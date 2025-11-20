# Write your MySQL query statement below
WITH
    counter AS (
        SELECT requester_id AS id, COUNT(accepter_id) AS num
        FROM RequestAccepted
        GROUP BY requester_id

        UNION ALL

        SELECT accepter_id AS id, COUNT(requester_id) AS num
        FROM RequestAccepted
        GROUP BY accepter_id
    ),
    getSum AS (
        SELECT id, SUM(num) AS num
        FROM counter
        GROUP BY id
    )

SELECT *
FROM getSum
WHERE num = (SELECT MAX(num) FROM getSum);

-- 1 2
-- 1 3
-- 2 3
-- 3 4
-- ----------
-- 1 2
-- 1 3

-- 2 1
-- 2 3

-- 3 1
-- 3 2
-- 3 4

-- 4 0


-- | 2  | 1   |
-- | 3  | 2   |
-- | 4  | 1   |


-- | 1  | 2   |
-- | 2  | 1   |
-- | 3  | 1   |