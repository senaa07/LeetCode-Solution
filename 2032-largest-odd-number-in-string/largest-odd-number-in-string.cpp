class Solution {
public:
    string largestOddNumber(string num) {
        int lastDigitIndex = -1;

        for(int i = num.size()-1; i>=0; i--){
            if ( (num[i] - '0') % 2 == 1){
                lastDigitIndex = i;
                break;
            } 
        }
        if(lastDigitIndex != -1) return num.substr(0,lastDigitIndex+1);
        return "";
    }
};