# Problem P21. [算法课分支限界法]组合

![picture 0](.assets_IMG/Problem%20P21.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%88%86%E6%94%AF%E9%99%90%E7%95%8C%E6%B3%95%5D%E7%BB%84%E5%90%88/IMG_20231017-161425.png)  

这是一个关于组合的问题，可以用递归的方式来解决。组合是指从n个元素中选出k个元素的所有不同的方式，不考虑顺序。递归的思路是：

- 如果k等于0，说明已经选出了k个元素，将当前的组合加入到结果集中。
- 如果k大于0，从当前的位置开始，遍历所有的数字，每次选择一个数字加入到当前的组合中，然后递归地从下一个位置开始继续选择。
- 最后将数字从当前的组合中移除，回退到上一步，尝试其他的数字。

下面是用C++写的一个完整的程序，它用一个二维数组res来存储所有的组合，用一个一维数组temp来存储当前的组合，用一个函数combine来实现递归。程序的思路是：

- 输入n和k
- 初始化res和temp
- 调用combine函数，从第一个位置开始搜索
- 输出结果

```cpp
#include <iostream>
#include <vector>
using namespace std;

// 递归函数
void combine(int n, int k, int start, vector<vector<int>>& res, vector<int>& temp) {
    // 如果已经选出了k个元素，将当前的组合加入到结果集中
    if (k == 0) {
        res.push_back(temp);
        return;
    }
    // 从当前的位置开始，遍历所有的数字
    for (int i = start; i <= n; i++) {
        // 将数字加入到当前的组合中
        temp.push_back(i);
        // 递归地从下一个位置开始继续选择
        combine(n, k - 1, i + 1, res, temp);
        // 将数字从当前的组合中移除
        temp.pop_back();
    }
}

// 主函数
int main() {
    // 输入n和k
    int n, k;
    cin >> n >> k;
    // 初始化res和temp
    vector<vector<int>> res;
    vector<int> temp;
    // 调用combine函数，从第一个位置开始搜索
    combine(n, k, 1, res, temp);
    // 输出结果
    cout << "范围 [1, n] 中所有可能的 k 个数的组合 是：" << endl;
    for (auto& v : res) {
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
```

代码的主要部分是一个名为backtrack的递归函数，它有五个参数：

- n：表示从1到n的n个整数
- k：表示要选择的数字的个数
- start：表示当前搜索的起始位置
- res：表示存储所有组合的二维数组
- temp：表示存储当前组合的一维数组

函数的逻辑是：

- 首先判断k是否等于0，如果是，说明已经选出了k个数字，就将temp数组加入到res数组中，然后返回。
- 如果k不等于0，就从start开始，遍历所有的数字，每次将一个数字i加入到temp数组中，然后递归地调用backtrack函数，将n、k-1、i+1、res和temp作为参数传入。这样就相当于在剩下的数字中再选出k-1个数字，组成一个新的组合。
- 在递归调用返回后，将数字i从temp数组中移除，这样就可以回退到上一层，尝试其他的数字。这个过程就是回溯法的核心思想，即在每一层都尝试所有可能的选择，然后在下一层继续搜索，如果发现某个选择不合适，就回退到上一层，换一个选择。

代码的主函数部分是：

- 输入n和k
- 初始化res和temp为空数组
- 调用backtrack函数，将n、k、1、res和temp作为参数传入。这样就相当于从第一个位置开始搜索所有可能的组合。
- 输出res数组中的所有元素，每个元素就是一个组合。
