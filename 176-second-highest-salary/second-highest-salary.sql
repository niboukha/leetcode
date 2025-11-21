-- Write your PostgreSQL query statement below

WITH
    rank AS (
        SELECT *, DENSE_RANK() OVER (ORDER BY salary DESC NULLS LAST) AS rn
        FROM Employee
    )

SELECT
    coalesce(
        (
            SELECT DISTINCT salary
            FROM rank
            WHERE rn = 2
        ), NULL
    ) AS SecondHighestSalary
