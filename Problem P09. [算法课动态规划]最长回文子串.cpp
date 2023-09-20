//
// Created by MCZJ3 on 9/14/2023.
//
#include <iostream>
#include <vector>

void CycleChar(std::vector<char> &s) {
  int jug = -1;
  int jug2 = -1;
  int mid = 0;
  int start = -1;
  int end = -2;
  for (int i = 0; i <= s.size(); ++i) {
	for (int j = s.size() - 1; j >= i; --j) {
	  if (s[i] == s[j]) {
		if (i != j) {
		  if ((jug != i - 1 && jug2 != j + 1) || jug == -1) {
			jug = i;
			jug2 = j;
			start = i;
			end = j;
		  } else {
			jug = i;
			jug2 = j;
		  }
		} else {
		  mid = i;
		}
	  }
	}
  }
  if (start == -1 && end == -2) {
	std::cout << s[0];
  } else {
	for (int i = start; i < end + 1; ++i) {
	  std::cout << s[i];
	}
  }
}
int main() {
  std::vector<char> s;
  char temp;
  while (std::cin >> temp) {
	s.push_back(temp);
	if (std::cin.peek() == '\n')
	  break;
  }
  CycleChar(s);
}

/*#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int start = 0; // 用于记录最长回文子串的起始位置
    int end = 0;   // 用于记录最长回文子串的结束位置

    for (int i = 0; i < s.length(); i++) {
        // 以当前字符为中心向两边扩展
        int len1 = expandAroundCenter(s, i, i);
        // 以当前字符和下一个字符的中间为中心向两边扩展
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);

        if (len > (end - start)) {
            // 如果找到更长的回文子串，更新start和end
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return s.substr(start, end - start + 1);
}

int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

int main() {
    string input;
    cout << "请输入一个字符串: ";
    cin >> input;

    string result = longestPalindrome(input);
    cout << "最长回文子串是: " << result << endl;

    return 0;
}
//这个程序首先定义了一个 longestPalindrome 函数，它使用中心扩展法来找到最长回文子串。
 //然后，在 main 函数中，用户被要求输入一个字符串，然后调用 longestPalindrome 函数来查找并打印最长回文子串。
*/

/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if (n <= 1) {
        return s; // 字符串长度为0或1时，本身就是回文
    }

    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    int start = 0; // 记录最长回文子串的起始位置
    int maxLen = 1; // 记录最长回文子串的长度

    // 所有长度为1的子串都是回文
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

    return s.substr(start, maxLen);
}

int main() {
    string input;
    cout << "请输入一个字符串: ";
    cin >> input;

    string result = longestPalindrome(input);
    cout << "最长回文子串是: " << result << endl;

    return 0;
}
//这个代码片段中，我们使用一个二维布尔数组 isPalindrome 来记录字符串中不同位置的子串是否是回文。
 //然后，我们从长度为1的子串开始，逐渐增加子串的长度，检查是否是回文，并在找到更长的回文子串时更新 start 和 maxLen。最后，返回最长回文子串。
 */
