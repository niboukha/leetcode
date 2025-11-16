-- Write your PostgreSQL query statement below

WITH
    group_dates AS (
        SELECT visited_on, SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
        ORDER BY visited_on
    ),
    sum_amounts AS (
        SELECT
            visited_on,
            SUM(amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount
        FROM group_dates

    ),
    avg_amounts AS (
        SELECT *, ROUND(amount / 7, 2) AS average_amount
        FROM sum_amounts
        ORDER BY visited_on DESC
    ),
    ranked AS (
        SELECT *, ROW_NUMBER() OVER (ORDER BY visited_on DESC) AS rn
        FROM avg_amounts
    ),
    count_row AS (
        SELECT COUNT(*) - 6 AS cutoff
        FROM ranked
    )
    

SELECT ranked.visited_on, ranked.amount, ranked.average_amount
FROM ranked
CROSS JOIN count_row
WHERE rn <= count_row.cutoff
ORDER BY ranked.visited_on ASC
