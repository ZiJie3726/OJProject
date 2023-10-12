# Problem P15. [算法课贪婪]移掉 K 位数字

给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

- 1 <= k <= num.length <= 1000
- num 仅由若干位数字（0 - 9）组成
- 除了 0 本身之外，num 不含任何前导零

![picture 0](.assets_IMG/Problem%20P15.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%B4%AA%E5%A9%AA%5D%E7%A7%BB%E6%8E%89%20K%20%E4%BD%8D%E6%95%B0%E5%AD%97/IMG_20231011-153146.png)  

下面是给定C++代码的逐行解释和演示：

```cpp
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 定义一个函数，用于移除k个数字以得到最小的数字字符串
string removeKDigits(string num, int k) {
    // 创建一个字符栈，用于构建最小的数字字符串
    stack<char> s;
    
    // 遍历字符串num中的每个数字字符
    for (char digit : num) {
        // 如果栈不为空，k大于0，且当前数字比栈顶小
        while (!s.empty() && k > 0 && digit < s.top()) {
            // 弹出栈顶元素以确保新的数字字符的位置是最优的
            s.pop();
            k--;
        }
        // 将当前数字字符压入栈中
        s.push(digit);
    }
    
    // 如果k仍大于0，继续从栈中弹出元素以满足移除k个数字的要求
    while (k > 0) {
        s.pop();
        k--;
    }
    
    // 构建最终结果字符串
    string result = "";
    while (!s.empty()) {
        result = s.top() + result; // 栈的元素逆序排列
        s.pop();
    }
    
    // 移除结果字符串的前导零
    int i = 0;
    while (i < result.length() && result[i] == '0') {
        i++;
    }
    result = result.substr(i);
    
    // 如果结果字符串为空，返回 "0"
    if (result.empty()) {
        return "0";
    }
    
    return result;
}

int main() {
    string input;
    int k;
    cin >> input >> k;

    // 调用removeKDigits函数来移除数字并得到最小的数字字符串
    string result = removeKDigits(input, k);
    cout << result << endl;

    return 0;
}
```

此代码的主要工作如下：

1. 我们首先创建一个字符栈（stack），该栈用于构建最小的数字字符串。

2. 在`removeKDigits`函数中，我们遍历输入字符串 `num` 中的每个数字字符。

3. 对于每个数字字符，我们考虑了几种情况：
   - 如果栈不为空，且 `k` 大于零，并且当前数字字符比栈顶元素小，我们弹出栈顶元素，以确保新的数字字符的位置是最优的。这一步骤会持续进行，直到不再满足这个条件。这是贪心策略的关键部分。
   - 然后，将当前数字字符压入栈中。

4. 在遍历完成后，如果 `k` 仍大于零，我们需要继续从栈中弹出元素，以满足移除 `k` 个数字的要求。

5. 我们构建最终的结果字符串，将栈中的元素按顺序从栈顶到栈底取出，然后逆序排列，以得到最小的数字字符串。

6. 接下来，我们去除结果字符串的前导零，以确保结果是一个合法的数字。

7. 最后，如果结果字符串为空，表示移除数字后为空字符串，我们返回 "0" 作为最小的数字。

在 `main` 函数中，我们从标准输入读取输入字符串 `input` 和整数 `k`，然后调用 `removeKDigits` 函数来处理输入并输出最小的数字字符串。
