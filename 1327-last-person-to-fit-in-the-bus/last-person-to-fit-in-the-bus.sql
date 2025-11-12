-- Write your PostgreSQL query statement below

WITH
    SumWeight AS (
        SELECT
            person_id, turn, person_name, weight,
            CASE 
                WHEN 
                    SUM(weight) OVER (ORDER BY turn) <= 1000 then SUM(weight) OVER (ORDER BY turn)
                ELSE NULL
            END
            AS TotalWeight
        FROM Queue
    )

SELECT person_name
FROM SumWeight
WHERE TotalWeight = (SELECT MAX(TotalWeight) FROM SumWeight)

