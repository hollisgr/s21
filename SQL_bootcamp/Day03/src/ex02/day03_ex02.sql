select 
    pizza_name,
    price,
    pz.name as pizzeria_name
    from (
        select id as menu_id
        from menu
        except
        select menu_id
        from person_order
    ) as temp
join menu m on m.id = temp.menu_id
join pizzeria pz on pz.id = m.pizzeria_id
order by 1, 2;