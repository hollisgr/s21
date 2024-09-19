with temp as (
    select temp::date
    from generate_series('2022-01-01'::date, 
    '2022-01-10', interval '1 day') as temp)
    select temp::date as missing_date
    from (select * from person_visits pv
    where person_id = 1 or person_id = 2) as pv
right join temp on pv.visit_date = temp
    where pv.id is NULL
    order by missing_date;