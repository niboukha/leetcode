-- Write your PostgreSQL query statement below

WITH 
    LessSalary AS (
        SELECT *
        FROM Employees
        WHERE salary < 30000 AND manager_id IS NOT NULL
    ),
    LeaveCompany AS (
        SELECT *
        FROM LessSalary
        WHERE
            NOT EXISTS (
                SELECT 1
                FROM Employees
                WHERE Employees.employee_id = LessSalary.manager_id
            )
    )


SELECT employee_id
FROM LeaveCompany
ORDER BY employee_id
