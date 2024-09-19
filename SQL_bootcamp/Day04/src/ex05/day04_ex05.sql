create view v_price_with_discount as
select
    p.name as name,
    pizza_name,
    price,
    round (price - price * 0.1) as discount_price
    from person_order po
    join person p on p.id = po.person_id
    join menu m on m.id = po.menu_id
    order by 1, 2;