#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
	nums1.erase(nums1.begin()+m,nums1.end());
    for(int i=0;i<n;i++){
        nums1.push_back(nums2[i]);
    }
    for(int i=0;i<n+m-1;i++){
        for(int j=0;j<n+m-1-i;j++){
            if(nums1[j]>nums1[j+1]){
                //cout<<nums1[j]<<" "<<nums1[j+1]<<endl;
                int index = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = index;
            }
        }
    }
}

//leetcode好解法
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
        while (p2 >= 0) { // nums2 还有要合并的元素
            // 如果 p1 < 0，那么走 else 分支，把 nums2 合并到 nums1 中
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--]; // 填入 nums1[p1]
            } else {
                nums1[p--] = nums2[p2--]; // 填入 nums2[p1]
            }
        }
    }
};

int main(){
	vector<int>nums1 = {2,0};
	vector<int>nums2 = {1};
	merge(nums1,1,nums2,1);
	for(int i=0;i<nums1.size();i++){
		cout<<nums1[i]<<" ";
	}
	cout<<endl;
}
