"""
Given an integer n, return the number of unique binary search trees you can form with integers from [0, n). Mod the result by 10 ** 9 + 7

For example, given n = 3, there's 5 unique trees.

0
 \
  1
   \
    2

0
 \
  2
 /
1

    2
   /
  1
 /
0

  2
 /
0
 \
  1

  1
 / \
0   2

Constraints

    n ≤ 1000

Example 1

Input

n = 3

Output

5
"""

class Solution:
    def solve(self, n):
        MOD = 10 ** 9 + 7
        dp = [0] * (n + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            for k in range(i):
                dp[i] += dp[k] * dp[i - 1 - k] % MOD
            dp[i] %= MOD

        return dp[n]
