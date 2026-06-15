/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertinbetween(Node* head){
        Node* temp= head;
        while(temp!= NULL){
            Node* nextElement= temp->next;
            Node* copy= new Node(temp->val);
            copy->next =nextElement;
            temp->next= copy;
            temp= nextElement;
        }
    }
   void connectrandmpointers(Node* head){
        Node* temp= head;
        while(temp!= NULL){
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random= temp->random->next;

            }
            else{
                copyNode->random= nullptr;
            }
            temp= temp->next->next;
        }
    }
    Node* getdeepcopylist(Node* head){
        Node* temp= head;
        Node* dummynode= new Node(-1);
        Node* res= dummynode;
        while(temp!= NULL){
            res->next= temp->next;
            res=res->next;
            temp->next= temp->next->next;
            temp= temp->next;
        }
        return dummynode->next;
    }
    Node* copyRandomList(Node* head) {
        insertinbetween(head);
        connectrandmpointers(head);
        return getdeepcopylist(head);
    }
};