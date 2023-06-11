class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int _key,int _val){
        key=_key;
        val=_val;
    }
};
class LRUCache {
public:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*>mp;
    int cap;
    void addNode(Node* node){
        node->next=head->next;
        node->next->prev=node;
        head->next=node;
        node->prev=head;
    }
    void deleteNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
        if(mp.count(key)){
            Node* temp=mp[key];
            deleteNode(mp[key]);
            addNode(temp);
            return temp->val;
        }
        return -1;
    }
    void put(int key, int value) {
        if(mp.count(key)){
            deleteNode(mp[key]);
            mp.erase(key);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* temp=new Node(key,value);
        mp[key]=temp;
        addNode(temp);
    }
};