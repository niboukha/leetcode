-- Write your PostgreSQL query statement below


SELECT Products.product_name, SUM(Orders.unit) AS unit
FROM Products
LEFT JOIN Orders USING(product_id)
WHERE TO_CHAR(order_date, 'YYYY-MM') = '2020-02'
GROUP BY product_name
HAVING SUM(Orders.unit) >= 100


