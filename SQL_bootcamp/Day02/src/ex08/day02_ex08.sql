select 
    p.name
    from person_order po
    join menu m on m.id = po.menu_id
    join person p on p.id = po.person_id
    where pizza_name in ('pepperoni pizza', 'mushroom pizza')
    and address in ('Moscow', 'Samara')
    and gender = 'male'
    order by 1 desc;