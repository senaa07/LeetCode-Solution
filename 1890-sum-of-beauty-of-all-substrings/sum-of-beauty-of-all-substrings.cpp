class Solution {
public:
    int beautySum(string s) {
        
        int ans = 0;
        
        for (int i=0; i< s.size();i++){

            vector<int> freq(26,0);
            for (int j = i; j< s.size();j++){
                freq[s[j] - 'a']++;

                int minFreq = INT_MAX, maxFreq = INT_MIN;
                for (auto it : freq ){
                    
                    if (it>0){
                        maxFreq = max(maxFreq, it);
                        minFreq = min(minFreq, it);  
                    }
                    
                }
                ans+= (maxFreq-minFreq);
            }
        }
        return ans;
    }
};