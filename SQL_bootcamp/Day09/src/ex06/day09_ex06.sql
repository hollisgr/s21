CREATE FUNCTION fnc_person_visits_and_eats_on_date(
    pperson varchar default 'Dmitriy',
    pprice numeric default 500,
    pdate date default '2022-01-08')
RETURNS TABLE(name varchar) AS $$
begin
return query
SELECT pz.name as pizzeria_name
    from menu m
    join pizzeria pz on pz.id = m.pizzeria_id
    join person_visits pv on m.pizzeria_id = pv.pizzeria_id
    join person p on p.id = pv.person_id
    where price  < pprice 
    and p.name = pperson 
    and visit_date = pdate;
END;
$$ LANGUAGE PLPGSQL;