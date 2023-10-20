# Problem P29. [算法课指针] 颜色分类

![picture 0](.assets_IMG/Problem%20P29.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E6%8C%87%E9%92%88%5D%20%E9%A2%9C%E8%89%B2%E5%88%86%E7%B1%BB/IMG_20231020-170403.png)  

这是一个荷兰国旗问题，可以使用三指针的方法解决。我们可以使用三个指针，分别指向当前已经排好序的最后一个0、1和2。遍历数组，如果遇到0，就将其交换到0指针的位置；如果遇到1，就将其交换到1指针的位置；如果遇到2，就将其交换到2指针的位置。这样遍历完整个数组后，数组就被排好序了。

具体来说，我们使用三个指针 p0、p1 和 p2 分别表示当前已经排好序的最后一个0、1和2。初始时，p0 和 p1 都指向数组开头，p2 指向数组结尾。然后我们从左往右遍历数组，如果遇到了0，就将其交换到 p0 的位置，并将 p0 和 p1 都往右移动一位；如果遇到了2，就将其交换到 p2 的位置，并将 p2 往左移动一位；如果遇到了1，则不需要进行任何操作，直接将 p1 往右移动一位即可。当 p1 大于等于 p2 时，说明整个数组已经被排好序了。

以下是C++代码实现：

```cpp
// solution.cpp

#include "solution.h"

void Solution::SortColors(vector<int> &nums) {
    int n = nums.size(); // 获取数组的长度
    int p0 = 0, p1 = 0, p2 = n - 1; // 初始化三个指针，p0指向第一个元素，p1指向第一个元素，p2指向最后一个元素
    while (p1 <= p2) { // 当p1没有超过p2时，循环执行以下操作
        if (nums[p1] == 0) { // 如果当前元素是0，即红色的
            swap(nums[p0], nums[p1]); // 交换nums[p0]和nums[p1]，将红色的元素放到最前面
            ++p0; // 将p0加一，表示已经处理了一个红色的元素
            ++p1; // 将p1加一，表示已经处理了一个白色的元素
        } else if (nums[p1] == 2) { // 如果当前元素是2，即蓝色的
            swap(nums[p1], nums[p2]); // 交换nums[p1]和nums[p2]，将蓝色的元素放到最后面
            --p2; // 将p2减一，表示已经处理了一个蓝色的元素
        } else { // 如果当前元素是1，即白色的
            ++p1; // 将p1加一，表示已经处理了一个白色的元素
        }
    }
}
```

```cpp
// solution.h

#include <iostream>
#include <vector>

using namespace std;

#ifndef DEBUG_SOLUTION_H_
#define DEBUG_SOLUTION_H_

class Solution {
 public:
  static void SortColors(vector<int> &nums);
};

#endif //DEBUG_SOLUTION_H_
```

```cpp
// main.cpp

#include "solution.h"

int main() {
    int n; // 定义一个整数n，代表数组的长度
    cin >> n; // 输入n
    vector<int> nums(n); // 定义一个大小为n的数组nums
    for (int i = 0; i < n; i++) { // 遍历数组
        cin >> nums[i]; // 输入每个元素
    }
    Solution::SortColors(nums); // 调用s的sortColors方法，对数组进行排序
    cout << "[";
    for (int i = 0; i < n; i++) { // 遍历数组
        cout << nums[i]; // 输出每个元素，用空格隔开
        if (i == n - 1)
            cout << "]";
        else cout << ",";
    }
    cout << endl; // 输出换行符
    return 0; // 返回0，表示程序正常结束
}
```
