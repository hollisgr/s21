select 
    pz.name,
    count(*) as count_of_orders,
    round(avg(price), 2) as average_price,
    max(price) as max_price,
    min(price) as min_price
    from person_order po
    join menu m on m.id = po.menu_id
    join pizzeria pz on pz.id = m.pizzeria_id
    group by pz.name
    order by 1;
    