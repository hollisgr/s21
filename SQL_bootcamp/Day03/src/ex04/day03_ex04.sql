(select 
    pz.name as pizzeria_name
    from person_order po
    join person p on p.id = po.person_id
    join menu m on m.id = po.menu_id
    join pizzeria pz on pz.id = m.pizzeria_id
    where gender = 'female'
except
select
    pz.name as pizzeria_name
    from person_order po
    join person p on p.id = po.person_id
    join menu m on m.id = po.menu_id
    join pizzeria pz on pz.id = m.pizzeria_id
    where gender = 'male')
union
(select 
    pz.name as pizzeria_name
    from person_order po
    join person p on p.id = po.person_id
    join menu m on m.id = po.menu_id
    join pizzeria pz on pz.id = m.pizzeria_id
    where gender = 'male'
except
select
    pz.name as pizzeria_name
    from person_order po
    join person p on p.id = po.person_id
    join menu m on m.id = po.menu_id
    join pizzeria pz on pz.id = m.pizzeria_id
    where gender = 'female')
    order by 1;