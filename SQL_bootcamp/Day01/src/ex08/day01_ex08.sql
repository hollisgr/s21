select
    order_date,
    concat(name, ' (age:', person.age, ')') as person_information
    from person_order
    natural join 
    (select 
        person.id as person_id, 
        person.name, 
        person.age
        from person) person
    order by order_date asc, person_information asc;