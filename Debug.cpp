#include <iostream>
#include <vector>

using namespace std;

int MostWater(vector<int> &num) {
    int s = 0;
    int ans = 0;
    for (int i = 0; i < num.size(); ++i) {
        for (int j = num.size() - 1; j > i; --j) {
            if (num[i] > num[j]) {
                if (num[j] * (j - i) > s) {
                    s = num[j] * (j - i);
                }
            } else {
                if (num[i] * (j - i) > s) {
                    s = num[i] * (j - i);
                }
            }
            if (s > ans)
                ans = s;
        }
    }
    return ans;
}

int main() {
    vector<int> num;
    int temp;
    while (cin >> temp) {
        num.push_back(temp);
        if (cin.peek() == '\n') {
            break;
        }
    }
    cout << MostWater(num);
    return 0;
}
