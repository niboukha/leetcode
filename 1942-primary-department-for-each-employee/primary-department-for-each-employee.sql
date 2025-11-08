-- Write your PostgreSQL query statement below

SELECT Employee.employee_id, Employee.department_id
FROM Employee
WHERE
    primary_flag = 'Y'
    or
    Employee.employee_id IN (
        SELECT employee_id
        FROM Employee
        GROUP BY employee_id
        HAVING COUNT(employee_id) = 1
    )
