# Problem P20. [算法课回溯]优美的排列

![picture 1](.assets_IMG/Problem%20P20.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%9B%9E%E6%BA%AF%5D%E4%BC%98%E7%BE%8E%E7%9A%84%E6%8E%92%E5%88%97/IMG_20231017-141807.png)  

这是一个关于回溯法的问题，可以用递归的方式来解决。回溯法是一种搜索所有可能解的方法，它从一个初始状态开始，每次尝试一个可能的选择，如果这个选择满足条件，就继续往下搜索，否则就回退到上一步，尝试另一个选择，直到找到所有的解或者没有更多的选择为止。

下面是用C++写的一个完整的程序，它用一个数组visited来记录哪些数字已经被使用过，用一个变量count来记录优美排列的数量，用一个函数backtrack来实现回溯法。程序的思路是：

- 从第一个位置开始，遍历所有的数字，如果数字没有被使用过，并且能够被位置整除或者位置能够被数字整除，就将数字放在当前位置，并将visited数组对应的位置设为true，表示已经使用过。
- 然后递归地搜索下一个位置，如果找到了一个优美排列，就将count加一。
- 最后将数字从当前位置移除，并将visited数组对应的位置设为false，表示没有使用过，回退到上一步，尝试其他的数字。

```cpp
#include <iostream>
#include <vector>
using namespace std;

// 回溯法函数
void backtrack(int n, int pos, vector<bool>& visited, int& count) {
    // 如果已经到达最后一个位置，说明找到了一个优美排列
    if (pos > n) {
        count++;
        return;
    }
    // 遍历所有的数字
    for (int i = 1; i <= n; i++) {
        // 如果数字没有被使用过，并且能够被位置整除或者位置能够被数字整除
        if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
            // 将数字放在当前位置，并将visited数组对应的位置设为true
            visited[i] = true;
            // 递归地搜索下一个位置
            backtrack(n, pos + 1, visited, count);
            // 将数字从当前位置移除，并将visited数组对应的位置设为false
            visited[i] = false;
        }
    }
}

// 主函数
int main() {
    // 输入n
    int n;
    cin >> n;
    // 初始化visited数组和count变量
    vector<bool> visited(n + 1, false);
    int count = 0;
    // 调用回溯法函数
    backtrack(n, 1, visited, count);
    // 输出结果
    cout << "优美排列 的 数量 是 " << count << endl;
    return 0;
}
```
