class TimeMap {
    unordered_map<string,vector<pair<int,string>>>store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)==store.end()) return "";
        auto& values=store[key];
        string result="";
        int left=0, right=values.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(values[mid].first<=timestamp){
                result=values[mid].second;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
      return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */