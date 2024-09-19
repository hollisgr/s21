select 
    p.name
    from person_order po
    join menu m on m.id = po.menu_id
    join person p on p.id = po.person_id
    where gender = 'female'
    and pizza_name = 'pepperoni pizza'
intersect
select 
    p.name
    from person_order po
    join menu m on m.id = po.menu_id
    join person p on p.id = po.person_id
    where gender = 'female'
    and pizza_name = 'cheese pizza'
    order by 1 asc;