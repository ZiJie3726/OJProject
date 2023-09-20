#include <iostream>

using namespace std;

void Maxsum(int n[], int length) {
  int sum = 0;
  int sumin = 0;
  int sumout = 0;
  for (int i = 0; i < length; ++i) {
    for (int j = i; j < length; ++j) {
      sum = sum + n[j];
      if (sum > sumout)
        sumout = sum;
    }
    if (sumout > sumin)
      sumin = sumout;
    sumout = 0;
    sum = 0;
  }
  std::cout << sumin;
}
int main() {
  int length;
  std::cin >> length;
  int n[length];
  for (int i = 0; i < length; ++i) {
    std::cin >> n[i];
  }
  Maxsum(n, length);
  return 0;
}
