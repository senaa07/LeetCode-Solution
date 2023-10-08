class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double taxAmount=0;
        int prev=0;
        for(auto i : brackets){
            if(income >=i[0]){
                taxAmount += (i[0]-prev) * double(i[1])/100;
                prev = i[0];
            }else{
                taxAmount+= (income-prev) * double(i[1])/100;
                break;
            }
        }
        return taxAmount;
    }
};