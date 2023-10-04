class MyHashMap {

private:
    vector<pair<int,int>> HashMap;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(auto& i: HashMap){
            if(i.first == key){
                i.second = value;
                return ;
            }
        
        }
        HashMap.push_back(make_pair(key,value));
    }
    
    int get(int key) {
        for(const auto& i: HashMap){
            if(i.first == key){
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for (auto it = HashMap.begin(); it != HashMap.end();++it){
            if(it->first == key){
                HashMap.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */