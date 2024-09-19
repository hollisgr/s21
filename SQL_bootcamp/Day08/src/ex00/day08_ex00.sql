-- session 1--
begin transaction;

update pizzeria
    set rating = 5
    where id = 1;

commit;

--session 2---
select * from pizzeria
    where id = 1;