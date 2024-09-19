select
    address,
    round(max(age)-(min(age)/max(age)::numeric), 2) as formula,
    round(avg(age),2) as average,
    case 
        when round(max(age)-(min(age)/max(age)::numeric), 2) 
        > round(avg(age),2) then 'true'
        else 'false'
        end as comparison
    from person
    group by 1
    order by 1;
