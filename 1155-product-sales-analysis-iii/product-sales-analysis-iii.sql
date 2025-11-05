-- Write your PostgreSQL query statement below

WITH Earliest AS (
    SELECT product_id, min(year) AS first_year
    FROM Sales
    GROUP BY product_id
)
SELECT Earliest.product_id, Earliest.first_year, Sales.quantity, Sales.price
FROM Sales
RIGHT JOIN Earliest ON Earliest.product_id = Sales.product_id AND Earliest.first_year = Sales.year

