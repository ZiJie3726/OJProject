# Problem P28. [算法课贪心] 跳跃游戏

![picture 2](.assets_IMG/Problem%20P28.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%B4%AA%E5%BF%83%5D%20%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F/IMG_20231020_110328.png)  

- 从数组的第一个位置开始，记录当前能跳到的最远位置和下一步能跳到的最远位置。
- 每次跳跃时，更新下一步能跳到的最远位置，如果当前位置达到了之前记录的最远位置，说明需要再跳一次，并且更新最远位置为下一步能跳到的最远位置。
- 重复这个过程，直到到达数组的最后一个位置，返回跳跃次数。

用C++实现的代码如下：

```cpp
// solution.cpp

#include "solution.h"

int Solution::jump(vector<int> &nums) {
  unsigned long long n = nums.size();
  int cur = 0; // 当前能跳到的最远位置
  int next = 0; // 下一步能跳到的最远位置
  int ans = 0; // 跳跃次数
  for (int i = 0; i < n - 1; i++) {
	next = max(next, i + nums[i]); // 更新下一步能跳到的最远位置
	if (i == cur) { // 如果当前位置达到了之前记录的最远位置
	  ans++; // 需要再跳一次
	  cur = next; // 更新最远位置为下一步能跳到的最远位置
	}
  }
  return ans;
}
```

```cpp
// solution.h
#include <vector>

using namespace std;

#ifndef DEBUG__SOLUTION_H_
#define DEBUG__SOLUTION_H_

class Solution {
 public:
  static int jump(vector<int> &nums);
};

#endif //DEBUG__SOLUTION_H_
```

```cpp
// main.cpp

#include <iostream>

#include "solution.h"

int main() {
  vector<int> nums;
  int t;
  cin >> t;
  int temp;
  while (cin >> temp) {
	nums.push_back(temp);
	if (cin.peek() == '\n')
	  break;
  }
  cout << Solution::jump(nums) << endl;
  return 0;
}
```

首先，我们定义了四个变量，分别是：

- `n`：数组的长度，用`nums.size()`获取。
- `cur`：当前能跳到的最远位置，初始值为0。
- `next`：下一步能跳到的最远位置，初始值为0。
- `ans`：跳跃次数，初始值为0。

然后，我们用一个`for`循环遍历数组中的每个元素，除了最后一个元素（因为我们假设总是可以到达最后一个位置）。

在循环中，我们做了两件事：

- 更新下一步能跳到的最远位置，用`max(next, i + nums[i])`表示。这里的`i`是当前元素的下标，`nums[i]`是当前元素的值，表示从当前位置能跳到的最远距离。我们用`max`函数取两者中的较大值，保证下一步能跳到的最远位置是最优的。
- 判断是否需要跳跃，用`if (i == cur)`表示。这里的`cur`是之前记录的当前能跳到的最远位置。如果当前元素的下标等于这个位置，说明我们已经达到了当前能跳到的极限，需要再跳一次才能继续前进。所以我们把跳跃次数加一，并且把当前能跳到的最远位置更新为下一步能跳到的最远位置。

循环结束后，我们返回跳跃次数作为答案。

这个算法的时间复杂度是O(n)，空间复杂度是O(1)。
