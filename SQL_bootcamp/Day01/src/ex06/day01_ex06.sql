select
    person_visits.visit_date as action_date,
    person.name as person_name
from person_visits, person_order, person
intersect select
    person_visits.visit_date as action_date,
    person.name as person_name
from person_order, person_visits, person
where person_visits.visit_date = person_order.order_date
and person_order.person_id = person.id
order by action_date asc, person_name desc;