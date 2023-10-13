# Problem P09. [算法课动态规划]最长回文子串

![picture 0](.assets_IMG/Problem%20P09.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%5D%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2/IMG_20231013-103710.png)

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
  int n = s.length();
  if (n <= 1) {
    return s; // 如果字符串长度为0或1，它本身就是回文
  }

  vector<vector<bool>> isPalindrome(n, vector<bool>(n, false)); // 创建一个二维布尔矩阵用于存储回文子串信息
  int start = 0; // 记录最长回文子串的起始位置
  int maxLen = 1; // 记录最长回文子串的长度

  // 初始化矩阵：所有长度为1的子串都是回文
  for (int i = 0; i < n; i++) {
    isPalindrome[i][i] = true;
  }

  // 检查所有长度为2的子串是否是回文
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      isPalindrome[i][i + 1] = true;
      start = i;
      maxLen = 2;
    }
  }

  // 从长度3开始检查更长的回文子串
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
        isPalindrome[i][j] = true;
        if (len > maxLen) {
          start = i;
          maxLen = len;
        }
      }
    }
  }

  return s.substr(start, maxLen); // 返回最长回文子串
}

int main() {
  string input;
  cin >> input; // 从标准输入读取输入字符串

  string result = longestPalindrome(input); // 调用函数计算最长回文子串
  cout << result << endl; // 输出最长回文子串

  return 0;
}
```

代码的执行过程如下：

1. 引入必要的头文件，包括iostream（用于输入和输出）、string（用于处理字符串）和vector（用于创建二维矩阵）。

2. 在 `main` 函数中，从标准输入读取一个字符串 `input`，这个字符串是待检测的字符串。

3. 调用 `longestPalindrome` 函数，将 `input` 作为参数传递给它。

4. 在 `longestPalindrome` 函数中，首先获取字符串的长度 `n`。如果 `n` 小于等于 1，直接返回字符串本身，因为在这种情况下，它本身就是回文。

5. 创建一个二维布尔矩阵 `isPalindrome`，大小为 n x n，用于存储回文子串的信息。

6. 初始化矩阵：所有长度为1的子串都是回文，所以对角线上的元素都设置为 `true`。

7. 检查所有长度为2的子串是否是回文，如果是，将对应的矩阵元素设置为 `true`。

8. 从长度3开始，使用双重循环检查更长的回文子串。如果某个子串是回文，就将相应的矩阵元素设置为 `true`。

9. 同时，如果当前回文子串的长度大于之前记录的最长回文子串长度 `maxLen`，则更新 `start` 和 `maxLen`，以便记录最长回文子串的起始位置和长度。

10. 最后，函数返回通过 `s.substr(start, maxLen)` 获取的最长回文子串。

11. 在 `main` 函数中，将计算得到的最长回文子串输出到标准输出。

这个程序演示了如何使用动态规划方法来查找给定字符串中的最长回文子串。