-- Write your PostgreSQL query statement below

WITH Cte AS (
    SELECT *,
        COALESCE(LEAD(student) OVER (ORDER BY id), student) as lead,
        LAG(student) OVER (ORDER BY id)
    FROM Seat
)
SELECT id, (
    CASE
        WHEN MOD(id, 2) = 1 THEN lead
        ELSE lag
    END
) AS student
FROM Cte


-- SELECT id, lead as student
-- FROM Cte
-- WHERE MOD(id, 2) = 1

-- UNION

-- SELECT id, lag as student
-- FROM Cte
-- WHERE MOD(id, 2) = 0


-- +----+---------+
-- | id | student |
-- +----+---------+
-- | 1  | Abbot   | Doris
-- | 2  | Doris   | Abbot
-- | 3  | Emerson | Green
-- | 4  | Green   | Emerson
-- | 5  | Jeames  |
-- +----+---------+