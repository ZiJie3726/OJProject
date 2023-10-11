# Problem P14. [算法课蛮力法]种花问题

![picture 0](.assets_IMG/Problem%20P14.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%9B%AE%E5%8A%9B%E6%B3%95%5D%E7%A7%8D%E8%8A%B1%E9%97%AE%E9%A2%98/IMG_20231011-103958.png)  

```c
#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int count = 0;
    flowerbed.insert(flowerbed.begin(), 0);//在首尾加入0方便比较
    flowerbed.insert(flowerbed.end(), 0);
    for (int i = 1; i < flowerbed.size() - 1; ++i) {
        if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            count++;
        }
    }
    return n <= count;
}

int main() {
    vector<int> flowerbed;
    int temp, n;
    while (cin >> temp) {
        flowerbed.push_back(temp);
        if (cin.peek() == '\n') {
            break;
        }
    }
    cin >> n;
    if (canPlaceFlowers(flowerbed, n)) {
        cout << "ture";
    } else
        cout << "false";
    return 0;
}
```
