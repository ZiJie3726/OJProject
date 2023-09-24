//
// Created by MCZJ3 on 9/13/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Way(vector<int> &arr, int &n, int &k) {
  sort(arr.begin(), arr.end());
  for (int i = 0; i < k; ++i) {
	cout << arr[i] << " ";
  }
}

int main() {
  int NumsLength;
  int k;
  vector<int> arr;
  cin >> NumsLength;
  cin >> k;
  for (int i = 0; i < NumsLength; ++i) {
	int temp;
	cin >> temp;
	arr.push_back(temp);
  }
  LookingForSmall(arr, NumsLength, k);
};
