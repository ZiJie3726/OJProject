# Problem P16. [算法课贪婪]盛最多的水

![picture 0](.assets_IMG/Problem%20P16.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%B4%AA%E5%A9%AA%5D%E7%9B%9B%E6%9C%80%E5%A4%9A%E7%9A%84%E6%B0%B4/IMG_20231012-163338.png)  

![picture 2](.assets_IMG/Problem%20P16.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%B4%AA%E5%A9%AA%5D%E7%9B%9B%E6%9C%80%E5%A4%9A%E7%9A%84%E6%B0%B4/IMG_20231012-163544.png)  

当面临求解"盛最多水的容器"问题时，我们要找出两条垂直线，使得它们与 x 轴构成的容器能容纳最多的水。这意味着我们要找到这两条线的位置，以便容器的底边（即这两条线之间的距离）最大，同时这两条线的高度要足够高。解决这个问题的一种常见方法是使用双指针。

以下是代码的详细解释：

```cpp
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) {
  int maxWater = 0;     // 用于记录最大容器容积
  int left = 0;         // 左边的指针
  int right = height.size() - 1;  // 右边的指针

  while (left < right) {
    int h = std::min(height[left], height[right]); // 找到当前左右指针位置的两条线的高度的较小值
    int width = right - left; // 计算当前两条线之间的宽度
    int water = h * width;    // 计算容器的容积

    maxWater = std::max(maxWater, water); // 更新最大容积

    if (height[left] < height[right]) {
      left++;  // 如果左边的线较矮，将左指针向右移动，以寻找更高的线
    } else {
      right--; // 如果右边的线较矮，将右指针向左移动，以寻找更高的线
    }
  }

  return maxWater; // 返回最大容器容积
}


#include <iostream>

int main() {
  std::vector<int> n;
  int temp;
  while (std::cin >> temp) {
    n.push_back(temp);
    if (std::cin.peek() == '\n')
      break;
  }
  std::cout << maxArea(n);
}
```

1. 我们首先初始化 `maxWater` 变量为0，这将用于记录最大容器容积。

2. 我们使用两个指针 `left` 和 `right`，分别初始化为容器的左侧和右侧。开始时，它们分别指向容器的最左边和最右边。

3. 在一个循环中，我们计算当前左右指针位置所形成的容器的容积。为此，我们找到两个指针所指位置的高度的较小值 `h`，然后计算两个指针之间的宽度 `width`，最后将 `h` 和 `width` 相乘得到容积 `water`。

4. 我们使用 `std::max` 来更新 `maxWater`，确保它存储最大的容积。

5. 接下来，我们决定如何移动指针。如果左边的线较矮（`height[left]` 小于 `height[right]`），我们将左指针 `left` 向右移动，以寻找更高的线。否则，如果右边的线较矮，我们将右指针 `right` 向左移动。

6. 我们重复这个过程直到左指针 `left` 不再小于右指针 `right`。此时，我们已经找到了容器的最大容积，最后返回 `maxWater` 即可。

这个算法的核心思想是通过双指针来寻找最大容积，同时保持指针的移动方向朝着更有可能找到更大容积的方向。这使得算法的时间复杂度为 O(n)，其中 n 是输入数组 `height` 的大小，而不是 O(n^2) 的暴力枚举法。
