# Problem P01. [算法课分治] 最大二叉树

![picture 2](.assets_IMG/Problem%20P01/IMG_20230920-095951.png)  

![picture 4](.assets_IMG/Problem%20P01/IMG_20230920-101333.png)

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        // 找到数组中的最大值和对应的索引
        int maxVal = nums[0];
        int maxIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIndex = i;
            }
        }

        // 创建根节点
        TreeNode* root = new TreeNode(maxVal);

        // 递归构建左子树和右子树
        std::vector<int> leftSubArray(nums.begin(), nums.begin() + maxIndex);
        std::vector<int> rightSubArray(nums.begin() + maxIndex + 1, nums.end());
        root->left = constructMaximumBinaryTree(leftSubArray);
        root->right = constructMaximumBinaryTree(rightSubArray);

        return root;
    }
};

// 辅助函数，以字符串形式输出二叉树
std::string serialize(TreeNode* root) {
    if (!root) {
        return "null";
    }

    std::string leftSerialized = serialize(root->left);
    std::string rightSerialized = serialize(root->right);

    // 如果左子树和右子树都为"null"，则返回根节点的值
    if (leftSerialized == "null" && rightSerialized == "null") {
        return std::to_string(root->val);
    }

    // 否则，返回包含根节点值、左子树和右子树的完整字符串
    return std::to_string(root->val) + " " + leftSerialized + " " + rightSerialized;
}

int main() {
    Solution solution;
    std::vector<int> nums;
    int num;

    while (true) {
        if (std::cin.peek() == '\n') {
            break;
        }
        std::cin >> num;
        nums.push_back(num);
    }

    TreeNode* root = solution.constructMaximumBinaryTree(nums);
    std::string result = serialize(root);
    std::cout << result << std::endl; // 输出结果
    return 0;
}

```
