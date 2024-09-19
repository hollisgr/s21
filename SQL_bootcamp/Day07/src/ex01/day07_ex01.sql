select
    name,
    count(*) as count_of_visits
    from person_visits pv
    join person p on p.id = pv.person_id
    group by name
    order by 2 desc, 1 
    limit 4;