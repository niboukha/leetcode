-- Write your PostgreSQL query statement below


WITH
    UniqueLonLat AS (
        SELECT lat, lon
        FROM Insurance
        GROUP BY lat, lon
        HAVING COUNT(lat) = 1 OR COUNT(lon) = 1
    ),
    UniqueTiv2015 AS (
        SELECT tiv_2015
        FROM Insurance
        GROUP BY tiv_2015
        HAVING COUNT(tiv_2015) > 1
    ),
    JoinUniqueTiv AS (
        SELECT *
        FROM Insurance
        RIGHT JOIN UniqueTiv2015 USING(tiv_2015)
    )

SELECT ROUND(SUM(JoinUniqueTiv.tiv_2016)::NUMERIC, 2) AS tiv_2016
FROM JoinUniqueTiv
RIGHT JOIN UniqueLonLat ON
    UniqueLonLat.lat = JoinUniqueTiv.lat AND UniqueLonLat.lon = JoinUniqueTiv.lon






-- tiv_2016:
--     - tiv_2015 shouldn't be unique
--     - (lat, lon) must be unique
