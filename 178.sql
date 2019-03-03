SELECT Score, (
  SELECT COUNT(*)
  FROM (
    SELECT DISTINCT SCORE S
    FROM Scores
  ) AS tmp
  WHERE S >= Score
) AS Rank
FROM Scores
ORDER BY Score DESC