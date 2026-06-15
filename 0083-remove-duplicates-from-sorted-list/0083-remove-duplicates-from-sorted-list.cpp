
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            ListNode* nextNode = temp->next;

            while (nextNode != NULL && nextNode->val == temp->val) {
                ListNode* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }

            temp->next = nextNode;
            temp = temp->next;
        }

        return head;
    }
};