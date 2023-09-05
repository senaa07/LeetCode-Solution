class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(int i=0 ;i< intervals.size();i++){
            if(newInterval[0] > intervals[i][0] && newInterval[0] > intervals[i][1] || newInterval[1] < intervals[i][0] && newInterval[1] < intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            else{

            
                if(newInterval[0] > intervals[i][0] && newInterval[1] >= intervals[i][1]){
                    newInterval[0] = intervals[i][0];
                    cout<<"first"<<"  ";
                }
                else if (newInterval[0] > intervals[i][0] && newInterval[1] < intervals[i][1]){
                    newInterval = intervals[i];
                }
                else if(newInterval[1] >= intervals[i][0] && newInterval[1] < intervals[i][1]){
                    newInterval[1] = intervals[i][1];
                    cout<<"second"<<"  ";
                }
                
            }
        }
        ans.push_back(newInterval);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
};