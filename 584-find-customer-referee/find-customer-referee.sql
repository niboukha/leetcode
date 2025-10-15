-- Write your PostgreSQL query statement below

SELECT name FROM Customer
WHERE referee_id IS DISTINCT FROM 2 ;


-- WHERE referee_id != 2 or referee_id is null;