class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev=0;
        for(auto it : nums){
            if(it>0 && it-prev >= 2){
                return prev+1;
            }
            if(it>0) prev=it;
        }
        return prev+1; 
    }
};