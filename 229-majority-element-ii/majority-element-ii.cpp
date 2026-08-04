class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<= 1) return nums;

        vector<int> majority;
        
        int count = 1;

        for (int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1]) {
                if(count > (nums.size()/3)){
                    majority.push_back(nums[i-1]);
                }
                count=1;
            }
            else{
                ++count;
            }
        }
        if(count > (nums.size()/3)) majority.push_back(nums.back());

        return majority;
    }
};