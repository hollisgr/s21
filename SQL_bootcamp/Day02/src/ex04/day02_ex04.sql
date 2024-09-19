select pizza_name,
    pz.name as pizzeria_name,
    price
    from menu m
    join pizzeria pz on m.pizzeria_id = pz.id
    where pizza_name in ('mushroom pizza', 'pepperoni pizza')
    order by pizza_name, pizzeria_name;
