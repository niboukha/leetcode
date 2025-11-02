-- Write your PostgreSQL query statement below

SELECT project_id, ROUND(avg(experience_years)::numeric , 2) AS average_years
FROM Project
LEFT JOIN Employee USING(employee_id)
GROUP BY project_id

