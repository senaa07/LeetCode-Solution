class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>>& ans,int index,vector<int>&temp){
        if(index== nums.size()){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(nums,ans,index+1,temp);
        temp.pop_back();
        solve(nums,ans,index+1,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        set<vector<int>> ans;
        ans.insert(temp);
        solve(nums,ans,0,temp);
        vector<vector<int>> ans1(ans.begin(),ans.end());
        return ans1;

    }
};