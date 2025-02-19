-- Select all columns from the employees table
SELECT * FROM employees;

-- Select the name and salary columns from the employees table
SELECT name, salary FROM employees;

-- count the no of employees in table
SELECT COUNT(*) FROM employees;

-- find the highest salary in the employee table
SELECT MAX(salary) FROM employees;

-- find the lowest salary in the employee table
SELECT MIN(salary) FROM employees;

-- find the average salary in the employee table
SELECT AVG(salary) FROM employees;

-- find the sum of all salaries in the employee table
SELECT SUM(salary) FROM employees;

-- sort the employees table by salary in ascending order
SELECT * FROM employees ORDER BY salary ASC;

-- sort the employees table by salary in descending order
SELECT * FROM employees ORDER BY salary DESC;

-- retrieve the first 5 rows from the employees table
SELECT * FROM employees LIMIT 5;

-- retrieve employees who joined after jan 1 , 2020
SELECT * FROM employees WHERE join_date > '2020-01-01';

-- retrieve employees who joined after jan 1 , 2020 and have a salary greater than 50000
SELECT * FROM employees WHERE join_date > '2020-01-01' AND salary > 50000;

-- group employees by department and count how many employees are in each department
SELECT department, COUNT(*) AS employee_count FROM employees GROUP BY department;

-- find second highest salary in the employee table
SELECT MAX(salary) FROM employees WHERE salary < (SELECT MAX(salary) FROM employees);

SELECT DISTINCT salary FROM employees ORDER BY salary DESC LIMIT 1 OFFSET 1;