select
    pizza_name,
    pz.name as pizzeria_name
    from person_order po
    join person p on p.id = po.person_id
    join menu m on m.id = po.menu_id
    join pizzeria pz on m.pizzeria_id = pz.id
    where p.name in ('Denis', 'Anna')
    order by pizza_name, pizzeria_name;