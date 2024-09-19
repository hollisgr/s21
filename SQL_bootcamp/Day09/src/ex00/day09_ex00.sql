create table person_audit
( 
    created timestamp with time zone not null 
        default current_timestamp,
    type_event char(1) not null default 'I',
    row_id bigint not null,
    name varchar not null,
    age integer not null default 10,
    gender varchar default 'female' not null ,
    address varchar,
    constraint ch_type_event check (type_event in ('I', 'U', 'D'))
);

create or replace function fnc_trg_person_insert_audit()
returns trigger 
language PLPGSQL as
$$
begin
insert into person_audit
values (current_timestamp, 
        'I', 
        new.id, 
        new.name, 
        new.age, 
        new.gender,
        new.address);
return null;
end;
$$;

create trigger trg_person_insert_audit
after insert on person for each row
execute function fnc_trg_person_insert_audit();