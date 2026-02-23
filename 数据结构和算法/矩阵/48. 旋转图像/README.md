## 记录
### 解题
1. **转置矩阵**：遍历矩阵的上三角部分（避免重复交换），将 matrix[i][j] 与 matrix[j][i] 互换，得到矩阵的转置。

2. **反转每一行**：对每一行的元素进行反转，即第 i 行的第 j 个元素与第 n-1-j 个元素交换。**（左右翻转）**

3. 以上操作可以仅以对角线为准操作一半矩形。

### 代码
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 转置
        for (int i=0;i<n;i++) {
            for (int j=i;j<n;j++) {
                int staging = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = staging;
            }
        }

        // 左右翻转（水平翻转）
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
    }
};
```