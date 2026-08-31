# Write your MySQL query statement below
# -------------------- Problem: Average Processing Time (LeetCode 1661) --------------------
# Task: Calculate the average processing time for each machine.
# Table: Activity(machine_id INT, process_id INT, activity_type ENUM('start','end'), timestamp FLOAT)
# Each process has a start and end timestamp.

# -------------------- Algorithm Explanation --------------------
# 1. Self-join Activity table (a1 = start, a2 = end).
# 2. Match rows where machine_id and process_id are the same.
# 3. Ensure a1.timestamp < a2.timestamp (start before end).
# 4. Compute difference (a2.timestamp - a1.timestamp).
# 5. Take average per machine_id.
# 6. Round result to 3 decimal places.

# -------------------- Query --------------------
/*
SELECT a1.machine_id, 
       ROUND(AVG(a2.timestamp - a1.timestamp), 3) AS processing_time
FROM Activity AS a1
inner JOIN Activity AS a2
  ON a1.process_id = a2.process_id 
 AND a1.machine_id = a2.machine_id 
 AND a1.timestamp < a2.timestamp 
GROUP BY a1.machine_id;
*/
# -------------------- Corrected Query --------------------
SELECT a1.machine_id, 
       ROUND(AVG(a2.timestamp - a1.timestamp), 3) AS processing_time
FROM Activity AS a1
JOIN Activity AS a2
  ON a1.machine_id = a2.machine_id 
 AND a1.process_id = a2.process_id 
 AND a1.activity_type = 'start'
 AND a2.activity_type = 'end'
GROUP BY a1.machine_id;


# -------------------- Dry Run Example --------------------
# Activity table:
# machine_id | process_id | activity_type | timestamp
#     1      |     1      |     start     |   0.0
#     1      |     1      |     end       |   2.0
#     1      |     2      |     start     |   3.0
#     1      |     2      |     end       |   5.0
#
# Self-join pairs:
# (start=0.0, end=2.0) → duration = 2.0
# (start=3.0, end=5.0) → duration = 2.0
#
# AVG = (2.0 + 2.0)/2 = 2.0
# Output: machine_id=1, processing_time=2.000

# -------------------- Complexity --------------------
# Time Complexity: O(N^2) worst case (self-join compares rows),
# but effectively O(N) since each process has exactly one start and one end.
# Space Complexity: O(N) for join result set.

# -------------------- Key Notes --------------------
# - Use self-join to pair start and end of same process.
# - Condition a1.timestamp < a2.timestamp ensures correct ordering.
# - AVG() computes mean processing time per machine.
# - ROUND(...,3) formats to 3 decimal places.
# - Pattern: Self-join for pairing related events (start/end).
