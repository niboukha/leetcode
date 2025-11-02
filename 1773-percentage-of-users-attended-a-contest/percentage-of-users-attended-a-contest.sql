-- Write your PostgreSQL query statement below

SELECT contest_id, ROUND((COUNT(user_id) * 100.0 / (SELECT COUNT(*) FROM Users)), 2) AS percentage
FROM Users
RIGHT JOIN Register USING(user_id)
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC