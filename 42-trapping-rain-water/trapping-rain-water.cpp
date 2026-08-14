class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int l=0,r=height.size()-1;
        int maxl=height[l],maxr=height[r];
        
        int sum=0;
        
        while(l<r){
            if(maxl<=maxr){
                l++;
                maxl = max(maxl,height[l]);
                sum+= maxl - height[l];
            }else{
                r--;
                maxr = max(maxr,height[r]);
                sum+= maxr - height[r];
            }
            
        }

        return sum;

    }
};