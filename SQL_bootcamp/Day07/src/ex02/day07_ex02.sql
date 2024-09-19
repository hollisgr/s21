(select
    pz.name as name,
    count(*) as count,
    'visit' as action_type
    from person_visits pv
    join pizzeria pz on pz.id = pv.pizzeria_id
    group by pz.name
    order by 2 desc
    limit 3)
union 
    (select
    pz.name as name,
    count(*) as count,
    'order' as action_type
    from person_order po
    join menu m on m.id = po.menu_id
    join pizzeria pz on pz.id = m.pizzeria_id
    group by pz.name
    order by 2 desc
    limit 3)
    order by 3, 2 desc
