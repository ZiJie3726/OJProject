# Problem P07. [算法课动态规划]爬楼梯

![picture 0](.assets_IMG/Problem%20P07.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%5D%E7%88%AC%E6%A5%BC%E6%A2%AF/IMG_20231013-102231.png)

```cpp
#include <iostream>
#include <vector>

int climbStairs(int n) {
  if (n <= 2) {
    return n;  // 如果 n 小于等于 2，直接返回 n，因为在这种情况下，只有 n 种走法
  }
  std::vector<int> dp(n + 1);  // 创建一个整数向量 dp，大小为 n+1，用于存储不同台阶数的走法数量
  dp[1] = 1;  // 初始情况：一阶台阶，只有一种走法
  dp[2] = 2;  // 初始情况：两阶台阶，有两种走法
  for (int i = 3; i <= n; ++i) {
    // 从第 3 阶开始，采用动态规划方法计算每个台阶的走法数量
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];  // 返回达到第 n 阶台阶的总走法数量
}

int main() {
  int n;
  std::cin >> n;  // 从标准输入读取 n，即台阶的数量
  int result = climbStairs(n);  // 调用 climbStairs 函数计算走法数量
  std::cout << result << std::endl;  // 输出计算得到的走法数量
  return 0;
}
```

代码执行的详细步骤：

1. 引入必要的头文件，包括iostream和vector。

2. 在`main`函数中，从标准输入读取一个整数 `n`，表示台阶的数量。

3. 调用 `climbStairs` 函数，将 `n` 作为参数传递给它。

4. 在 `climbStairs` 函数中，首先检查如果 `n` 小于等于 2，直接返回 `n`。这是因为在这种情况下，只有 `n` 种走法。如果 `n` 大于 2，创建一个整数向量 `dp`，大小为 `n+1`，用于存储不同台阶数的走法数量。

5. 初始情况：一阶台阶有 1 种走法，两阶台阶有 2 种走法，所以将 `dp[1]` 设为 1，`dp[2]` 设为 2。

6. 使用一个循环从第 3 阶开始，采用动态规划方法计算每个台阶的走法数量。`dp[i]` 表示到达第 `i` 阶的总走法数量，它等于 `dp[i - 1]` 和 `dp[i - 2]` 的和。

7. 最后，`climbStairs` 函数返回 `dp[n]`，即到达第 `n` 阶台阶的总走法数量。

8. 在 `main` 函数中，结果被输出到标准输出，显示了达到第 `n` 阶台阶的总走法数量。

通过迭代计算不同台阶数的走法数量，最终得出到达第 `n` 阶台阶的总走法数量。
