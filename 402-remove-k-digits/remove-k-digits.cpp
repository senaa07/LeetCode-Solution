class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;

        for(const char& it:num){
            while(!stack.empty() && stack.back() > it && k>0){
                stack.pop_back();
                k--;
            }
            stack.push_back(it);
        }

        while(k>0 && !stack.empty()){
            stack.pop_back();
            k--;
        }

        int start=0;
        while(start < stack.size()-1 && stack[start] == '0'){
            start++;
        }

        return stack.empty()? "0": stack.substr(start);
    }
};