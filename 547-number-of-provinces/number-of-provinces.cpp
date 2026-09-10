class Solution {

private:
    
    void dfs(int city, const vector<vector<int>>& isConnected, vector<bool>& visited, const int& length){
        visited[city] = true;

        for(int i=0;i<length;i++){
            if(isConnected[city][i] != 0 && !visited[i]) dfs(i,isConnected,visited, length);
        }
        return;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count=0;

        for(int i=0;i< n;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited, n);

                count++;
            }
        }

        return count;
    }
};