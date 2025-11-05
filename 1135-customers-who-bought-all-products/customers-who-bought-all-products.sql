-- Write your PostgreSQL query statement below

WITH FILTER_CUSTOMERS AS (
    SELECT customer_id, product_key
    FROM Customer
    GROUP BY customer_id, product_key
)
SELECT customer_id
FROM FILTER_CUSTOMERS
GROUP BY customer_id
HAVING (COUNT(customer_id) = (SELECT COUNT(*) FROM Product))