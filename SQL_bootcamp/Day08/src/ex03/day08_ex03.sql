--session 1--
begin transaction isolation level read commited;

--session 2--
begin transaction isolation level read commited;

--session 1--
select * from pizzeria
    where id = 1;

--session 2--
update pizzeria 
    set rating = 4
    where id = 1;

--session 2--
commit;
-- (UPDATE 1)

--session 1--
select * from pizzeria
    where id = 1;

--session 1--
commit;
-- (COMMIT)

--session 1--
select * from pizzeria
    where id = 1;

--session 2--
select * from pizzeria
    where id = 1;