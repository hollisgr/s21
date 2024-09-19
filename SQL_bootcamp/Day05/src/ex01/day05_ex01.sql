SET enable_seqscan TO OFF;
explain analyze
    select
    pizza_name,
    pz.name as pizzeria_name
    from menu m
    join pizzeria pz on pz.id = m.pizzeria_id
    order by 1, 2 desc;