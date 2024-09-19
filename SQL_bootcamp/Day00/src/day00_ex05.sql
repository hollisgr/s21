select name 
    from person, person_order
    where person.id = person_order.person_id
        and (person_order.menu_id = '13'
        or person_order.menu_id = '14'
        or person_order.menu_id = '18')
        and person_order.order_date = '2022-01-07'
    group by person.name;