select
    person.name 
        as person_name,
    pizzeria.name 
        as pizzeria_name
    from person, person_visits, pizzeria
    where pizzeria.id = person_visits.pizzeria_id 
        and person.id = person_visits.person_id
        and person_visits.visit_date between '2022-01-07' and '2022-01-09'
    order by person_name asc, pizzeria_name desc;    
