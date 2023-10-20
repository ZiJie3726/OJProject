# Problem P26. [算法课动态规划] 打家劫舍

![picture 0](.assets_IMG/Problem%20P26.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%5D%20%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D/IMG_20231018-085005.png)  

这个问题可以通过动态规划来解决。我们可以维护一个数组 `dp`，其中 `dp[i]` 表示在第 `i` 个房屋之前，小偷能够偷窃到的最高金额。动态规划的思路如下：

1. 对于第一个房屋（`nums[0]`），小偷只能选择偷窃它，因此 `dp[0] = nums[0]`。

2. 对于第二个房屋（`nums[1]`），小偷可以选择偷窃它或者不偷窃它。如果小偷偷窃第二个房屋，那么最高金额就是 `nums[1]`。如果小偷不偷窃第二个房屋，那么最高金额就是 `nums[0]`（第一个房屋的金额）。因此，`dp[1]` 的值为 `max(nums[0], nums[1])`。

3. 对于第三个房屋（`nums[2]`）以及之后的房屋，小偷有两种选择：
   a. 偷窃第 `i` 个房屋，此时最高金额是 `dp[i-2] + nums[i]`，因为小偷不能连续偷窃相邻的房屋。
   b. 不偷窃第 `i` 个房屋，此时最高金额是 `dp[i-1]`。
   小偷在这两种选择中选择较大的金额，更新 `dp[i]`。

4. 最终，`dp[n-1]` 即为小偷能够偷窃到的最高金额，其中 `n` 是房屋的总数。

以下是使用动态规划的C++代码示例：

```cpp
// solution.cpp

#include "solution.h"

int Solution::Rob(vector<int> &nums) {
  unsigned long n = nums.size();
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return nums[0];
  }

  vector<int> dp(n, 0);
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);

  for (int i = 2; i < n; i++) {
    dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
  }

  return dp[n-1];
}
```

这个代码使用动态规划来计算小偷在不触动警报装置的情况下能够偷窃到的最高金额。`dp[n-1]` 包含了所有房屋中小偷能够偷窃到的最高金额。动态规划的核心思想是在每个房屋处选择偷窃或不偷窃，然后根据前一步的最高金额来更新当前步的最高金额。最终返回 `dp[n-1]` 即可。

```cpp
// solution.h

#include <vector>

using namespace std;

#ifndef DEBUG__SOLUTION_H_
#define DEBUG__SOLUTION_H_

class Solution {
 public:
  static int Rob(vector<int> &nums);
};

#endif //DEBUG__SOLUTION_H_
```

```cpp
// main.cpp

#include <iostream>
#include "solution.h"

int main() {
  vector<int> nums;
  int temp;
  while (cin >> temp) {
    nums.push_back(temp);
    if (cin.peek() == '\n')
      break;
  }
  cout << Solution::Rob(nums);
}
```
