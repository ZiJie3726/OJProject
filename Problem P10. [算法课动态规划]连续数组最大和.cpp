//
// Created by MCZJ3 on 9/14/2023.
//
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
/*#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0; // 如果数组为空，最大和为0
    }

    int maxSum = nums[0]; // 记录全局最大和
    int currentSum = nums[0]; // 记录当前子数组的和

    for (int i = 1; i < n; i++) {
        // 对于每个元素，比较将其添加到当前子数组中的和
        // 与仅以当前元素作为新的子数组的起始来计算的和
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum); // 更新全局最大和
    }

    return maxSum;
}

int main() {
    vector<int> nums;
    int n, num;

    cout << "请输入整数数组的大小: ";
    cin >> n;

    cout << "请输入整数数组的元素: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    int result = maxSubArray(nums);
    cout << "最大子数组的和为: " << result << endl;

    return 0;
}
//这个代码片段中，我们首先定义了一个 maxSubArray 函数，它使用Kadane's算法来查找最大子数组的和。
 //然后，在 main 函数中，用户被要求输入整数数组的大小和元素，然后调用 maxSubArray 函数来查找最大子数组的和并输出它。
//Kadane's算法的关键思想是维护两个变量：maxSum（用于存储全局最大和）和 currentSum（用于存储当前子数组的和）。
 //在遍历数组时，我们始终比较将当前元素添加到当前子数组中的和与仅以当前元素作为新子数组的起始来计算的和，然后更新 currentSum 和 maxSum。
 //这样，我们可以在线性时间内找到最大子数组的和。
 */