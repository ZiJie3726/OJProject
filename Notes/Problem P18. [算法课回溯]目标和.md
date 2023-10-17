# Problem P18. [算法课回溯]目标和

![picture 0](.assets_IMG/Problem%20P18.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%9B%9E%E6%BA%AF%5D%E7%9B%AE%E6%A0%87%E5%92%8C/IMG_20231017-114714.png)  

## 回溯算法

### openai

下面是使用回溯算法解决问题的C++代码，我将为你逐行进行详细解释：

```cpp
#include <iostream>
#include <vector>
using namespace std;

// 递归函数，用于探索所有可能的表达式
int countExpressions(vector<int>& nums, int target, int index, int currentSum) {
    if (index == nums.size()) {
        // 如果我们已经处理完了所有数字
        // 检查当前和是否等于目标，如果是则返回1，否则返回0
        return (currentSum == target) ? 1 : 0;
    }

    int ways = 0;
    // 尝试在当前数字前添加 '+' 号
    ways += countExpressions(nums, target, index + 1, currentSum + nums[index]);
    // 尝试在当前数字前添加 '-' 号
    ways += countExpressions(nums, target, index + 1, currentSum - nums[index]);

    return ways;
}

// 主函数，用于调用递归函数并输出结果
int findWaysToReachTarget(vector<int>& nums, int target) {
    return countExpressions(nums, target, 0, 0);
}

int main() {
    vector<int> nums;
    int target;

    // 输入 nums
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }

    // 输入 target
    cin >> target;

    // 调用主函数以计算表达式数量
    int result = findWaysToReachTarget(nums, target);

    // 输出结果
    cout << result << endl;

    return 0;
}
```

1. 首先，我们包括必要的头文件，创建了一个空的整数向量 `nums` 来存储输入的整数数组，以及一个整数 `target` 用于存储目标值。

2. 在 `countExpressions` 函数中，我们使用回溯来探索所有可能的表达式。参数 `index` 表示当前处理的数字的索引，`currentSum` 表示到目前为止的求和结果。

3. 如果 `index` 等于 `nums` 数组的大小，说明我们已经处理完了所有数字，此时检查 `currentSum` 是否等于 `target`。如果是，返回1，表示找到了一种满足条件的表达式；否则，返回0。

4. 否则，我们在当前数字前添加 '+' 号和 '-' 号，分别递归调用 `countExpressions` 函数，继续探索下一个数字。

5. 在 `findWaysToReachTarget` 函数中，我们开始调用 `countExpressions` 函数来启动递归过程。

6. 在 `main` 函数中，我们输入整数数组 `nums` 和目标整数 `target`。

7. 然后，我们调用 `findWaysToReachTarget` 函数来计算可以构造的表达式数量，将结果存储在 `result` 中。

8. 最后，我们将结果输出到标准输出流，显示答案。

### bing

用回溯算法来解决这个问题也是可行的，但是可能会比动态规划的方法更慢，因为回溯算法会遍历所有可能的表达式，而动态规划的方法会利用子问题的解来减少重复计算。如果你想尝试用回溯算法来写这个代码，你可以参考以下的C++代码：

```c++
#include <iostream>
#include <vector>
using namespace std;

// 定义一个全局变量result，用于存储结果
int result = 0;

// 定义一个回溯函数，参数为数组nums，目标值target，当前索引index，当前和sum
void backtrack(vector<int>& nums, int target, int index, int sum) {
    // 如果索引等于数组长度，说明已经遍历完所有元素
    if (index == nums.size()) {
        // 如果当前和等于目标值，说明找到了一个合法的表达式，结果加一
        if (sum == target) {
            result++;
        }
        // 返回上一层递归
        return;
    }
    // 尝试给当前元素添加正号，并向前搜索
    backtrack(nums, target, index + 1, sum + nums[index]);
    // 尝试给当前元素添加负号，并向前搜索
    backtrack(nums, target, index + 1, sum - nums[index]);
}

// 定义一个主函数，从标准输入读取数据，并输出结果
int main() {
    // 定义一个整数向量nums，用于存储输入的数组
    vector<int> nums;
    // 定义一个整数变量target，用于存储输入的目标值
    int target;
    // 定义一个整数变量num，用于临时存储输入的每个元素
    int num;
    // 使用空格分隔输入的数组元素，以回车结束输入
    cout << "请输入一个整数数组（以空格分隔）：" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') break;
    }
    // 输入目标值
    cout << "请输入一个整数目标值：" << endl;
    cin >> target;
    // 调用回溯函数，从第0个元素和0开始搜索
    backtrack(nums, target, 0, 0);
    // 输出结果
    cout << "可以构造出目标值的表达式的数目为：" << endl;
    cout << result << endl;
}
```

## 动态规划

### bing

这是一个经典的**动态规划**问题，可以用以下的C++代码来解决：

