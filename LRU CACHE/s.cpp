// THIS ONE IS JUST LIL MORE EFFICIENT 
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList; // Maintains the order of keys based on usage.
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // Maps keys to their positions in the list.

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = cacheMap.find(key);

        if (it != cacheMap.end()) {
            // Move the accessed key to the front of the list.
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return it->second->second;
        }

        return -1; // Key not found.
    }

    void put(int key, int value) {
        auto it = cacheMap.find(key);

        if (it != cacheMap.end()) {
            // Key exists, update the value and move it to the front.
            it->second->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
        } else {
            // Key does not exist, check if the cache is full.
            if (cacheList.size() == capacity) {
                // Evict the least recently used key from the back of the list.
                int evictedKey = cacheList.back().first;
                cacheMap.erase(evictedKey);
                cacheList.pop_back();
            }

            // Insert the new key-value pair to the front of the list.
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }
};

/*
LRUCache lRUCache = LRUCache(2);
// cache is {}

lRUCache.put(1, 1);
// cache is {1=1}

lRUCache.put(2, 2);
// cache is {1=1, 2=2}

lRUCache.get(1);
// Move key 1 to the front (most recently used)
// cache is {2=2, 1=1}
// return 1

lRUCache.put(3, 3);
// LRU key was 2, evicts key 2
// cache is {1=1, 3=3}

lRUCache.get(2);
// Key 2 is not found
// cache is {1=1, 3=3}
// return -1

lRUCache.put(4, 4);
// LRU key was 1, evicts key 1
// cache is {4=4, 3=3}

lRUCache.get(1);
// Key 1 is not found
// cache is {4=4, 3=3}
// return -1

lRUCache.get(3);
// Move key 3 to the front (most recently used)
// cache is {3=3, 4=4}
// return 3

lRUCache.get(4);
// Move key 4 to the front (most recently used)
// cache is {4=4, 3=3}
// return 4


    The LRUCache is initialized with a capacity of 2.
    put(1, 1) inserts key 1 with value 1.
    put(2, 2) inserts key 2 with value 2.
    get(1) returns 1 and moves key 1 to the front.
    put(3, 3) evicts key 2, inserts key 3 with value 3.
    get(2) returns -1 (not found).
    put(4, 4) evicts key 1, inserts key 4 with value 4.
    get(1) returns -1 (not found).
    get(3) returns 3 and moves key 3 to the front.
    get(4) returns 4 and moves key 4 to the front.
*/


========================================================================================




class Node{
    public:
    int key;
    int val;
    Node*next;
    Node*prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>m;
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    int size;
    LRUCache(int capacity) {
           size=capacity;
            head->next=tail;
             tail->prev=head;
    }
    void deleteNode(Node*p){
       Node*pre=p->prev;
       Node*nex=p->next;
       pre->next=nex;
       nex->prev=pre;
    }
    void addNode(Node*newnode){
        Node*temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    int get(int key) {
        if(m.find(key)==m.end())
        return -1;
        Node*p=m[key];
        deleteNode(p);
        addNode(p);
        m[key]=head->next;
        return head->next->val;
    }
    
    void put(int key, int value) {
       if(m.find(key)!=m.end()){
            Node*c=m[key];
            deleteNode(c);
            c->val=value;
            addNode(c);
            m[key]=head->next;
        }
        else{
            if(m.size()==size){
                Node* prev=tail->prev;
                deleteNode(prev);
                Node*l=new Node(key,value);
                addNode(l);
                m.erase(prev->key);
                m[key]=head->next;
            }
            else{
                 Node*l=new Node(key,value);
                addNode(l);
                m[key]=head->next; 
            }
        }
    }
};


/*

LRUCache* obj = new LRUCache(2);
// Cache is initialized with a capacity of 2

obj->put(1, 1);
// Cache state: {1=1}

obj->put(2, 2);
// Cache state: {1=1, 2=2}

int param_1 = obj->get(1);
// Cache state: {2=2, 1=1} (key 1 moved to the front)
// param_1 = 1 (value associated with key 1)

obj->put(3, 3);
// Cache is full, evict least recently used key (key 2)
// Cache state: {1=1, 3=3}

int param_2 = obj->get(2);
// Key 2 is not found
// Cache state: {1=1, 3=3}
// param_2 = -1

obj->put(4, 4);
// Cache is full, evict least recently used key (key 1)
// Cache state: {4=4, 3=3}

int param_3 = obj->get(1);
// Key 1 is not found
// Cache state: {4=4, 3=3}
// param_3 = -1

int param_4 = obj->get(3);
// Cache state: {3=3, 4=4} (key 3 moved to the front)
// param_4 = 3

int param_5 = obj->get(4);
// Cache state: {4=4, 3=3} (key 4 moved to the front)
// param_5 = 4


    LRUCache* obj = new LRUCache(2);: The LRUCache is created with a capacity of 2.
    obj->put(1, 1);: Key 1 with value 1 is added to the cache.
    obj->put(2, 2);: Key 2 with value 2 is added to the cache.
    int param_1 = obj->get(1);: The value associated with key 1 is retrieved, and key 1 is moved to the front.
    obj->put(3, 3);: Key 2 is evicted (LRU), and key 3 with value 3 is added to the cache.
    int param_2 = obj->get(2);: Key 2 is not found in the cache.
    obj->put(4, 4);: Key 1 is evicted (LRU), and key 4 with value 4 is added to the cache.
    int param_3 = obj->get(1);: Key 1 is not found in the cache.
    int param_4 = obj->get(3);: The value associated with key 3 is retrieved, and key 3 is moved to the front.
    int param_5 = obj->get(4);: The value associated with key 4 is retrieved, and key 4 is moved to the front.

*/