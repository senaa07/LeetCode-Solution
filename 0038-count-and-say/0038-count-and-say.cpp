class Solution {
private:
    string convert(string store)
    {
        string str=store;
        store.clear();
        int i=0,cnt=0;
        char pre=str[0];
        while(i<str.length())
        {
            if(pre==str[i])
            {
                cnt++;
                i++;
            }
            else
            {
                store+=to_string(cnt);
                store.push_back(pre);
                pre=str[i];
                cnt=0;
            }
        }
        store+=to_string(cnt);
        store.push_back(pre);
        return store;
    }
    void solve(int n,string &store)
    {
        if(n==1)
        {
            store=to_string(1);
            return; 
        }
        solve(n-1,store);
        store=convert(store);
        return;
    }
public:
    string countAndSay(int n) {
        if(n==1)
        {
            string str=to_string(n);
            return str;   
        }
        string store;
        solve(n,store);
        return store;
    }
};