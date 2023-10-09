// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int low=1,high=n,mid;
        while(low<=high){
            int mid = (high +low) /2;
            if(!isBadVersion(mid)){
                low=mid+1;
            }
            else{
                if((mid -1 >=0) && (!isBadVersion(mid-1))){
                    return mid;
                }
                high=mid-1;
            }
        }
        return -1;
    }
};