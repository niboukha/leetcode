-- Write your PostgreSQL query statement below

SELECT
    DISTINCT(e1.reports_to) AS employee_id,
    (SELECT name FROM Employees WHERE employee_id = e1.reports_to),
    COUNT(e1.employee_id) AS reports_count,
    ROUND(SUM(e1.age) * 1.0 / COUNT(e1.age)) AS average_age
FROM Employees AS e1
JOIN Employees AS e2 USING(reports_to)
GROUP BY e2.employee_id, e1.reports_to


