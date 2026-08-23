# Write your MySQL query statement below
SELECT D.unique_id,E.name FROM Employees as E LEFT JOIN EmployeeUNI as D ON E.id=D.id;