class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        stack<int> stk;
        const int n = nums.size();
        for(int i=0;i< 2*n; i++){
            int j = i%n;
            while(!stk.empty() && nums[j] > nums[stk.top()]){
                ans[stk.top()] = nums[j];
                stk.pop();
            }
            if(i<n) stk.push(j);
        }

        return ans;
    }
};