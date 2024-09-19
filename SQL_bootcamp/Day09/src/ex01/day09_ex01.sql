create or replace function fnc_trg_person_update_audit()
returns trigger 
language PLPGSQL as
$$
begin
insert into person_audit
values (current_timestamp, 
        'U', 
        old.id, 
        old.name, 
        old.age, 
        old.gender,
        old.address);
return null;
end;
$$;

create trigger trg_person_update_audit
after update on person for each row
execute function fnc_trg_person_update_audit();