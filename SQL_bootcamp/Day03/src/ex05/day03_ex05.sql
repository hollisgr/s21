select 
    pz.name as pizzeria_name
    from person_visits pv
    join person p on pv.person_id = p.id
    join pizzeria pz on pv.pizzeria_id = pz.id
    where p.name = 'Andrey'
except
select
    pz.name as pizzeria_name
    from person_order po
    join menu m on m.id = po.menu_id
    join person p on p.id = po.person_id
    join pizzeria pz on pz.id = m.pizzeria_id
    where p.name = 'Andrey'
    order by 1;