# Problem P12. [算法课贪婪]6和9组成的最大数字

![picture 0](.assets_IMG/Problem%20P12.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%B4%AA%E5%A9%AA%5D6%E5%92%8C9%E7%BB%84%E6%88%90%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E5%AD%97/IMG_20231011-090025.png)

![picture 2](.assets_IMG/Problem%20P12.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%B4%AA%E5%A9%AA%5D6%E5%92%8C9%E7%BB%84%E6%88%90%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E5%AD%97/IMG_20231011-090156.png)  

## answer

```c
#include <iostream>

using namespace std;

void trans(int num) {
    string num_str = to_string(num);
    for (char & i : num_str) {
        if (i == '6'){
            i = '9';
            break;
        }
    }
    cout << num_str;
}

int main() {
    int num;
    cin >> num;
    trans(num);
}
```

## note

字符串的for循环里面

```c
for (int i = 0; i < num_str.size(); ++i) {
        if (num_str[i] == '6'){
            num_str[i] = '9';
            break;
        }
    }
```

可以换成

```c
for (char & i : num_str) {
        if (i == '6'){
            i = '9';
            break;
        }
    }
```
