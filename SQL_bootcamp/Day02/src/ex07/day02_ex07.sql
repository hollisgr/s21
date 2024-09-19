select
    pz.name as pizzeria_name
    from person_visits pv
    join person p on pv.person_id = p.id
    join menu m on pv.pizzeria_id = m.pizzeria_id
    join pizzeria pz on m.pizzeria_id = pz.id
    where p.name = 'Dmitriy'
        and visit_date = '2022-01-08'
        and price < 800;
