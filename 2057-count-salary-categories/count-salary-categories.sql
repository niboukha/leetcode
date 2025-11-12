-- Write your PostgreSQL query statement below

WITH
    FilterCategories AS (
        SELECT *,
            CASE 
                WHEN income < 20000 THEN 'Low Salary'
                WHEN income > 50000 THEN 'High Salary'
                ELSE 'Average Salary'
            END AS category
        FROM Accounts
    ),
    cat AS (
        SELECT category, 0 AS accounts_count
        FROM (
        VALUES
            ('Low Salary'),
            ('Average Salary'),
            ('High Salary')
        ) AS cats(category)
    )

SELECT category, COUNT(account_id) AS accounts_count
FROM FilterCategories
RIGHT JOIN cat USING(category)
GROUP BY category

