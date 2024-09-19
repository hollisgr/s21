insert into person_order
select 
    gs + (select max(id) from person_order),
    id,
    (select id from menu where pizza_name = 'greek pizza'),
    '2022-02-25'
    from person
    join generate_series(1, (select count(*) from person)) 
        as gs on gs = person.id
