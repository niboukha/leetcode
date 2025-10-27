# Write your MySQL query statement below


SELECT e1.name
FROM Employee e1
JOIN Employee e2 ON e1.id = e2.managerID
WHERE e2.managerId = e1.id
GROUP BY e1.id
HAVING COUNT(e2.managerId) >= 5;
;

