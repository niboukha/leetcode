-- Write your PostgreSQL query statement below

WITH
    Cte AS (
        SELECT
            id, num,
            LEAD(num) OVER (ORDER BY id) as num1,
            LEAD(num, 2) OVER (ORDER BY id) as num2
        FROM Logs
    )
SELECT DISTINCT num AS ConsecutiveNums
FROM Cte
WHERE num = num1 AND num1 = num2



-- | id | num |
-- | -- | --- |
-- | 1  | 1   | 1 | 1
-- | 2  | 1   | 1 | 2
-- | 3  | 1   | 2 | 1
-- | 4  | 2   | 1 | 2
-- | 5  | 1   | 2 | null
-- | 6  | 2   | null | null