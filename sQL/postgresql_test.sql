-- Create Users Table
CREATE TABLE users (
    user_id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL
);

-- Create Orders Table
CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    user_id INT REFERENCES users(user_id),
    order_date DATE NOT NULL
);

-- Create Products Table
CREATE TABLE products (
    product_id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    price DECIMAL(10,2) NOT NULL
);

-- Create Order Items Table
CREATE TABLE order_items (
    order_item_id SERIAL PRIMARY KEY,
    order_id INT REFERENCES orders(order_id),
    product_id INT REFERENCES products(product_id),
    quantity INT NOT NULL
);

-- Create Shipping Table
CREATE TABLE shipping (
    shipping_id SERIAL PRIMARY KEY,
    order_id INT REFERENCES orders(order_id),
    tracking_number VARCHAR(50),
    shipping_status VARCHAR(20) CHECK (shipping_status IN ('pending', 'shipped', 'delivered')),
    shipping_date DATE
);

-- Insert Sample Data
INSERT INTO users (name, email) VALUES
('Alice', 'alice@example.com'),
('Bob', 'bob@example.com');

INSERT INTO orders (user_id, order_date) VALUES
(1, '2024-02-20'),
(2, '2024-02-21');

INSERT INTO products (name, price) VALUES
('Laptop', 999.99),
('Phone', 499.99);

INSERT INTO order_items (order_id, product_id, quantity) VALUES
(1, 1, 1),
(2, 2, 2);

INSERT INTO shipping (order_id, tracking_number, shipping_status, shipping_date) VALUES
(1, 'TRK12345', 'shipped', '2024-02-21'),
(2, 'TRK12346', 'pending', '2024-02-22');

-- Queries to Retrieve Data
SELECT * FROM users;
SELECT * FROM orders;
SELECT * FROM products;
SELECT * FROM order_items;
SELECT * FROM shipping;

-- Retrieve orders with user details
SELECT o.order_id, u.name, o.order_date FROM orders o
JOIN users u ON o.user_id = u.user_id;

-- Retrieve order details with product names
SELECT oi.order_item_id, p.name AS product_name, oi.quantity FROM order_items oi
JOIN products p ON oi.product_id = p.product_id;

-- Get total order count per user
SELECT u.name, COUNT(o.order_id) AS total_orders FROM users u
LEFT JOIN orders o ON u.user_id = o.user_id
GROUP BY u.name;

-- Get total revenue per product
SELECT p.name, SUM(oi.quantity * p.price) AS total_revenue FROM order_items oi
JOIN products p ON oi.product_id = p.product_id
GROUP BY p.name;



-- Commonly Asked SQL Queries

-- 1. Retrieve all users
SELECT * FROM users;

-- 2. Get orders placed by a specific user
SELECT * FROM orders WHERE user_id = ?;

-- 3. Count total orders for each user
SELECT user_id, COUNT(*) AS total_orders FROM orders GROUP BY user_id;

-- 4. Find total revenue generated
SELECT SUM(total_amount) AS total_revenue FROM orders;

-- 5. List products ordered along with their quantity
SELECT p.product_name, oi.quantity FROM order_items oi
JOIN products p ON oi.product_id = p.product_id;

-- 6. Retrieve orders that have been shipped
SELECT * FROM orders o
JOIN shipping s ON o.order_id = s.order_id
WHERE s.shipping_status = 'Shipped';

-- 7. Find the most ordered product
SELECT p.product_name, SUM(oi.quantity) AS total_quantity
FROM order_items oi
JOIN products p ON oi.product_id = p.product_id
GROUP BY p.product_name
ORDER BY total_quantity DESC
LIMIT 1;

-- 8. Find users who haven’t placed an order
SELECT * FROM users
WHERE user_id NOT IN (SELECT DISTINCT user_id FROM orders);

-- 9. Retrieve all orders placed in the last 30 days
SELECT * FROM orders
WHERE order_date >= CURRENT_DATE - INTERVAL '30 days';

-- 10. Retrieve total sales per day for the last month
SELECT order_date, SUM(total_amount) AS daily_sales
FROM orders
WHERE order_date >= CURRENT_DATE - INTERVAL '30 days'
GROUP BY order_date
ORDER BY order_date;

-- 11. Get the latest order placed by each user
SELECT DISTINCT ON (user_id) user_id, order_id, order_date
FROM orders
ORDER BY user_id, order_date DESC;

-- 12. Find orders with at least 3 different products
SELECT order_id FROM order_items
GROUP BY order_id
HAVING COUNT(DISTINCT product_id) >= 3;

-- 13. Retrieve orders with their shipping status
SELECT o.order_id, o.user_id, s.shipping_status
FROM orders o
LEFT JOIN shipping s ON o.order_id = s.order_id;

-- 14. Find the average order value per user
SELECT user_id, AVG(total_amount) AS avg_order_value
FROM orders
GROUP BY user_id;

-- 15. Get products that were never ordered
SELECT * FROM products
WHERE product_id NOT IN (SELECT DISTINCT product_id FROM order_items);



