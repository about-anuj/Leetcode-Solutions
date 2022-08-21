# Write your MySQL query statement be
#self join
# SELECT column_name(s)
# FROM table1 T1, table1 T2
# WHERE condition;
# SELECT e1.name as Employee from Employee e1, Employee e2
# where e1.managerid = e2.id AND e1.salary > e2.salary;
select e1.name as Employee
from Employee e1, Employee e2
where e1.managerId=e2.id and e1.salary>e2.salary;