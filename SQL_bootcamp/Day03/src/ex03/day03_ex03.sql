(select 
    pz.name as pizzeria_name
    from pizzeria pz
    join person_visits pv on pv.pizzeria_id = pz.id
    join person p on p.id = pv.person_id
    where gender = 'female'
except all
select 
    pz.name as pizzeria_name
    from pizzeria pz
    join person_visits pv on pv.pizzeria_id = pz.id
    join person p on p.id = pv.person_id
    where gender = 'male')
union all
(select
    pz.name as pizzeria_name
    from pizzeria pz
    join person_visits pv on pv.pizzeria_id = pz.id
    join person p on p.id = pv.person_id
    where gender = 'male'
except all
select 
    pz.name as pizzeria_name
    from pizzeria pz
    join person_visits pv on pv.pizzeria_id = pz.id
    join person p on p.id = pv.person_id
    where gender = 'female')
    order by 1;