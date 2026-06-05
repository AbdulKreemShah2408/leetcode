class LFUCache {
public:
   int capacity;
   int minFreq;
   struct Node{
    int key,value,freq;
   };
   unordered_map<int,list<Node>::iterator>key_map;
   unordered_map<int,list<Node>>freq_map;
   void updateFrequency(list<Node>::iterator it){
    int key=it->key;
    int value=it->value;
    int freq=it->freq;
    freq_map[freq].erase(it);
    if(freq_map[freq].empty() && freq==minFreq){
        minFreq++;

    }
    freq_map[freq+1].push_front({key,value,freq+1});
    key_map[key]=freq_map[freq+1].begin();
   }
    LFUCache(int capacity) {
        this->capacity=capacity;
        this->minFreq=0;

    }
    
    int get(int key) {
        if(key_map.find(key)==key_map.end()) return -1;
        auto it=key_map[key];
        int res=it->value;
        updateFrequency(it);
        return res;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        if(key_map.find(key) !=key_map.end()){
            auto it=key_map[key];
            it->value=value;
            updateFrequency(it);
            return;
        }
        if(key_map.size()==capacity){
            auto delete_it=freq_map[minFreq].back();
            key_map.erase(delete_it.key);
            freq_map[minFreq].pop_back();

        }
        minFreq=1;
        freq_map[1].push_front({key,value,1});
        key_map[key]=freq_map[1].begin();

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */