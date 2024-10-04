# Write your MySQL query statement below

select Employees.name as name , EmployeeUNI.unique_id as unique_id 
from Employees  
left join EmployeeUNI 
on Employees.id = EmployeeUNI.id