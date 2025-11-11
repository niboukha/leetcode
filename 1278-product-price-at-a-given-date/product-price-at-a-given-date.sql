-- Write your PostgreSQL query statement below

WITH
    Filter_dates AS (
        SELECT *
        FROM Products
        WHERE change_date <= DATE '2019-08-16'
    ),
    Max_dates AS (
        SELECT product_id, MAX(change_date) AS change_date
        FROM Filter_dates
        GROUP BY product_id
    ),
    Updated_price AS (
        UPDATE Products
        SET new_price = 10
        WHERE change_date > DATE '2019-08-16'
        RETURNING *
    ), 
    Union_tables as (
        SELECT DISTINCT P.product_id, P.new_price AS price, P.change_date
        FROM Products P
        RIGHT JOIN Max_dates M ON
            P.product_id = M.product_id
            AND
            P.change_date = M.change_date

        UNION ALL

        SELECT product_id, new_price AS price, change_date
        FROM Updated_price
    )


SELECT DISTINCT ON (product_id) product_id, price
FROM Union_tables
ORDER BY product_id, change_date ASC
