#include <iostream>
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
