-- Write your PostgreSQL query statement below

SELECT query_name,
    ROUND(SUM(rating * 1.0 / position) / COUNT(query_name), 2) AS quality,
    ROUND(COUNT(rating) FILTER (WHERE rating < 3) * 100.0 / COUNT(query_name), 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name


