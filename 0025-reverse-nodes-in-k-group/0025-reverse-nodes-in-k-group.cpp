/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* getKthNode(ListNode* curr, int k) {
    k--;
    while(curr != NULL && k > 0){
        curr = curr->next;
        k--;
    }
    return curr;
}
    ListNode* reverseList(ListNode* head) {
        ListNode* temp= head;
        ListNode* prev= NULL;
        while(temp!= NULL){
            ListNode* front= temp->next;
            temp->next= prev;
            prev= temp;
            temp = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp= head;
        ListNode* prevNode= NULL;
        while(temp!= NULL){
           ListNode* Kthnode= getKthNode(temp, k);
            if(Kthnode == NULL){
                if(prevNode) prevNode->next= temp;
                break;
            }
            ListNode* nextNode= Kthnode->next;
            Kthnode->next= NULL;
            reverseList(temp);
            if(temp==head){
                head=Kthnode;
            }
                else{
                prevNode->next=Kthnode;
                }
                prevNode= temp;
                temp=nextNode;
            }
            return head;
        } 
};