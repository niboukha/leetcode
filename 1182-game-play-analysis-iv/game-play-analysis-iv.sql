-- Write your PostgreSQL query statement below

WITH Init_date AS (
    SELECT player_id, MIN(event_date) AS event_date
    FROM Activity
    GROUP BY player_id
)
SELECT ROUND(
        COUNT(Init_date.event_date) * 1.0 / COUNT(DISTINCT(Activity.player_id))
    , 2) AS fraction
FROM Activity
LEFT JOIN Init_date ON
    Activity.player_id =  Init_date.player_id
    AND
    Activity.event_date =  Init_date.event_date + 1

-- smallest date then check if date (day + 1) exist