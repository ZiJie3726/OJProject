//
// Created by MCZJ3 on 9/13/2023.
//
#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
  // 创建一个二维数组dp，其中dp[i][j]表示从左上角到达网格(i, j)的不同路径数
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
  // 初始化第一行和第一列，因为只能向右或向下移动，所以只有一种路径
  for (int i = 0; i < m; ++i) {
	dp[i][0] = 1;
  }
  for (int j = 0; j < n; ++j) {
	dp[0][j] = 1;
  }
  // 使用动态规划计算路径数量
  for (int i = 1; i < m; ++i) {
	for (int j = 1; j < n; ++j) {
	  dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}
  }
  // 返回右下角格子的路径数量
  return dp[m - 1][n - 1];
}

int main() {
  int m, n;
  std::cin >> m >> n;
  int result = uniquePaths(m, n);
  std::cout << result << std::endl;
  return 0;
}
