//
// Created by MCZJ3 on 9/13/2023.
//
#include <iostream>
#include <vector>

using namespace std;

int LookingForSmall(vector<int> &a, int &n) {
  int sum = 0;
  for (int i = 0; i < a.size(); ++i) {
	int tempsum = 0;
	for (int j = i; j < a.size(); ++j) {
	  tempsum = tempsum + a[j];
	  if (tempsum > sum) {
		sum = tempsum;
	  }
	}
  }
  return sum;
}

int main() {
  int NumsLength;
  vector<int> nums;
  int temp;
  cin >> NumsLength;
  while (cin >> temp) {
	nums.push_back(temp);
	if (cin.peek() == '\n') {
	  break;
	}
  }
  cout << LookingForBiggest(nums, NumsLength);
};
