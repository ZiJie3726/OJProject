#include <iostream>
#include <vector>

using namespace std;

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
