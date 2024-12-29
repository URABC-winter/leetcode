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
//	// ����һ�� pair ���飬����ֵ�����ǵ�����
//    std::vector<std::pair<int, char>> indexedArr;
//    for (int i = 0; i < 26; ++i) {
//        if (nums[i] != 0) { // ���˵�ֵΪ0��Ԫ��
//            indexedArr.push_back({nums[i], i+65});
//        }
//    }
//
//    // ���� pair �ĵ�һ��Ԫ�أ���ֵ����������
//    std::sort(indexedArr.begin(), indexedArr.end(), [](const std::pair<int, char>& a, const std::pair<int, char>& b) {
//        return a.first < b.first;
//    });
//
//    // ���������ֵ�Ͷ�Ӧ��ԭʼ���к�
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
                return nums[a - 'A'][i] < nums[b - 'A'][i]; // ע�������� <
            }
        }
        return a < b; // ��������еļ�������ͬ������Ϊ����Ԫ�����
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


