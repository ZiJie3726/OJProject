# Problem P13. [算法课贪婪]三角形的最大周长

![picture 0](.assets_IMG/Problem%20P13.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%B4%AA%E5%A9%AA%5D%E4%B8%89%E8%A7%92%E5%BD%A2%E7%9A%84%E6%9C%80%E5%A4%A7%E5%91%A8%E9%95%BF/IMG_20231011-092255.png)  

![picture 1](.assets_IMG/Problem%20P13.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E8%B4%AA%E5%A9%AA%5D%E4%B8%89%E8%A7%92%E5%BD%A2%E7%9A%84%E6%9C%80%E5%A4%A7%E5%91%A8%E9%95%BF/IMG_20231011-092313.png)  

贪婪法：

>因为事先经过降序排序，若是第i+1和第i+2个数小于第i个数导致无法构成三角形，那之后的数相加更不可能大于i，所以不可能出现最大周长出现在A[i], A[i+2], A[i+3]之类的情况

```c
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestPerimeter(vector<int> &A) {
    sort(A.rbegin(), A.rend()); // 降序排序数组

    for (int i = 0; i < A.size() - 2; i++) {
        if (A[i] < A[i + 1] + A[i + 2]) {
            // 找到了三个可以组成三角形的边，返回它们的周长
            return A[i] + A[i + 1] + A[i + 2];
        }
    }

    // 没有找到满足条件的三角形，返回0
    return 0;
}

int main() {
    vector<int> A;
    int temp;
    while (cin >> temp) {
        A.push_back(temp);
        if (cin.peek() == '\n') {
            break;
        }
    }
    int maxPerimeter = largestPerimeter(A);
    cout << maxPerimeter << endl;
    return 0;
}
```

用三个循环遍历非常的浪费时间：

```c
#include <vector>
#include <algorithm>

using namespace std;

int largestPerimeter(vector<int>& A) {
    sort(A.rbegin(), A.rend()); // 降序排序数组

    int maxPerimeter = 0;

    for (int i = 0; i < A.size() - 2; i++) {
        for (int j = i + 1; j < A.size() - 1; j++) {
            for (int k = j + 1; k < A.size(); k++) {
                if (A[i] < A[j] + A[k]) {
                    // 找到一个满足条件的三角形
                    maxPerimeter = max(maxPerimeter, A[i] + A[j] + A[k]);
                }
            }
        }
    }

    return maxPerimeter;
}
```
