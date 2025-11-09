-- Write your PostgreSQL query statement below
WITH Upd AS (
    UPDATE Users
    SET name = UPPER(LEFT(name, 1)) || LOWER(SUBSTRING(name FROM 2))
    RETURNING *
)
SELECT *
FROM Upd
ORDER BY user_id;
