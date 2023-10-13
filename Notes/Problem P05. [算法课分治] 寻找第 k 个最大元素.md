# Problem P05. [算法课分治] 寻找第 k 个最大元素

![picture 0](.assets_IMG/Problem%20P05.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%88%86%E6%B2%BB%5D%20%E5%AF%BB%E6%89%BE%E7%AC%AC%20k%20%E4%B8%AA%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0/IMG_20231013-091517.png)  

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k; // 输入数组的长度和要找的第k个最大元素

    std::vector<int> nums(n); // 创建一个整数向量来存储输入的数组

    for (int i = 0; i < n; i++) {
        std::cin >> nums[i]; // 读取数组元素
    }

    std::sort(nums.begin(), nums.end(), std::greater<int>()); // 使用降序排序

    int kthLargest = nums[k - 1]; // 找到第k个最大元素

    std::cout << kthLargest; // 输出第k个最大元素

    return 0;
}
```

现在来详细讲解这个代码：

1. 首先，我们包含了必要的头文件，如iostream和vector，以及算法头文件algorithm。

2. 在`main`函数中，我们声明了两个整数变量 `n` 和 `k`，用于存储输入数组的长度和要找的第k个最大元素。

3. 使用`std::cin`从标准输入读取 `n` 和 `k` 的值。

4. 创建一个整数向量 `nums` 来存储输入的整数数组。这个向量的大小被设置为 `n`，以容纳整个数组。

5. 使用一个`for`循环，我们逐个读取输入数组的元素，并将它们存储在 `nums` 向量中。

6. 接下来，我们使用`std::sort`函数对 `nums` 向量进行降序排序，这意味着数组中的元素按照从大到小的顺序排列。

7. 为了找到第k个最大元素，我们访问 `nums` 向量的第k-1个元素，因为向量的索引从0开始。这个元素即为第k个最大元素。

8. 最后，我们输出找到的第k个最大元素。
