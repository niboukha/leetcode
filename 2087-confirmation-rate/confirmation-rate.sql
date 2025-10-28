-- Write your PostgreSQL query statement below

-- SELECT s.user_id,
--     ROUND(
--         COALESCE(
--             COUNT(action) FILTER (WHERE action = 'confirmed')::numeric / NULLIF(COUNT(action), 0), 0
--         ), 2
--     )
--     AS confirmation_rate
-- FROM Signups s
-- LEFT JOIN Confirmations conf USING(user_id)
-- GROUP BY user_id
-- ;


SELECT s.user_id,
    CASE
        WHEN COUNT(action) = 0 THEN 0
        ELSE ROUND(COUNT(action) FILTER (WHERE action = 'confirmed')::numeric / COUNT(action), 2)
    END
    AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations conf USING(user_id)
GROUP BY user_id
;