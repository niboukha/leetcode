-- Write your PostgreSQL query statement below


WITH FilterInfo AS (
    SELECT tiv_2016, 
        COUNT(*) OVER (PARTITION BY tiv_2015) AS tiv_2015,
        COUNT(*) OVER (PARTITION BY lat, lon) AS pairs
    FROM Insurance
)

SELECT ROUND(SUM(FilterInfo.tiv_2016)::NUMERIC, 2) AS tiv_2016
FROM FilterInfo
WHERE tiv_2015 > 1 AND pairs = 1






-- tiv_2016:
--     - tiv_2015 shouldn't be unique
--     - (lat, lon) must be unique
