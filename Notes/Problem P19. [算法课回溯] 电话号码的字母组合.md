# Problem P19. [算法课回溯] 电话号码的字母组合

![picture 0](.assets_IMG/Problem%20P19.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%9B%9E%E6%BA%AF%5D%20%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88/IMG_20231017-124103.png)  

这是一个经典的编程问题，可以用回溯法来解决。回溯法是一种试探性的算法，它在搜索空间中寻找所有可能的解，每次找到一个解后，就将其加入到结果集中，然后回退到上一步，继续搜索其他的解。回溯法的关键是定义好搜索空间和终止条件。

对于这个问题，搜索空间是由数字对应的字母组成的树形结构

终止条件是当遍历完输入字符串的所有数字时，就得到了一个字母组合。为了实现回溯法，我们需要维护一个字符串变量，用来存储当前的字母组合，以及一个结果集变量，用来存储所有的字母组合。我们还需要一个哈希表，用来存储数字到字母的映射关系。

用C++语言实现的代码如下：

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 定义一个哈希表，存储数字到字母的映射关系
unordered_map<char, string> phone = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
};

// 定义一个回溯函数，用来递归地生成字母组合
void backtrack(string& combination, vector<string>& result, const string& digits, int index) {
    // 如果遍历完输入字符串的所有数字，就得到了一个字母组合
    if (index == digits.length()) {
        // 将其加入到结果集中
        result.push_back(combination);
    }
    else {
        // 否则，取出当前数字对应的字母
        char digit = digits[index];
        string letters = phone[digit];
        // 遍历每个字母
        for (char letter : letters) {
            // 将其加入到当前的字母组合中
            combination.push_back(letter);
            // 递归地处理下一个数字
            backtrack(combination, result, digits, index + 1);
            // 回退到上一步，移除最后一个字母
            combination.pop_back();
        }
    }
}

// 定义一个主函数，用来调用回溯函数，并返回结果集
vector<string> letterCombinations(string digits) {
    // 如果输入字符串为空，直接返回空结果集
    if (digits.empty()) {
        return {};
    }
    // 定义一个字符串变量，用来存储当前的字母组合
    string combination;
    // 定义一个结果集变量，用来存储所有的字母组合
    vector<string> result;
    // 调用回溯函数，从第0个数字开始处理
    backtrack(combination, result, digits, 0);
    // 返回结果集
    return result;
}

// 定义一个辅助函数，用来打印结果集
void printResult(vector<string> result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// 测试代码
int main() {
    string digits;
    cin >> digits;
    vector<string> result = letterCombinations(digits);
    printResult(result);
}
```

输入：

`456`

输出：

`[gjm, gjn, gjo, gkm, gkn, gko, glm, gln, glo, hjm, hjn, hjo, hkm, hkn, hko, hlm, hln, hlo, ijm, ijn, ijo, ikm, ikn, iko, ilm, iln, ilo]`

回溯法是一种基于深度优先搜索（DFS）的算法，它可以用来解决一些组合、排列、子集等问题，通常有以下几个步骤：

1. 定义一个全局变量，用来存储最终的结果集。
2. 定义一个局部变量，用来存储当前的解或路径。
3. 定义一个搜索函数，用来递归地遍历搜索空间，并更新结果集和路径。
4. 在搜索函数中，首先判断是否满足终止条件，如果是，则将当前路径加入到结果集中，并返回。
5. 如果不是，则遍历当前节点的所有可能的选择，并对每个选择做以下操作：
    - 将选择加入到当前路径中。
    - 递归地调用搜索函数，进入下一层节点。
    - 将选择从当前路径中移除，回退到上一层节点。
6. 调用搜索函数，从根节点开始搜索。

对于这个问题，我们可以将输入字符串看作是一个树形结构，每个数字对应一个节点，每个节点有若干个分支，分别对应该数字能表示的字母。

我们的目标是找到从根节点到叶子节点的所有路径，每条路径就是一个字母组合。因此，我们可以用回溯法来实现这个目标。

具体来说，我们需要做以下几件事：

1. 定义一个全局变量 `result`，用来存储最终的结果集。
2. 定义一个局部变量 `combination`，用来存储当前的字母组合。
3. 定义一个搜索函数 `backtrack`，用来递归地遍历搜索空间，并更新结果集和字母组合。该函数需要接收四个参数：`combination`、`result`、`digits` 和 `index`。其中 `digits` 是输入字符串，`index` 是当前处理的数字的下标。
4. 在搜索函数中，首先判断是否满足终止条件，即 `index == digits.length()`。如果是，则将当前字母组合加入到结果集中，并返回。
5. 如果不是，则取出当前数字对应的字母字符串 `letters`，并遍历每个字母 `letter`。对于每个字母，做以下操作：
    - 将字母加入到当前字母组合中：`combination.push_back(letter)`。
    - 递归地调用搜索函数，进入下一层节点：`backtrack(combination, result, digits, index + 1)`。
    - 将字母从当前字母组合中移除，回退到上一层节点：`combination.pop_back()`。
6. 调用搜索函数，从第0个数字开始搜索：`backtrack(combination, result, digits, 0)`。

这样就可以得到所有可能的字母组合，并存储在结果集中。最后返回结果集即可。
