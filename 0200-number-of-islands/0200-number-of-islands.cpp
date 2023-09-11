class Solution {
public:
    
    void bfs(vector<vector<char>>& grid, int row,int col,vector<vector<int>>& visited){
        int n = grid.size();
        int m= grid[0].size();
        queue<pair<int,int>> q;
        visited[row][col] = 1;
        q.push({row,col});

        while( !q.empty()){
            row= q.front().first;
            col= q.front().second;
            q.pop();

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow = row + i;
                    int ncol = col + j;
                    if(abs(i)==abs(j)){continue;}
                    if(nrow >=0 && nrow<n && ncol >=0 && ncol <m && visited[nrow][ncol] ==0 && grid[nrow][ncol] == '1'){
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        int count=0;
        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j] == '1'){
                    count++;
                    bfs(grid,i,j,visited);
                    
                }
            }
        }
        return count;
        /*
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!= '1') continue;
                if(i==0){
                    if(j==0){
                        if(grid[i+1][j]=='0' || grid[i][j+1]=='0') count++;
                    }
                    else if(j==n-1){
                        if(grid[i+1][j]=='0' || grid[i][j-1]=='0') count++;
                    }
                    else{
                        if(grid[i+1][j]=='0' || (grid[i][j+1]=='0' && grid[i][j-1]=='0')) count++;
                    }
                }

                else if(i==m-1){
                    if(j==0){
                        if(grid[i-1][j]=='0' || grid[i][j+1]=='0') count++;
                    }
                    else if(j==n-1){
                        if(grid[i-1][j]=='0' || grid[i][j-1]=='0') count++;
                    }
                    else{
                        if(grid[i-1][j]=='0' || (grid[i][j+1]=='0' && grid[i][j-1]=='0')) count++;
                    }
                }
                else{
                    if((grid[i+1][j]=='0' && grid[i-1][j]=='0') || (grid[i][j+1] && grid[i][j-1]=='0')) count++;
                }
            }
        }
        return count;*/
    }
};