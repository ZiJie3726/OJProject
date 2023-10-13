# Problem P02. [算法课分治] 寻找多数

![picture 0](.assets_IMG/Problem%20P02.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%88%86%E6%B2%BB%5D%20%E5%AF%BB%E6%89%BE%E5%A4%9A%E6%95%B0/IMG_20231013-084509.png)  

![picture 1](.assets_IMG/Problem%20P02.%20%5B%E7%AE%97%E6%B3%95%E8%AF%BE%E5%88%86%E6%B2%BB%5D%20%E5%AF%BB%E6%89%BE%E5%A4%9A%E6%95%B0/IMG_20231013-084645.png)  

这段C++代码是一个程序，用于查找一个整数向量（vector）中出现次数超过一半的元素（也就是出现频率最高的元素）。以下是对代码的详细解释：

```cpp
#include <iostream>
#include <vector>

int LookingForMost(std::vector<int> &a, int &n) {
    int most = -1;  // 初始化most为-1（表示没有元素）
    
    for (int i = 0; i < a.size(); ++i) {
        int sum = 0;
        
        for (int j = i; j < a.size(); ++j) {
            if (a[i] == a[j])
                sum++;
            
            if (sum > n / 2) {
                most = a[i];  // 如果一个元素出现次数超过n/2，它成为出现频率最高的元素
                return most;
            }
        }
    }
    
    return most;  // 返回出现频率最高的元素（或者-1，如果没有找到）
}

int main() {
    int n;
    std::vector<int> a;
    int aa;
    
    std::cin >> n;
    
    while (std::cin >> aa) {
        a.push_back(aa);
        if (std::cin.peek() == '\n') {
            break;
        }
    }
    
    int result = LookingForMost(a, n);
    std::cout << result << std::endl;
    return 0;
}
```

解释：

1. 代码开始包含了必要的头文件，用于输入/输出和向量操作。

2. 定义了一个名为`LookingForMost`的函数，该函数接受一个整数向量`a`的引用和一个整数`n`作为输入。这个函数旨在查找向量`a`中出现频率最高的元素，但它存在一些问题，如下所述。

3. 在`LookingForMost`函数内，变量`most`初始化为-1，表示尚未找到出现频率最高的元素。

4. 通过两个嵌套循环来遍历向量`a`中的元素。外部循环遍历向量中的每个元素。

5. 内部循环统计向量中位置`i`的元素出现的次数。

6. 如果一个元素出现次数超过`n / 2`次，它被认为是出现频率最高的元素，并且`most`变量将设置为该元素。然后函数返回`most`元素。

7. 在`main`函数中，从标准输入（通常是键盘）读取一个整数`n`和一系列整数，然后将它们存储在向量`a`中。输入过程在遇到换行字符时停止。

8. 读取输入后，调用`LookingForMost`函数并打印结果，结果是出现频率最高的元素，如果没有找到则打印-1。

请注意，代码中存在一个函数名称不匹配的问题（函数定义中的函数名为"LookingForMost"，而函数调用中使用了"LookingForSmall"），并且代码存在一些需要纠正的问题，以使其按预期工作。
