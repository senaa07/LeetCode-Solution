class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& temp, vector<bool>& freq ){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i] = true;
                temp.push_back(nums[i]);
                solve(nums,temp,freq);
                temp.pop_back();
                freq[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<bool> freq(nums.size(),false);
        solve(nums,ds,freq);
        return ans;
    }
};