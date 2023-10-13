# Problem P03. [算法课分治] 找到最大子序和

![picture 0](.assets_IMG/Problem%20P03.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%88%86%E6%B2%BB%5D%20%E6%89%BE%E5%88%B0%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C/IMG_20231013-085131.png)  

```cpp
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0]; // 初始化最大子数组和为第一个元素
    int currentSum = nums[0]; // 初始化当前子数组和为第一个元素

    for (int i = 1; i < nums.size(); i++) {
        // 比较当前元素与当前子数组和+当前元素的大小，选择较大者
        currentSum = max(nums[i], currentSum + nums[i]);
        // 比较maxSum与当前currentSum，选择较大者
        maxSum = max(maxSum, currentSum);
    }

    return maxSum; // 返回最大子数组和
}

int main() {
    int n;
    cin >> n; // 输入数组的长度
    vector<int> nums(n); // 创建一个整数数组来存储输入的数字

    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // 读取输入的数组元素
    }

    int result = maxSubArray(nums); // 调用maxSubArray函数找到最大子数组和
    cout << result << endl; // 输出最大子数组和

    return 0;
}
```

这个代码用于找到一个整数数组中具有最大和的连续子数组，它采用了动态规划的方法。在 `maxSubArray` 函数中，我们使用两个变量 `maxSum` 和 `currentSum` 分别跟踪最大子数组和和当前子数组和。随着循环的进行，我们不断更新这些变量，以找到最大的子数组和。最后，我们在 `main` 函数中读取输入，调用 `maxSubArray` 函数，并输出结果。

当要解决这个问题时，我们首先需要理解动态规划的思想。我们将使用一个动态规划算法来找到最大子数组和。下面是代码的详细解释：

1. 首先，我们定义了一个函数 `maxSubArray`，它接受一个整数数组 `nums` 作为参数，并返回最大子数组和。

2. 在函数内部，我们定义了两变量 `maxSum` 和 `currentSum`，它们用来跟踪最大子数组和和当前子数组和。

3. 我们初始化 `maxSum` 和 `currentSum` 都为数组中的第一个元素 `nums[0]`，因为初始时最大子数组和和当前子数组和都是第一个元素的值。

4. 然后，我们进入一个循环，从数组的第二个元素开始遍历。在每一步中，我们比较当前元素 `nums[i]` 与当前子数组和 `currentSum + nums[i]` 的大小，选择其中较大的值作为新的 `currentSum`。这是因为我们想找到包含当前元素的最大子数组和。

5. 接下来，我们比较 `maxSum` 和当前的 `currentSum`，并将其中较大的值更新为 `maxSum`。这个步骤确保 `maxSum` 始终存储到目前为止找到的最大子数组和。

6. 循环继续，以相同的方式遍历数组的所有元素。

7. 当循环结束时，`maxSum` 中将包含整个数组的最大子数组和。

8. 最后，我们在 `main` 函数中读取输入。首先，我们读取数组的长度 `n`，然后创建一个名为 `nums` 的整数数组，以存储输入的数字。

9. 然后，我们使用一个循环来读取 `n` 个数字并将它们存储在 `nums` 数组中。

10. 接下来，我们调用 `maxSubArray` 函数，将 `nums` 数组作为参数传递，并将结果存储在 `result` 变量中。

11. 最后，我们输出 `result`，这是找到的最大子数组和。

这个算法的核心思想是通过迭代数组元素，不断更新当前子数组和和最大子数组和，以找到最大的子数组和。这种动态规划方法非常有效，因为它只需要一次遍历数组即可找到解决方案。
