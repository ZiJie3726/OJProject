# Problem P23. 计数排序（使用C/C++）

![picture 0](.assets_IMG/Problem%20P23.%20%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F%EF%BC%88%E4%BD%BF%E7%94%A8CC%2B%2B%EF%BC%89/IMG_20231017-211033.png)  

```cpp
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const long long MOD = 1000000007;  // 1e9 + 7

void countingSort(vector<int>& a, int n, int m) {
  vector<int> count(m + 1, 0);// 创建一个用于计数的数组，大小为 m+1，下标从1到m
  vector<int> b(n + 1);// 创建一个用于存储排序结果的数组

  // 计算每个元素出现的次数
  for (int i = 1; i <= n; i++) {
	count[a[i]]++;
  }

  // 计算每个元素应该在排序后的位置
  for (int i = 1; i <= m; i++) {
	count[i] += count[i - 1];
  }

  // 构造排序后的数组 b
  // 这里从后往前遍历原始数组 a，保证稳定性
  for (int i = n; i >= 1; i--) {
	b[count[a[i]]] = a[i];
	count[a[i]]--;
  }

  // 将排序后的结果复制回原始数组 a
  for (int i = 1; i <= n; i++) {
	a[i] = b[i];
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);// 从标准输入中读取 n 和 m，提高输入效率
  vector<int> a(n + 1);// 数组大小扩展到 n+1，以适应从1开始的下标

  for (int i = 1; i <= n; i++) {
	scanf("%d", &a[i]);// 从标准输入中读取数组数据
  }

  countingSort(a, n, m);// 调用计数排序函数

  long long sum = 0;  // 用于存储相加的结果
// 计算从1到n的每个 b[i] 与 i 的乘积相加，然后再对 MOD 取余
  for (int i = 1; i <= n; i++) {
	sum = (sum + static_cast<long long>(a[i]) * i) % MOD;
  }

  cout << sum << endl;  // 输出求余的结果

  return 0;
}
```

以下是对上面代码的详细分析和讲解：

1. 引入头文件：
   ```cpp
   #include <iostream>
   #include <vector>
   #include <cstdio>
   ```
   这些头文件包括了C++标准输入输出库和用于向程序中输入和输出数据的`<cstdio>`头文件。

2. 常量定义：
   ```cpp
   const long long MOD = 1000000007;  // 1e9 + 7
   ```
   这里定义了一个常量 `MOD` 用于存储取余的值，以便在计算过程中使用。

3. 计数排序函数 `countingSort`：
   这个函数执行计数排序。它接受一个整数数组 `a`，数组大小 `n`，以及最大元素值 `m` 作为参数。

   - 创建一个 `count` 数组，大小为 `m+1`，用于存储每个元素的计数。
   - 创建一个 `b` 数组，大小为 `n+1`，用于存储排序后的结果。
   - 遍历原始数组 `a`，计算每个元素的出现次数，存储在 `count` 中。
   - 计算每个元素应该在排序后的位置，更新 `count`。
   - 使用 `count` 数组构建排序后的数组 `b`。
   - 最后，将排序后的结果复制回原始数组 `a`。

4. `main` 函数：
   - 声明整数变量 `n` 和 `m`，并使用 `scanf` 从标准输入中读取它们。这允许更快的输入操作。
   - 创建一个整数数组 `a`，大小为 `n+1`，以存储输入的数据。注意，这里数组大小扩展到 `n+1`，以适应从1开始的下标。
   - 使用 `scanf` 从标准输入中读取 `n` 个整数，将它们存储在数组 `a` 中。
   - 调用 `countingSort` 函数对数组 `a` 进行计数排序。
   - 创建一个长整数变量 `sum`，用于存储从1到n的每个 `a[i] * i` 相加的结果，每次相加后都对 `MOD` 取余。
   - 遍历排序后的数组 `a`，计算 `a[i] * i`，将其与 `sum` 相加，并在每次相加后都对 `MOD` 取余。
   - 最后，输出计算后的 `sum`，即从1到n的每个 `a[i] * i` 相加后取余的结果。

这个代码对大数据输入做了一些优化，使用 `scanf` 提高输入效率，并使用动态内存分配来处理大数组，以防止栈溢出。它还对每一步都进行了详细的注释，以便更好地理解代码的功能。
