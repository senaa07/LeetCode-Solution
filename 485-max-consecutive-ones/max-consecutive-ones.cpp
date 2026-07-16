class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;

        if(nums[0]==1){
            currentCount=1;
            maxCount = 1;
        }
        

        for(int i=1;i<nums.size();i++){
            if(nums[i]==1){
                if(nums[i-1]==1){
                    currentCount++;
                    
                }else{
                    currentCount=1;
                    
                }
                maxCount = max(maxCount,currentCount);
            }
        }
        return maxCount;
    }
};