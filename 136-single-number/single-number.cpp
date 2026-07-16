class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int i=0 ; i < nums.size() ; i++){
            if(freq.find(nums[i]) == freq.end()){
                freq[nums[i]] =1;
            }
            else freq[nums[i]]++;
        }
        for(const auto& it:freq){
            if(it.second==1) return it.first;
        }

        return 0;
    }
};