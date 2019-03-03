select Max(Salary) SecondHIghestSalary
from Employee
where (
    select Max(Salary)
    from Employee
) > Salary
