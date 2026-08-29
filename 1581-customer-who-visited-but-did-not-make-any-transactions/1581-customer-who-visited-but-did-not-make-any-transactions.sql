# Write your MySQL query statement bel
SELECT v.customer_id, COUNT(V.customer_id) as count_no_trans
FROM Visits AS v LEFT JOIN Transactions AS t ON v.visit_id=t.visit_id WHERE t.transaction_id is NULL group by v.customer_id