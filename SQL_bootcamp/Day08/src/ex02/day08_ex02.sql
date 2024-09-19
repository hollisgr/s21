--session 1--
begin transaction isolation level repeatable read;

--session 2--
begin transaction isolation level repeatable read;

--session 1--
select * from pizzeria
    where id = 1;

--session 2--
select * from pizzeria
    where id = 1;

--session 1--
update pizzeria 
    set rating = 4
    where id = 1;
-- (UPDATE 1 instant)


--session 2--
update pizzeria 
    set rating = 4
    where id = 1;

--session 1--
commit;
-- (after commit in session 1 ERROR: could not serialize access due to concurrent update in session 2)

--session 2--
commit;
-- (after commit in session 2 ROLLBACK)

--session 1--
select * from pizzeria
    where id = 1;

--session 2--
select * from pizzeria
    where id = 1;