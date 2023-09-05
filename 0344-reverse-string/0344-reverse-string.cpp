class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(s.begin(),s.end());
        int left = 0;
        int right = s.size()-1;
        char x;
        while(left<right){
            char x = s[left];
            s[left] = s[right];
            s[right] = x; 
            ++left;
            --right;
        }
    }
};