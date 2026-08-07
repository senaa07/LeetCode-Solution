class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        int countOdds=0;

        vector<int> CountEvenAfterOdds(nums.size()+1,0);
        CountEvenAfterOdds[0] = 1;

        for(auto num:nums){
            if(num%2){
                countOdds++;

            }
            if( countOdds - k >= 0 ){
                ans += CountEvenAfterOdds[countOdds - k ];
            }
            CountEvenAfterOdds[countOdds]++;
        }
        return ans;
    }
};