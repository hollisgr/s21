create index
    idx_person_order_multi
    on person_order (person_id, menu_id, order_date);

    SET enable_seqscan TO OFF;
explain analyze
    select
    person_id,
    menu_id,
    order_date
    from person_order
    where person_id = 8
    and menu_id = 19;