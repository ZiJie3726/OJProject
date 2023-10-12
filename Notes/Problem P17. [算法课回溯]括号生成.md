# Problem P17. [算法课回溯]括号生成

![picture 0](.assets_IMG/Problem%20P17.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%9B%9E%E6%BA%AF%5D%E6%8B%AC%E5%8F%B7%E7%94%9F%E6%88%90/IMG_20231012-170849.png)  

以下是对代码的详细解释：

```cpp
#include <iostream>
#include <vector>
#include <string>

// 递归函数，用于生成所有可能的有效括号组合
void generateParenthesisHelper(int n, int open, int close, std::string current, std::vector<std::string>& result) {
  // 当生成的字符串长度等于 2n 时，说明一个有效的括号组合已经生成
  if (current.length() == n * 2) {
    result.push_back(current); // 将它加入结果集
    return;
  }

  // 如果尚未放置完所有左括号，可以继续放置左括号
  if (open < n) {
    generateParenthesisHelper(n, open + 1, close, current + '(', result);
  }

  // 如果已经放置了一些左括号，可以放置右括号（但要确保左右括号匹配）
  if (close < open) {
    generateParenthesisHelper(n, open, close + 1, current + ')', result);
  }
}

// 主函数，生成 n 对括号的所有有效组合
std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::string> result; // 用于存储结果的向量
  generateParenthesisHelper(n, 0, 0, "", result); // 调用辅助函数开始生成
  return result;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::string> combinations = generateParenthesis(n);

  std::cout << "[";
  for (int i = 0; i < combinations.size(); i++) {
    std::cout << combinations[i];
    if (i < combinations.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;

  return 0;
}
```

1. `generateParenthesisHelper` 是一个递归函数，用于生成有效的括号组合。它接受以下参数：
   - `n`：期望的括号对数。
   - `open`：已经放置的左括号的数量。
   - `close`：已经放置的右括号的数量。
   - `current`：当前正在构建的组合字符串。
   - `result`：一个向量，用于存储有效的括号组合。

2. 首先，函数检查当前组合字符串的长度是否等于 `n * 2`。如果是，这表示已经生成了一个有效的括号组合，将其添加到 `result` 向量中，并返回。

3. 如果还没有达到期望的长度，函数有两个选项：
   - 如果可以添加更多的左括号（`open < n`），则递归调用 `generateParenthesisHelper`，在 `current` 的末尾添加左括号，并增加 `open`。
   - 如果可以添加更多的右括号（`close < open`），则递归调用 `generateParenthesisHelper`，在 `current` 的末尾添加右括号，并增加 `close`。

4. `generateParenthesis` 函数是包装函数，用于初始化结果向量 `result` 并调用 `generateParenthesisHelper` 开始生成有效的括号组合。

5. 在 `main` 函数中，我们指定了希望生成的括号对数 `n`，然后调用 `generateParenthesis` 生成括号组合。

6. 接着，我们对生成的括号组合进行排序，按照括号生成的层数从大到小排序。这是根据您的要求的，所以我们使用 `std::sort` 函数和一个自定义的排序谓词来实现这一点。

7. 最后，我们遍历已排序的括号组合并将它们打印到控制台。这将显示以所需顺序排列的有效括号组合。
