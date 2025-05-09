class LRUCache {
public:

    class node{
        public:
        int key,val;
        node* next;
        node* prev;

        node(int key,int val){
            this->key = key;
            this->val = val;
        }
    };

    node* head = new node (-1,-1);
    node* tail = new node (-1,-1);

    int cap ;
    unordered_map <int,node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addAfterHead(node* newnode){
        node* temp = head->next;
        newnode ->next = temp;
        temp -> prev = newnode;
        head -> next = newnode;
        newnode -> prev = head;
    }

    void deleteNode(node* delnode){
        node* delprev = delnode -> prev;
        node* delnext = delnode ->next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            node* resnode = m[key];
            int res = resnode -> val;
            m.erase(key);
            deleteNode(resnode);
            addAfterHead(resnode);
            m[key] = head -> next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addAfterHead(new node(key,value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */