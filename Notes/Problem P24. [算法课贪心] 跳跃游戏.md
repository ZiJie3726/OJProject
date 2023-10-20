# Problem P24. [算法课贪心] 跳跃游戏

![picture 0](.assets_IMG/Problem%20P24.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%B4%AA%E5%BF%83%5D%20%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F/IMG_20231017-230525.png)  

详细地解释一下 `canJump` 函数的思路。这个函数使用贪心算法来判断是否能够从数组的第一个位置跳跃到最后一个位置。

1. 首先，初始化一个变量 `maxReach` 为0。这个变量用于记录当前能够到达的最远位置。

2. 然后，我们遍历数组 `nums` 中的每个元素（从第一个位置开始）：

   a. 如果当前位置 `i` 超出了 `maxReach`，即 `i > maxReach`，意味着无法从当前位置跳跃到一个更远的位置，因此返回 `false`。这是因为当前位置无法到达，更远的位置也肯定无法到达。

   b. 否则，如果当前位置 `i` 没有超出 `maxReach`，我们更新 `maxReach` 为当前位置 `i` 和当前位置能够跳跃的最大距离 `nums[i]` 之和的较大值。这是因为从当前位置出发，我们能够跳跃的最远距离是当前位置 `i` 加上它所能够跳跃的最大距离 `nums[i]`。

3. 最后，如果我们成功遍历整个数组，且没有在任何位置出现 `i > maxReach` 的情况，说明我们可以从第一个位置跳跃到最后一个位置，因此返回 `true`。

这个算法的核心思想是根据当前位置能够跳跃的最大距离来更新 `maxReach`，并通过不断更新 `maxReach` 来判断是否能够跳跃到最后一个位置。如果在遍历过程中发现有位置无法到达（`i > maxReach`），则返回 `false`，否则返回 `true`。这是一种高效的贪心算法，因为它只需要一次遍历数组即可判断是否能够到达最后一个位置。

```cpp
#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums) {
  int maxReach = 0; // 记录当前能够到达的最远位置

  for (int i = 0; i < nums.size(); i++) {
  if (i > maxReach) {
	  return false; // 如果当前位置超出了最远能够到达的位置，返回false
	}
	maxReach = max(maxReach, i + nums[i]); // 更新最远能够到达的位置
  }

  return true; // 如果遍历完成都能到达，返回true
}

int main() {
  vector<int> nums;
  int num;
  while (cin >> num) {
	nums.push_back(num);
	if (cin.peek() == '\n')
	  break;
  }

  bool result = canJump(nums);

  if (result) {
	cout << "true" << endl;
  } else {
	cout << "false" << endl;
  }

  return 0;
}
```
