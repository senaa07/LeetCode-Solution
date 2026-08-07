class Solution {
public:
    int characterReplacement(string s, int k) {
        int startIndex = 0;
        unordered_map<char,int> freq;
        int maxFreq = INT_MIN;
        int ans = INT_MIN;

        for(int endIndex=0; endIndex < s.size() ;endIndex++ ){

            freq[s[endIndex]]++;

            maxFreq = max(maxFreq, freq[s[endIndex]]);

            if(endIndex - startIndex + 1 - maxFreq > k){
                freq[s[startIndex]]-=1;
                startIndex++;
            }

            ans = max(ans, endIndex-startIndex+1);
        }
        return ans;
        
    }
};