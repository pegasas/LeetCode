SELECT
        request_at AS Day,
        round(
        sum(
        CASE WHEN   -- 这里临时生成了一个字段，由status字段决定 若是完成字段值为0 反之为1  也就是是否被取消
status="completed" THEN 0
ELSE 1
END )       -- 对这个字段使用sum函数即可求得被取消了的个数
/count(*),  2)      -- 除以总个数后四舍五入2位即为被取消的概率
        AS "Cancellation Rate"
FROM
        Trips t INNER JOIN Users u ON t.Client_Id = u.Users_Id and u.Banned='No'    -- 限定为非ban用户
        WHERE request_at  BETWEEN "2013-10-01" AND "2013-10-03"    -- 限定日期
        GROUP BY request_at -- 对日期分组
        ORDER BY request_at;