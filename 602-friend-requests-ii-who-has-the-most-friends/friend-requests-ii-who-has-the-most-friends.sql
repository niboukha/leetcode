# Write your MySQL query statement below
WITH
    counter AS (
        SELECT requester_id AS id
        FROM RequestAccepted

        UNION ALL

        SELECT accepter_id AS id
        FROM RequestAccepted
    )

SELECT id, COUNT(id) as num
FROM counter
GROUP BY id
ORDER BY num DESC
LIMIT 1

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