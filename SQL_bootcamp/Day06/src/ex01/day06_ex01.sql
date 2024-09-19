insert into person_discounts
    select
    row_number() over() as id,
    person_id,
    m.pizzeria_id,
    case
        when count(*) = 1 then 10.5
        when count(*) = 2 then 22
        else 30
    end as discount
    from person_order po
    join menu m on m.id = po.menu_id
    group by 2, 3;