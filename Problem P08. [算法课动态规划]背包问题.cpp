//
// Created by MCZJ3 on 9/13/2023.
//
#include <iostream>
#include <vector>
void bag(std::vector<int> &V, std::vector<int> &W, int n, int cap) {
  int sum = 0;
  for (int i = 0; i < n; ++i) {
	for (int j = i + 1; j < n; ++j) {
	  if (W[i] + W[j] <= cap) {
		if (V[i] + V[j] > sum) {
		  sum = V[i] + V[j];
		}
	  }
	}
  }
  std::cout << sum;
}
int main() {
  int n, cap;
  std::cin >> n >> cap;
  std::vector<int> V = {42, 12, 40, 25};
  std::vector<int> W = {7, 3, 4, 5};
  bag(V, W, n, cap);
  return 0;
}
/*#include <iostream>
#include <vector>

using namespace std;

int knapsack(int N, int W, vector<int>& weights, vector<int>& values) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][W];
}
//创建一个二维数组 dp，其中 dp[i][j] 表示在前i个物品中，背包承重为j时的最大总价值。这个数组用于存储问题的中间结果，以便避免重复计算。
//使用双重循环遍历所有可能的物品和背包承重组合。外层循环 i 表示考虑前i个物品，内层循环 j 表示背包的承重。
//在每个循环步骤中，我们首先检查当前物品是否可以放入背包。这是通过比较物品的重量 weights[i - 1] 与当前背包承重 j 来判断的。如果 weights[i - 1] <= j，说明当前物品可以放入背包，否则不能。
//如果当前物品可以放入背包（即 weights[i - 1] <= j），我们需要做出一个决策：是将该物品放入背包，还是不放入背包。我们选择使总价值最大的那个决策。
//如果将物品放入背包，那么我们将考虑前i-1个物品，扣除当前物品的重量 weights[i - 1]，并将当前物品的价值 values[i - 1] 添加到背包中。因此，总价值为 dp[i-1][j-weights[i-1]] + values[i-1]。
//如果不将物品放入背包，那么背包中的总价值与前i-1个物品时的总价值相同，即 dp[i-1][j]。
//我们选择较大的那个值，并将其存储在 dp[i][j] 中。
//如果当前物品不能放入背包（即 weights[i - 1] > j），那么我们无法选择当前物品，因此 dp[i][j] 将等于 dp[i-1][j]，即背包中的总价值与前i-1个物品时的总价值相同。
//最终，dp[N][W] 中存储的值就是在给定背包承重下，选择物品以获得最大总价值的结果。
//动态规划的核心思想是将复杂问题分解成子问题，然后根据子问题的解构建出整体问题的解。在背包问题中，我们通过填充二维数组 dp 来记录子问题的解，最终得到了在给定背包承重下的最大总价值。希望这个解释有助于你更好地理解动态规划算法和代码。
int main() {
    int N = 4; // 物品数量
    int W = 10; // 背包承重
    vector<int> weights = {7, 3, 4, 5}; // 物品重量
    vector<int> values = {42, 12, 40, 25}; // 物品价值

    int result = knapsack(N, W, weights, values);
    cout << "背包中物品的最大总价值为: " << result << endl;

    return 0;
}
*/
