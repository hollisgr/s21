select 
    temp1.name,
    coalesce(temp1.count, 0) 
        + coalesce(temp2.count, 0) as total_count
    from 
        (select
            pz.name,
            count(*) as count
            from person_visits pv
            join pizzeria pz on pz.id = pv.pizzeria_id
            group by pz.name) as temp1
    full join
        (select
            pz.name,
            count(*) as count
            from person_order po
            join menu m on m.id = po.menu_id
            join pizzeria pz on pz.id = m.pizzeria_id
            group by pz.name) as temp2 on temp2.name = temp1.name
    order by 2 desc, 1;