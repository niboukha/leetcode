-- Write your PostgreSQL query statement below

SELECT name, bonus
FROM Employee
LEFT JOIN Bonus USING(empId)
WHERE bonus is null OR bonus < 1000;
