class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int ans= INT_MIN;
        int startIndex = 0;
        unordered_map<char,int> freq;

        for( int lastIndex = 0 ; lastIndex < s.size(); lastIndex++){
            freq[s[lastIndex]]++;

            if(freq[s[lastIndex]] > 1){
                while(freq[s[lastIndex]] != 1){
                    freq[s[startIndex]]-=1;
                    startIndex++;
                }
            }
            ans = max(ans, lastIndex - startIndex + 1);
        }
        return ans;

    }
};