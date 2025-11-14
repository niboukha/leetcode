-- Write your PostgreSQL query statement below

WITH 
    user_counts AS (
        SELECT user_id, COUNT(user_id)
        FROM MovieRating
        GROUP BY user_id
    ),
    rankU AS (
        SELECT c.user_id, u.name,
            RANK() OVER (ORDER BY c.count DESC, u.name ASC)
        FROM user_counts c
        LEFT JOIN Users u USING(user_id)
    ),
    avg_movies AS (
        SELECT movie_id, AVG(rating)
        FROM MovieRating
        WHERE to_char(created_at, 'YYYY-MM') = '2020-02'
        GROUP BY movie_id
    ),
    rankM AS (
        SELECT A.movie_id, M.title,
            RANK() OVER (ORDER BY A.avg DESC, M.title ASC)
        FROM avg_movies A
        LEFT JOIN Movies M USING(movie_id)
    )


SELECT U.name AS results
FROM rankU U
WHERE U.rank = 1

UNION ALL

SELECT M.title AS results
FROM rankM M
WHERE M.rank = 1