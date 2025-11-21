-- Write your PostgreSQL query statement below

WITH
    Rank AS (
        SELECT *,
            DENSE_RANK() OVER (PARTITION BY departmentid ORDER BY salary DESC) AS rn
        FROM Employee
    ),
    topThree AS (
        SELECT *
        FROM Rank
        WHERE rn <= 3
    )

SELECT Department.name AS Department, topThree.name AS Employee, topThree.Salary
FROM topThree
LEFT JOIN Department ON topThree.departmentid = Department.id
