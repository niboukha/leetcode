-- Write your PostgreSQL query statement below

WITH Earliest AS (
    SELECT customer_id, MIN(order_date) as order_date
    FROM Delivery
    GROUP BY customer_id
)

SELECT ROUND(
        SUM(
            CASE
                WHEN Earliest.order_date = customer_pref_delivery_date THEN 1
                ELSE 0
            END
        ) * 100.0 / COUNT(Earliest.customer_id)
    , 2) AS immediate_percentage
FROM Delivery 
LEFT JOIN Earliest ON Earliest.customer_id = Delivery.customer_id
    AND Earliest.order_date = Delivery.order_date
