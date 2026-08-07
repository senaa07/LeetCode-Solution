class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> current;
        int temp1 =0, temp2=0, length=0;

        if(s.size()==0) return 0;
        if(s.size()==1) return 1;
        for(temp2=0;temp2<s.size();temp2++){
            if(current.find(s[temp2]) != current.end()){
                while(current.count(s[temp2])){
                    current.erase(s[temp1]);
                    temp1++;
                    //cout<<temp1<<endl;
                }
                
            }
            current.insert(s[temp2]);
            length = max( length, temp2 - temp1 + 1);
        }
        return length;

    }
};