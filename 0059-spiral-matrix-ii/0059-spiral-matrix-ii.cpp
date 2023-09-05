class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int srow = 0, erow = n-1, scol = 0, ecol = n-1, element = 1, total = n*n;
        while(element <= total)    {
            for(int i=scol; i<=ecol && element<=total; i++)   {
                ans[srow][i] = element++;
            }
            srow++;

            for(int i=srow; i<=erow && element<=total; i++)   {
                ans[i][ecol] = element++;
            }
            ecol--;

            for(int i=ecol; i>=scol && element<=total; i--)   {
                ans[erow][i] = element++;
            }
            erow--;

            for(int i=erow; i>=srow && element<=total; i--)   {
                ans[i][scol] = element++;
            }
            scol++;
        }

        return ans;
    }
};