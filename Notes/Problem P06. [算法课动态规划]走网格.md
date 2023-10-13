# Problem P06. [算法课动态规划]走网格

![picture 0](.assets_IMG/Problem%20P06.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%5D%E8%B5%B0%E7%BD%91%E6%A0%BC/IMG_20231013-101904.png)

```cpp
#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
    // 创建一个二维矩阵 dp，大小为 m x n，用于存储到达每个格子的路径数量
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    // 初始化第一行和第一列为1，因为只有一种方式到达这些格子：一直向右或一直向下
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    // 使用动态规划填充剩余的格子
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // 返回右下角格子的路径数量，它代表了从左上角到右下角的总路径数量
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    std::cin >> m >> n;

    int result = uniquePaths(m, n);
    std::cout << result << std::endl;

    return 0;
}
```

这段代码执行以下操作：

1. 引入必要的头文件，包括iostream和vector。

2. 在`main`函数中，首先从标准输入读取m和n的值，这些值代表了网格的行数和列数。

3. 创建一个二维矩阵 `dp`，大小为m x n，用于存储到达每个格子的路径数量。初始化第一行和第一列为1，因为只有一种方式到达这些格子：一直向右或一直向下。

4. 使用嵌套循环填充剩余的格子。每个格子的路径数量等于其上方格子和左侧格子的路径数量之和，因为只能向下或向右移动。

5. 返回`dp[m-1][n-1]`的值，它代表了从左上角到右下角的总路径数量。

这个程序采用动态规划方法来计算从左上角到右下角的路径数量。对于给定的m行n列的网格，它能够找到共有多少种不同的走法以到达右下角。
