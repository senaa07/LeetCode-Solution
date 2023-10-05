class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;
        vector<int> ans;
        if(n<2){
            return nums;
        }
        for(auto i:nums){
            if(map.count(i)==0){
                map[i] = 1;
            }else{
                map[i]++;
            }
        }
        for(auto i: map){
            if(i.second > n/3){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};