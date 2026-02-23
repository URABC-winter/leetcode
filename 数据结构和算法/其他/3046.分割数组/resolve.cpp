class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int num[105]; 
        for(int i=0;i<nums.size();i++){
            num[nums[i]]++;
            if(num[nums[i]]>=3){
                return false;
            }
        }
        return true;
    }
};
