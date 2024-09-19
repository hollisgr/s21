select
    p.name as name,
    pizza_name,
    price,
    round(m.price - (m.price/100*pd.discount)) as discount_price,
    pz.name as pizzeria_name
    from person_order po
    join menu m on m.id = po.menu_id
    join person p on p.id = po.person_id
    join person_discounts pd on pd.person_id = po.person_id
        and pd.pizzeria_id = m.pizzeria_id
    join pizzeria pz on pz.id = m.pizzeria_id
    order by 1, 2;