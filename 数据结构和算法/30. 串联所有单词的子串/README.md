## 解题思路
### 30-1 解题思路（暴力）
1. 遍历s字符串，查看当前 [r+count, r+count+步长] 是否与words中的字符串相等且第一次匹配。不相等则跳出。
2. 一次遍历对应的发现valid没有报错，则添加r起始位置到结果中。
#### 代码
```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        vector<int> result;
        if (words.empty()) return result;

        int wordsLength = words.size();
        int numLength = words[0].size();
        int totalCount = wordsLength*numLength;
        if (n < totalCount) return result;

        vector<int> used(wordsLength, 0);
        for (int r=0;r<=n-totalCount;r++) {
            fill(used.begin(), used.end(), 0);
            bool valid = true;
            int count = 0;
            while (count < totalCount) {
                string str = s.substr(r+count, numLength);
                int index = findIndex(words, str);
                if (index == -1 || used[index] == 1) {
                    valid = false;
                    break;
                } else {
                    used[index] = 1;
                    count += numLength;
                }
            }
            if (valid == true) {
                result.push_back(r);
            }
        }
        return result;
    }

    int findIndex(const std::vector<std::string>& words, const std::string& target) {
        auto it = std::find(words.begin(), words.end(), target);
        if (it != words.end()) {
            return std::distance(words.begin(), it);  // 计算下标
        }
        return -1;
    }
};
```

#### 错误
1. 发现存在重复单词。

### 30-2 解题思路（暴力优化）
1. 将出现次数改为 unordered_map 哈希表判断单词出现次数，并根据window判断是否有超限情况。

#### 代码
```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        vector<int> result;
        if (words.empty()) return result;

        int wordsLength = words.size();
        int numLength = words[0].size();
        int totalCount = wordsLength*numLength;
        if (n < totalCount) return result;

        // vector<int> used(wordsLength, 0);
        unordered_map<std::string, int> need;
        for (const auto& w : words) {
            need[w]++;
        }

        for (int r=0;r<=n-totalCount;r++) {
            unordered_map<std::string, int> window;
            // fill(used.begin(), used.end(), 0);
            bool valid = true;
            int count = 0;
            while (count < totalCount) {
                string str = s.substr(r+count, numLength);
                // int index = findIndex(words, str);

                if (need.find(str) == need.end()) {
                    valid = false;
                    break;
                }
                window[str]++;
                if (window[str] > need[str]) {
                    valid = false;
                    break;
                }
                count += numLength;

            }
            if (valid == true) {
                result.push_back(r);
            }
        }
        return result;
    }

    // int findIndex(const std::vector<std::string>& words, const std::string& target) {
    //     auto it = std::find(words.begin(), words.end(), target);
    //     if (it != words.end()) {
    //         return std::distance(words.begin(), it);  // 计算下标
    //     }
    //     return -1;
    // }
};
```

#### 错误
1. 超出时间限制

#### 30-3 解题思路（滑动窗口）
1. 划分步长。然后根据步长截取单词，再统计单词出现次数。
2. 如果超出数组词数量，进行提出第一个单词，进行后续单词判断是否符合全部出现。
3. 最后判断单词是否全部出现次数相同数组次数。相同则记录起始位置left。

#### 代码
```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordsCount = words.size();
        int totalLen = wordLen * wordsCount;
        int n = s.size();
        if (n < totalLen) return result;

        std::unordered_map<std::string, int> need;
        for (const auto& w : words) {
            need[w]++;
        }

        for (int start = 0; start < wordLen; ++start) {
            int left = start, right = start;
            std::unordered_map<std::string, int> window;
            int matched = 0;

            while (right + wordLen <= n) {
                std::string word = s.substr(right, wordLen);
                right += wordLen;

                if (need.count(word)) {
                    window[word]++;
                    if (window[word] == need[word]) {
                        matched++;
                    }
                }

                while ((right - left) / wordLen > wordsCount) {
                    std::string leftWord = s.substr(left, wordLen);
                    left += wordLen;
                    if (need.count(leftWord)) {
                        if (window[leftWord] == need[leftWord]) {
                            matched--;
                        }
                        window[leftWord]--;
                    }
                }

                if (matched == need.size() && (right - left) / wordLen == wordsCount) {
                    result.push_back(left);
                }
            }
        }
        return result;
    }

    // int findIndex(const std::vector<std::string>& words, const std::string& target) {
    //     auto it = std::find(words.begin(), words.end(), target);
    //     if (it != words.end()) {
    //         return std::distance(words.begin(), it);  // 计算下标
    //     }
    //     return -1;
    // }
};
```