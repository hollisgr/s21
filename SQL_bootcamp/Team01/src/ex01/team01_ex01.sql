-- INSERT INTO currency VALUES (100, 'EUR', 0.85, '2022-01-01 13:29');
-- INSERT INTO currency VALUES (100, 'EUR', 0.79, '2022-01-08 13:29');

SELECT 
    temp.name,
    temp.lastname,
    currency_name,
    money * rate_to_usd AS currency_in_usd
FROM 
    (SELECT 
        coalesce(u.name,'not defined') AS name,
        coalesce(u.lastname,'not defined') AS lastname,
        c.name AS currency_name,
        money,
        coalesce((SELECT rate_to_usd 
                FROM currency c 
                WHERE b.currency_id = c.id 
                    AND c.updated < b.updated 
                ORDER BY  c.updated DESC 
                LIMIT 1),
        (SELECT rate_to_usd 
        FROM currency c 
        WHERE b.currency_id = c.id 
            AND c.updated > b.updated 
        ORDER BY  c.updated ASC 
        LIMIT 1)) AS rate_to_usd
    FROM balance b 
    JOIN (SELECT 
            c.id, 
            c.name 
        FROM currency c 
        GROUP BY c.id, c.name) AS c 
            ON c.id = b.currency_id
    LEFT JOIN "user" u 
        ON u.id = b.user_id) AS temp
ORDER BY 1 DESC, 2, 3;