```c++
#include <iostream>
#include <vector>
using namespace std;

// 计算数组nums中所有元素的和
int sum(vector<int>& nums) {
    int s = 0;
    for (int num : nums) {
        s += num;
    }
    return s;
}

// 计算数组nums中可以构造出target的表达式的数目
int findTargetSumWays(vector<int>& nums, int target) {
    // 如果数组为空，返回0
    if (nums.empty()) return 0;
    // 如果数组和小于target的绝对值，返回0
    int s = sum(nums);
    if (s < abs(target)) return 0;
    // 定义dp数组，dp[i][j]表示前i个元素可以构造出j的表达式的数目
    // dp数组的大小为(n+1) * (2s+1)，其中n为数组长度，s为数组和
    // dp数组的第一列为0，表示没有元素时不能构造出任何非零值
    // dp数组的中间列为1，表示没有元素时可以构造出0（空表达式）
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * s + 1, 0));
    dp[0][s] = 1;
    // 遍历数组中的每个元素
    for (int i = 1; i <= n; i++) {
        // 遍历dp数组中的每个值
        for (int j = 0; j <= 2 * s; j++) {
            // 如果当前值减去元素值不越界，累加dp[i-1][j-nums[i-1]]到dp[i][j]
            if (j - nums[i - 1] >= 0) {
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
            // 如果当前值加上元素值不越界，累加dp[i-1][j+nums[i-1]]到dp[i][j]
            if (j + nums[i - 1] <= 2 * s) {
                dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
        }
    }
    // 返回dp[n][s+target]，即最后一个元素可以构造出target的表达式的数目
    return dp[n][s + target];
}

// 主函数，从标准输入读取数据，并输出结果
int main() {
    // 定义一个整数向量nums，用于存储输入的数组
    vector<int> nums;
    // 定义一个整数变量target，用于存储输入的目标值
    int target;
    // 定义一个整数变量num，用于临时存储输入的每个元素
    int num;
    // 使用空格分隔输入的数组元素，以回车结束输入
    cout << "请输入一个整数数组（以空格分隔）：" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') break;
    }
    // 输入目标值
    cout << "请输入一个整数目标值：" << endl;
    cin >> target;
    // 调用findTargetSumWays函数，计算结果，并输出
    int result = findTargetSumWays(nums, target);
    cout << "可以构造出目标值的表达式的数目为：" << endl;
    cout << result << endl;
}
```

接下来，我会用简单的语言来解释这段代码的思路和细节。

首先，这个问题的本质是求解一个**01背包问题**，即给定一个容量为target的背包和一些物品（数组中的元素），每个物品有两种状态（正号或负号），求有多少种方法可以恰好装满背包。这个问题可以用**动态规划**的方法来解决，即用一个二维数组dp来记录不同状态下的解的数目，然后根据状态转移方程来更新dp数组。

具体来说，我们可以定义dp[i][j]表示前i个元素可以构造出j的表达式的数目，其中i从0到n（数组长度），j从-s到s（数组和）。那么，我们的目标就是求dp[n][target]，即最后一个元素可以构造出target的表达式的数目。为了方便计算，我们可以将j的范围平移s个单位，即从0到2s，这样就可以避免负数下标的问题。也就是说，我们实际上是求dp[n][s+target]。

那么，如何更新dp数组呢？我们可以从两个方面来考虑：

- 如果我们给第i个元素添加正号，那么它对应的值就是nums[i-1]（因为数组下标从0开始），那么它可以由前i-1个元素构造出j-nums[i-1]的表达式转化而来，也就是说dp[i][j] += dp[i-1][j-nums[i-1]]。
- 如果我们给第i个元素添加负号，那么它对应的值就是-nums[i-1]，那么它可以由前i-1个元素构造出j+nums[i-1]的表达式转化而来，也就是说dp[i][j] += dp[i-1][j+nums[i-1]]。

当然，在更新dp数组时，我们还要注意边界条件，即不能越界。也就是说，当j-nums[i-1]或者j+nums[i-1]超出了0到2s的范围时，我们就不能进行累加操作。

最后，我们还要初始化dp数组，即给定一些初始值。由于没有元素时不能构造出任何非零值，所以dp数组的第一列都为0（除了中间位置为1）。也就是说，dp[0][s] = 1，表示没有元素时可以构造出0（空表达式）。其他位置都为0，表示没有元素时不能构造出其他值。

: 01背包问题是一种组合优化问题，要求在一定容量限制下选择若干物品使得总价值最大。[01背包问题](https://zh.wikipedia.org/wiki/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98)
: 动态规划是一种求解复杂问题的方法，通过将问题分解为子问题，并存储子问题的解来避免重复计算。[动态规划](https://zh.wikipedia.org/wiki/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92)

### openai

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 函数用于计算可以构造的表达式数量
int findWaysToReachTarget(vector<int>& nums, int target) {
    // 使用 memoization 保存计算结果，memo[index][currentSum] 表示在给定索引和当前和的情况下的结果
    unordered_map<int, unordered_map<int, int>> memo;

    // 递归函数，用于计算从给定索引和当前和到达目标的方法数
    function<int(int, int)> dfs = [&](int index, int currentSum) -> int {
        if (index == nums.size()) {
            // 如果到达数组的末尾，检查当前和是否等于目标，如果是则返回1，否则返回0
            return (currentSum == target) ? 1 : 0;
        }

        // 检查结果是否已经被记忆
        if (memo.find(index) != memo.end() && memo[index].find(currentSum) != memo[index].end()) {
            return memo[index][currentSum];
        }

        int ways = 0;
        // 尝试将当前数字加到当前和中
        ways += dfs(index + 1, currentSum + nums[index]);
        // 尝试将当前数字从当前和中减去
        ways += dfs(index + 1, currentSum - nums[index]);

        // 记忆结果，以便后续使用
        memo[index][currentSum] = ways;

        return ways;
    };

    return dfs(0, 0);
}

int main() {
    vector<int> nums;
    int target;

    // 输入 nums
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }

    // 输入 target
    cin >> target;

    int result = findWaysToReachTarget(nums, target);
    cout << result << endl;

    return 0;
}
```

在这个代码中，主要的思想是使用递归函数 `dfs` 来探索添加 '+' 和 '-' 号到数组中每个数字前可能产生的结果。memoization（记忆化搜索）用于避免重复计算相同的情况，从而提高效率。这个程序会将结果输出到标准输出流。输入 `nums` 和 `target`，然后计算出可以构造的表达式数量并输出结果。
