class Solution {
public:
    bool isSubsequence(string s, string t) {
        //bool flag =false;
        int m = s.size()-1;
        if(m==-1) return true;
        for(int i=t.size()-1;i>=0;i--){
            if(s[m]== t[i]){
                if(m==0) return true;
                --m;
                //cout<<m<<endl;
                
            }
        }
        return false;
    }
};