select
    pizza_name,
    price,
    pz.name as pizzeria_name,
    visit_date
    from menu m
    join pizzeria pz on pz.id = m.pizzeria_id
    join person_visits pv on pv.pizzeria_id = pz.id
    join person p on p.id = pv.person_id
    where price between 800 and 1000 and p.name = 'Kate'
    order by 1, 2, 3;