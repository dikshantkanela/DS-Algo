#include <bits/stdc++.h> 

/*
Approach:
- This is a **recursive approach** to solving the problem.
- The base case:
  - If `nStairs == 0` or `nStairs == 1`, return 1 (only one way to climb).
- Recursive relation:
  - The number of ways to reach `n` stairs is the sum of ways to reach `(n-1)` and `(n-2)`.
  - This follows the Fibonacci sequence: `f(n) = f(n-1) + f(n-2)`.
- **Time Complexity**: O(2ⁿ) (Exponential, due to repeated calculations)
- **Space Complexity**: O(n) (Recursive stack space)
- **Drawback**: Inefficient for large `n` due to redundant recursive calls.
*/

int countDistinctWays(int nStairs) {
    if(nStairs == 0 || nStairs == 1){
        return 1;
    }
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

