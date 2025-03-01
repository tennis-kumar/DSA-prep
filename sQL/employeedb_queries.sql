-- Medium Level SQL Queries for Employee Database

-- 1. Find employees who have been in the company for more than 5 years
SELECT employee_id, name, hire_date
FROM employees
WHERE hire_date <= CURRENT_DATE - INTERVAL '5 years';

-- 2. Retrieve the top 3 highest-paid employees in each department
SELECT department_id, employee_id, name, salary
FROM (
    SELECT department_id, employee_id, name, salary,
           RANK() OVER (PARTITION BY department_id ORDER BY salary DESC) AS rank
    FROM employees
) ranked_employees
WHERE rank <= 3;

-- 3. Find the total salary expense for each department
SELECT department_id, SUM(salary) AS total_salary
FROM employees
GROUP BY department_id
ORDER BY total_salary DESC;

-- 4. Identify employees who do not have a manager
SELECT employee_id, name
FROM employees
WHERE manager_id IS NULL;

-- 5. Retrieve details of employees along with their manager's name
SELECT e.employee_id, e.name AS employee_name, m.name AS manager_name
FROM employees e
LEFT JOIN employees m ON e.manager_id = m.employee_id;

-- 6. Find employees who earn more than their manager
SELECT e.employee_id, e.name AS employee_name, e.salary AS employee_salary, m.salary AS manager_salary
FROM employees e
JOIN employees m ON e.manager_id = m.employee_id
WHERE e.salary > m.salary;

-- 7. Retrieve the average salary for each job title
SELECT job_title, AVG(salary) AS avg_salary
FROM employees
GROUP BY job_title
ORDER BY avg_salary DESC;

-- 8. Find the most recent hire in each department
SELECT DISTINCT ON (department_id) department_id, employee_id, name, hire_date
FROM employees
ORDER BY department_id, hire_date DESC;

-- 9. List employees who work in departments with fewer than 5 employees
SELECT e.employee_id, e.name, e.department_id
FROM employees e
JOIN (
    SELECT department_id, COUNT(*) AS dept_count
    FROM employees
    GROUP BY department_id
    HAVING COUNT(*) < 5
) d ON e.department_id = d.department_id;

-- 10. Calculate the percentage of employees in each department
SELECT department_id, (COUNT(*) * 100.0 / SUM(COUNT(*)) OVER()) AS department_percentage
FROM employees
GROUP BY department_id;
