class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node *next;
            Node *prev;

            Node (int key, int val) {
                this -> key = key;
                this -> val = val;
                this -> next = NULL;
                this -> prev = NULL;
            }
    };
    unordered_map <int, Node*> mahi;
    int capacity;
    
    Node *head = new Node (0,0);
    Node *tail = new Node (0,0);

    LRUCache(int capacity) {
        this -> capacity = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void remove(Node* currnode) {
        mahi.erase(currnode->key);
        currnode->next->prev =currnode->prev;
        currnode->prev->next=currnode->next;
       
    }

    void insert (Node* currnode) {
        currnode->next = head->next;                    
        head->next->prev = currnode;
        head->next= currnode;
        currnode->prev= head;
        mahi[currnode->key]=currnode;                 
    }

    int get(int key) {
        if (mahi.find(key)!=mahi.end()) {
            Node *currNode = mahi [key];
            remove (currNode);
            insert (currNode);
            return currNode -> val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mahi.find(key)!=mahi.end()) {
            remove (mahi[key]);
        }

        if (mahi.size()==capacity) {
            remove (tail -> prev);
        }
        

        insert (new Node(key, value));

    }
};
