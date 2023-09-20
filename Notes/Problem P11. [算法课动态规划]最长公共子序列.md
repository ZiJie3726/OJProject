# Problem P11. [算法课动态规划]最长公共子序列

![picture 0](.assets_IMG/Problem%20P11.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%5D%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97/IMG_20230920-155915.png)  

```cpp
void longer(vector<char> &s1, vector<char> &s2) {
    int sum = 0;
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = i; j < s2.size(); ++j) {
            if (s1[i] == s2[j]) {
                sum++;
                break;
            }
        }
    }
    cout << sum;
}

int main() {
    vector<char> s1, s2;
    char temp;
    while (cin >> temp) {
        s1.push_back(temp);
        if (cin.peek() == ' ') {
            break;
        }
    }
    while (cin >> temp) {
        s2.push_back(temp);
        if (cin.peek() == '\n') {
            break;
        }
    }
    if (s1.size() > s2.size())
        longer(s2, s1);
    else
        longer(s1, s2);
}
```
