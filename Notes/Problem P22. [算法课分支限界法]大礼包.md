# Problem P22. [算法课分支限界法]大礼包

![picture 0](.assets_IMG/Problem%20P22.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%88%86%E6%94%AF%E9%99%90%E7%95%8C%E6%B3%95%5D%E5%A4%A7%E7%A4%BC%E5%8C%85/IMG_20231017-173502.png)  

![picture 2](.assets_IMG/Problem%20P22.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%88%86%E6%94%AF%E9%99%90%E7%95%8C%E6%B3%95%5D%E5%A4%A7%E7%A4%BC%E5%8C%85/IMG_20231017-182904.png)  

![picture 3](.assets_IMG/Problem%20P22.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%88%86%E6%94%AF%E9%99%90%E7%95%8C%E6%B3%95%5D%E5%A4%A7%E7%A4%BC%E5%8C%85/IMG_20231017-183000.png)  

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
 public:
  map<vector<int>, int> memo;

  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
	int n = price.size();

	// 过滤不需要计算的大礼包，只保留需要计算的大礼包
	vector<vector<int>> filterSpecial;
	for (auto & sp : special) {
	  int totalCount = 0, totalPrice = 0;
	  for (int i = 0; i < n; ++i) {
		totalCount += sp[i];
		totalPrice += sp[i] * price[i];
	  }
	  if (totalCount > 0 && totalPrice > sp[n]) {
		filterSpecial.emplace_back(sp);
	  }
	}

	return dfs(price, special, needs, filterSpecial, n);
  }

  // 记忆化搜索计算满足购物清单所需花费的最低价格
  int dfs(vector<int> price,const vector<vector<int>> & special, vector<int> curNeeds, vector<vector<int>> & filterSpecial, int n) {
	if (!memo.count(curNeeds)) {
	  int minPrice = 0;
	  for (int i = 0; i < n; ++i) {
		minPrice += curNeeds[i] * price[i]; // 不购买任何大礼包，原价购买购物清单中的所有物品
	  }
	  for (auto & curSpecial : filterSpecial) {
		int specialPrice = curSpecial[n];
		vector<int> nxtNeeds;
		for (int i = 0; i < n; ++i) {
		  if (curSpecial[i] > curNeeds[i]) { // 不能购买超出购物清单指定数量的物品
			break;
		  }
		  nxtNeeds.emplace_back(curNeeds[i] - curSpecial[i]);
		}
		if (nxtNeeds.size() == n) { // 大礼包可以购买
		  minPrice = min(minPrice, dfs(price, special, nxtNeeds, filterSpecial, n) + specialPrice);
		}
	  }
	  memo[curNeeds] = minPrice;
	}
	return memo[curNeeds];
  }
};

int main() {
  Solution sol;
  vector<int> price; // 物品价格数组
  int temp,m;
  while (cin >> temp){
	price.push_back(temp);
	if (cin.peek() == '\n'){
	  m = price.back();
	  price.pop_back();
	  break;
	}
  }
  int n = price.size();
  m = temp;
  vector<vector<int>> special(m, vector<int>(n + 1)); // 大礼包数组，每个大礼包包含n + 1个元素，前n个表示每种物品的数量，最后一个表示价格
  for (int i = 0; i < m; i++) {
	for (int j = 0; j < price.size() + 1; j++) {
	  cin >> special[i][j];
	}
  }
  vector<int> needs(n); // 购物清单数组，表示每种物品需要购买的数量
  for (int i = 0; i < n; i++) {
	cin >> needs[i];
  }

  cout << sol.shoppingOffers(price, special, needs) << endl; // 输出满足购物清单所需花费的最低价格

  return 0;
}
```

较差的算法：LeetCode不通过：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个函数，用来判断是否可以购买某个大礼包
bool canBuy(const vector<int>& needs, const vector<int>& special) {
  for (int i = 0; i < needs.size(); i++) {
	if (needs[i] < special[i]) return false; // 如果购物清单上的物品数量小于大礼包中的物品数量，不能购买
  }
  return true; // 否则可以购买
}

// 定义一个函数，用来计算满足购物清单所需花费的最低价格
int shopping(const vector<int>& price, const vector<vector<int>>& special, const vector<int>& needs) {
  int n = price.size(); // 物品的种类数
  int m = special.size(); // 大礼包的个数
  int ans = 0; // 初始化答案为0

  // 计算如果不使用任何大礼包，只按照原价购买所需花费的价格
  for (int i = 0; i < n; i++) {
	ans += price[i] * needs[i];
  }

  // 遍历每个大礼包，尝试使用它并递归计算剩余的购物清单所需花费的最低价格
  for (int i = 0; i < m; i++) {
	if (canBuy(needs, special[i])) { // 如果可以购买这个大礼包
	  vector<int> newNeeds = needs; // 创建一个新的购物清单，用来存储使用这个大礼包后剩余的物品数量
	  for (int j = 0; j < n; j++) {
		newNeeds[j] -= special[i][j]; // 更新每种物品的数量
	  }
	  ans = min(ans, special[i][n] + shopping(price, special, newNeeds)); // 更新答案为使用这个大礼包后的价格和不使用这个大礼包的价格中的较小值
	}
  }

  return ans; // 返回答案
}

int main() {
  vector<int> price; // 物品价格数组
  int temp,m;
  while (cin >> temp){
	price.push_back(temp);
	if (cin.peek() == '\n'){
	  m = price.back();
	  price.pop_back();
	  break;
	}
  }
  int n = price.size();
  m = temp;
  vector<vector<int>> special(m, vector<int>(n + 1)); // 大礼包数组，每个大礼包包含n + 1个元素，前n个表示每种物品的数量，最后一个表示价格
  for (int i = 0; i < m; i++) {
	for (int j = 0; j < price.size() + 1; j++) {
	  cin >> special[i][j];
	}
  }
  vector<int> needs(n); // 购物清单数组，表示每种物品需要购买的数量
  for (int i = 0; i < n; i++) {
	cin >> needs[i];
  }

  cout << shopping(price, special, needs) << endl; // 输出满足购物清单所需花费的最低价格

  return 0;
}
```
