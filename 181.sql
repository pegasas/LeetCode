
SELECT Worker.Name AS Employee
FROM Employee AS Worker, Employee AS Manager
WHERE Worker.ManagerId = Manager.Id AND Worker.Salary > Manager.Salary