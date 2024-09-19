create index
    idx_person_name
    on person (UPPER(name));

    SET enable_seqscan TO OFF;
explain analyze
    select
    name
    from person
    where upper(name) = 'ANNA';