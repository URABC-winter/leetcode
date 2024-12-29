#include<bits/stdc++.h>
using namespace std;

//string rankTeams(vector<string>& votes) {
//    int nums[30];
//    string result;
//    for(int i=0;i<30;i++){
//    	nums[i]=0;
//	}
//    for(int i=0;i<votes.size();i++){
//        for(int j=0;j<votes[i].size();j++){
//            int num = votes[i][j] - 'A';
//            nums[num] += (j+1);
//        }
//    }
//    for(int i=0;i<26;i++){
//    	cout<<nums[i]<<" ";
//	}
//	cout<<endl;
//	
//	// 创建一个 pair 数组，包含值和它们的索引
//    std::vector<std::pair<int, char>> indexedArr;
//    for (int i = 0; i < 26; ++i) {
//        if (nums[i] != 0) { // 过滤掉值为0的元素
//            indexedArr.push_back({nums[i], i+65});
//        }
//    }
//
//    // 根据 pair 的第一个元素（即值）进行排序
//    std::sort(indexedArr.begin(), indexedArr.end(), [](const std::pair<int, char>& a, const std::pair<int, char>& b) {
//        return a.first < b.first;
//    });
//
//    // 输出排序后的值和对应的原始序列号
//    for (const auto& p : indexedArr) {
//    	result += p.second;
//        std::cout << "Value: " << p.first << ", Original Index: " << p.second << std::endl;
//    }
//	
//    return result;
//}

string rankTeams(vector<string>& votes) {
    int nums[27][27];
    for(int i=0;i<26;i++){
    	for(int j=0;j<26;j++){
    		nums[i][j] = 0;
		}
	}
    for(const string& str : votes) {
    	for(int i=0;i<str.size();i++){
    		int letter = str[i] - 'A';
    		nums[letter][i]--;
		}
	}
	
	string result = votes[0];
	std::sort(result.begin(), result.end(), [&](char a, char b) {
        for (int i = 0; i < 26; i++) {
            if (nums[a - 'A'][i] != nums[b - 'A'][i]) {
                return nums[a - 'A'][i] < nums[b - 'A'][i]; // 注意这里是 <
            }
        }
        return a < b; // 如果所有列的计数都相同，则认为两个元素相等
    });
   
    return result;
}
int main(){
	vector<string> votes;
	votes = {"FVSHJIEMNGYPTQOURLWCZKAX","AITFQORCEHPVJMXGKSLNZWUY","OTERVXFZUMHNIYSCQAWGPKJL","VMSERIJYLZNWCPQTOKFUHAXG","VNHOZWKQCEFYPSGLAMXJIUTR","ANPHQIJMXCWOSKTYGULFVERZ","RFYUXJEWCKQOMGATHZVILNSP","SCPYUMQJTVEXKRNLIOWGHAFZ","VIKTSJCEYQGLOMPZWAHFXURN","SVJICLXKHQZTFWNPYRGMEUAO","JRCTHYKIGSXPOZLUQAVNEWFM","NGMSWJITREHFZVQCUKXYAPOL","WUXJOQKGNSYLHEZAFIPMRCVT","PKYQIOLXFCRGHZNAMJVUTWES","FERSGNMJVZXWAYLIKCPUQHTO","HPLRIUQMTSGYJVAXWNOCZEKF","JUVWPTEGCOFYSKXNRMHQALIZ","MWPIAZCNSLEYRTHFKQXUOVGJ","EZXLUNFVCMORSIWKTYHJAQPG","HRQNLTKJFIEGMCSXAZPYOVUW","LOHXVYGWRIJMCPSQENUAKTZF","XKUTWPRGHOAQFLVYMJSNEIZC","WTCRQMVKPHOSLGAXZUEFYNJI"};
	//votes = {"WXYZ","XYZW"};
	string str = rankTeams(votes);
	cout<<str<<endl;
}


