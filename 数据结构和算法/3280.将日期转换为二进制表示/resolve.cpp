#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordsCount = words.size();
        int totalLen = wordLen * wordsCount;
        int n = s.size();
        if (n < totalLen) return result;

        unordered_map<string, int> need;
        for (const auto& w : words) {
            need[w]++;
        }

        for (int start = 0; start < wordLen; ++start) {
            int left = start, right = start;
            unordered_map<string, int> window;
            int matched = 0;

            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (need.count(word)) {
                    window[word]++;
                    if (window[word] == need[word]) {
                        matched++;
                    }
                }

                while ((right - left) / wordLen > wordsCount) {
                    string leftWord = s.substr(left, wordLen);
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
};

int main() {
    Solution sol;

    // 测试用例1
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> res1 = sol.findSubstring(s1, words1);
    cout << "Test case 1: [";
    for (size_t i = 0; i < res1.size(); ++i) {
        cout << res1[i];
        if (i != res1.size() - 1) cout << ",";
    }
    cout << "]" << endl;   // 预期输出 [0,9]

    // 测试用例2
    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word","good","best","word"};
    vector<int> res2 = sol.findSubstring(s2, words2);
    cout << "Test case 2: [";
    for (size_t i = 0; i < res2.size(); ++i) {
        cout << res2[i];
        if (i != res2.size() - 1) cout << ",";
    }
    cout << "]" << endl;   // 预期输出 []

    // 测试用例3
    string s3 = "barfoofoobarthefoobarman";
    vector<string> words3 = {"bar","foo","the"};
    vector<int> res3 = sol.findSubstring(s3, words3);
    cout << "Test case 3: [";
    for (size_t i = 0; i < res3.size(); ++i) {
        cout << res3[i];
        if (i != res3.size() - 1) cout << ",";
    }
    cout << "]" << endl;   // 预期输出 [6,9,12]

    return 0;
}