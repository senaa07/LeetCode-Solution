class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int,int> freq;
        freq.reserve(n);
        int ans=INT_MIN;
        for(int left=0, right=0; right <n ;right++){

            freq[nums[right]]++;
            while(freq[nums[right]] > k){
                freq[nums[left++]]--;
            }

            ans= max(ans, right-left +1);
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();