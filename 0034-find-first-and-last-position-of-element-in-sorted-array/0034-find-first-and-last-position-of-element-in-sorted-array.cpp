class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int higher=0;
        int index=-1;
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]) index=i;
            if(nums[i]>=target) ++higher;
        }
        if(index==-1) return vector<int>{static_cast<int>(-1), static_cast<int>(-1)};
        
        return vector<int>{static_cast<int>(nums.size() - higher), static_cast<int>(index)};;
    }
};