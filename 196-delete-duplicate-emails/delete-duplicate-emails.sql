-- Write your PostgreSQL query statement below

DELETE FROM Person
WHERE
    id NOT IN (
        SELECT MIN(id) as id
        FROM Person
        GROUP BY email
    )