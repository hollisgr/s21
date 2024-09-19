--session 1--
show transaction isolation level;

begin;

--session 2--
show transaction isolation level;

begin;

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
-- (after commit is session 1 UPDATE 1 in session 2)

--session 2--
commit;

--session 1--
select * from pizzeria
    where id = 1;

--session 2--
select * from pizzeria
    where id = 1;