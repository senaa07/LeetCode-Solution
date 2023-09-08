class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        int n = nums.size();
        int i=0,k=0;
        while(i<n){
            int curr = nums[i];
            int cnt = 0;

            while(i<n && nums[i] == curr){
                cnt++;
                i++;
            }

            if(cnt>1){
                nums[k] = curr;
                k++;
                nums[k] = curr;
                k++;
            }
            else{
                nums[k] = curr;
                k++;
            }
        }
        return k;
    }
};