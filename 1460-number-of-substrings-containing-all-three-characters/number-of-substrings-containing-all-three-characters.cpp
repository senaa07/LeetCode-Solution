class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> MinIndexCount(3,-1);
        int minIndexChar = 0, ans = 0;
        for(int i=0;i<s.size();i++){
            MinIndexCount[s[i] - 'a' ] = i;
            minIndexChar = min(MinIndexCount[0], min( MinIndexCount[1] ,MinIndexCount[2] ));
            if( minIndexChar != -1 ){
                ans += minIndexChar + 1;
            }
        }
        return ans;
    }
};