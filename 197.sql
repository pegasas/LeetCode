# Write your MySQL query statement below
SELECT w1.Id FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature AND SUBDATE(w1.RecordDate, 1) = w2.RecordDate;