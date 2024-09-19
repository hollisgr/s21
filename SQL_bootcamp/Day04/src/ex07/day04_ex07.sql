insert into person_visits
    values (
        (select max(id) from person_visits) + 1,
        (select id from person where name = 'Dmitriy'),
        (select pz.id from pizzeria pz
            join menu m on m.pizzeria_id = pz.id
            where price < 800 and pz.name != 'Papa Johns'
            order by 1
            limit 1),
        '2022-01-08'
    );

refresh materialized view 
    mv_dmitriy_visits_and_eats;