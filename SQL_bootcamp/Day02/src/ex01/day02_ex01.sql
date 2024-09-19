select 
    missing_date::date
    from generate_series('2022-01-01'::date, 
    '2022-01-10', interval '1 day') as missing_date
left join (select * from person_visits pv
    where person_id = 1 
    or person_id = 2) pv on pv.visit_date = missing_date
where pv.visit_date is NULL;