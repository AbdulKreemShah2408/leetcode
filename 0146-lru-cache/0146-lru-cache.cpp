class LRUCache {
    int capacity;
    list<int>lruList;
    unordered_map<int,pair<int,list<int>::iterator>>cacheMap;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key)==cacheMap.end()){
            return -1;
        }
        moveToFront(key);
        return cacheMap[key].first;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) !=cacheMap.end()){
            cacheMap[key].first=value;
            moveToFront(key);
        }else{
            if(cacheMap.size()==capacity){
                int lastKey=lruList.back();
                lruList.pop_back();
                cacheMap.erase(lastKey);
            }
            lruList.push_front(key);
            cacheMap[key]={value,lruList.begin()};

        }
    }
private:
        void moveToFront(int key){
           lruList.erase(cacheMap[key].second);
           lruList.push_front(key);
           cacheMap[key].second=lruList.begin(); 
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */