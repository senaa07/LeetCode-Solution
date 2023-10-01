class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> stack1;
        
        for(int i=0;i<s.size();i++){
            if(s[i]== ' '){
                ans.push_back(' ');
                cout<<"1"<<endl;
                continue;
            }
            while(s[i]!=' ' && i<s.size()){
                stack1.push(s[i]);
                ++i;
            }
            
            while(!stack1.empty()){
                ans.push_back(stack1.top());
                stack1.pop();
            }
            i--;
        }
        return ans;
    }
};