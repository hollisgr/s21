create view v_persons_female AS
    select * from person
    where gender = 'female';

create view v_persons_male AS
    select * from person
    where gender = 'male';