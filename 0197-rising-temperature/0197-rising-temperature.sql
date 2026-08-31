# -------------------- Problem: Rising Temperature (LeetCode 197) --------------------
# Task: Find all IDs of days where the temperature is higher than the previous day.
# Table: Weather(id INT, recordDate DATE, temperature INT)
# Each row = one day’s weather record.

# -------------------- Algorithm Explanation --------------------
# 1. Self-join the Weather table (w = today, p = yesterday).
# 2. Use DATEDIFF(w.recordDate, p.recordDate) = 1 to ensure consecutive days.
# 3. Compare temperatures: w.temperature > p.temperature.
# 4. Select w.id (today’s ID) when condition holds.

# -------------------- Query --------------------
# Write your MySQL query statement below
SELECT w.id
FROM Weather AS w 
JOIN Weather AS p 
  ON DATEDIFF(w.recordDate, p.recordDate) = 1
WHERE w.temperature > p.temperature;

# -------------------- Dry Run Example --------------------
# Weather table:
# id | recordDate | temperature
# 1  | 2020-01-01 | 10
# 2  | 2020-01-02 | 25
# 3  | 2020-01-03 | 20
#
# Self-join pairs:
# (w=2020-01-02, p=2020-01-01) → DATEDIFF=1, 25 > 10 → select id=2
# (w=2020-01-03, p=2020-01-02) → DATEDIFF=1, 20 > 25 → false
#
# Output: id=2

# -------------------- Complexity --------------------
# Time Complexity: O(N^2) worst case (self-join compares rows),
# but practically O(N) because DATEDIFF restricts matches to consecutive days.
# Space Complexity: O(N) for join result set.

# -------------------- Key Notes --------------------
# - MySQL does NOT support FULL OUTER JOIN → use INNER JOIN here.
# - JOIN without condition defaults to INNER JOIN.
# - DATEDIFF(w.recordDate, p.recordDate) = 1 ensures w is exactly one day after p.
# - Always select w.id (today’s ID), not p.id.
# - Pattern: Self-join on date difference for consecutive-day comparisons.
