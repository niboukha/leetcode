-- Write your PostgreSQL query statement below

SELECT DISTINCT author_id as id
FROM Views
WHERE viewer_id = author_id
ORDER BY id ASC;