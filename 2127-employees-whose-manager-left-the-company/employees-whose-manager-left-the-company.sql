-- Write your PostgreSQL query statement below

WITH 
    LessSalary AS (
        SELECT *
        FROM Employees
        WHERE
            salary < 30000
            AND
            manager_id NOT IN (
                SELECT employee_id
                FROM Employees
            )
    )

SELECT employee_id
FROM LessSalary
ORDER BY employee_id
