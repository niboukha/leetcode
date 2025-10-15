-- Write your PostgreSQL query statement below

SELECT product_id FROM Products
WHERE (low_fats, recyclable) = ('Y', 'Y');

-- WHERE low_fats || recyclable = 'YY';
-- WHERE low_fats = 'Y' AND recyclable = 'Y';