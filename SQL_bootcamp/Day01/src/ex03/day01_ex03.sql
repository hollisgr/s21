select
    person_visits.visit_date as action_date,
    person_visits.person_id
from person_visits, person_order
intersect select
    person_visits.visit_date as action_date,
    person_order.person_id
from person_order, person_visits
where person_visits.visit_date = person_order.order_date 
order by action_date asc, person_id desc;