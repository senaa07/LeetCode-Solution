class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n == 1) return 1;
        int prev = 1;
        int prev1 = 1;
        

        for(int i=0; i<n-1;i++){
            prev1 = prev + prev1;
            prev = prev1 - prev;
        }
        return prev1;
    }
};