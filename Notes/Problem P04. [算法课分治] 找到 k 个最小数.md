# Problem P04. [算法课分治] 找到 k 个最小数

![picture 0](.assets_IMG/Problem%20P04.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%88%86%E6%B2%BB%5D%20%E6%89%BE%E5%88%B0%20k%20%E4%B8%AA%E6%9C%80%E5%B0%8F%E6%95%B0/IMG_20231013-085905.png)  

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k; // 输入数组的长度和要找的最小的 k 个数

    std::vector<int> arr(n); // 创建一个整数向量来存储输入的数组

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i]; // 读取数组元素
    }

    std::sort(arr.begin(), arr.end()); // 使用标准库函数对数组进行升序排序

    for (int i = 0; i < k; i++) {
        std::cout << arr[i] << " "; // 输出最小的 k 个数
    }

    return 0;
}
```

1. 首先，我们包含了一些必要的头文件，如iostream和vector，以及算法头文件algorithm，以便使用排序函数`std::sort`。

2. 在`main`函数中，我们首先声明了两个整数变量 `n` 和 `k`，用于存储输入数组的长度和要找的最小的 k 个数。

3. 接下来，我们使用`std::cin`从标准输入读取 `n` 和 `k` 的值。

4. 我们创建一个整数向量 `arr` 来存储输入的整数数组。这个向量的大小被设置为 `n`，以容纳整个数组。

5. 使用一个`for`循环，我们逐个读取输入数组的元素，并将它们存储在 `arr` 向量中。

6. 一旦我们存储了所有的数组元素，我们使用`std::sort`函数对 `arr` 向量进行升序排序，以便找到最小的 k 个数。

7. 最后，我们使用另一个`for`循环输出排好序的 `arr` 向量中的前 k 个元素，这些元素就是最小的 k 个数。

这个程序的关键部分是使用`std::sort`函数对数组进行排序，然后输出前 k 个元素。这样，你就可以找到输入数组中最小的 k 个数。请注意，这是一个基本的示例，对于大型数组，有更高效的算法来实现相同的目标。