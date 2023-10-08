class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        
        int waiting=0,profit=0,rotation=0;
        int i=0;
        while(i<customers.size() || waiting!=0 ){
            if(i<customers.size()){
                if(waiting==0 && customers[i]==0 && i==customers.size()-1){
                    break;
                } 
                waiting += customers[i];
                if(waiting>4){
                    waiting-=4;
                    profit+=(4*boardingCost - runningCost);
                    rotation++;
                    
                }else{
                    profit+=(waiting*boardingCost - runningCost);
                    waiting=0;
                    rotation++;
                    
                }
                i++;
            }else{
                
                profit+=waiting*boardingCost;
                
                waiting = waiting/4 + ((waiting%4)*boardingCost<=runningCost?0:1 );
                cout<<waiting<<endl;
                profit-= waiting * runningCost;
                rotation+=waiting;
                waiting=0;
                
            }
        }
        if(profit>0) return rotation;
        return -1;
    }
};