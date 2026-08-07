class Solution {

private:
    int helper(vector<int>& nums, int k){
        unordered_map<int,int> freq;
        int left= 0;
        int ans=0;

        for(int right=0; right < nums.size(); right++){
            freq[nums[right]]++;

            while(freq.size()>k){
                if(freq[nums[left]] > 1) freq[nums[left]]--;
                else freq.erase(nums[left]);
                //freq[nums[left]]--;
                //if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            ans+= right-left+ 1;

        }
        return ans;
    }


public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return helper(nums, k) - helper(nums,k-1); 
    }
};