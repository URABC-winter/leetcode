## 记录
### 解题
1. **长度检查**：若两个字符串长度不等，则不可能同构，直接返回 `false`。
2. **双向哈希映射**：
   - 使用 `unordered_map<char, char>` 分别记录从 `s` 到 `t` 的映射 `s2t`和从 `t` 到 `s` 的映射 `t2s`。</br>
    举例：add和egg，则s2t为{a->e, b->g}，t2s为{e->a, g->b}
   - 遍历字符串的每个位置 `i`：
     - 若 `s[i]` 已在 `s2t` 中存在映射，则检查其映射值是否等于 `t[i]`，若不相等则返回 `false`。
     - 若 `s[i]` 不存在映射，则先检查 `t[i]` 是否已在 `t2s` 中存在映射（即是否已被其他 `s` 字符映射），若存在则说明产生冲突，返回 `false`。
     - 否则，建立双向映射：`s2t[s[i]] = t[i]` 且 `t2s[t[i]] = s[i]`。
3. **遍历完成**：若所有字符均满足一一对应关系，返回 `true`。

### 代码
```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < s.size(); i++) {
            char sc = s[i];
            char tc = t[i];

            auto it_s = s2t.find(sc);
            if (it_s != s2t.end()) {
                if (it_s->second != tc) return false;
            } else {
                auto it_t = t2s.find(tc);
                if (it_t != t2s.end()) {
                    if (it_t->second != sc) return false;
                }

                s2t[sc] = tc;
                t2s[tc] = sc;
            }
        }
        return true;
    }
};