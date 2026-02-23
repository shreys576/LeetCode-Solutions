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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        int pos = count - n + 1;
        if(pos == 1){
            ListNode* toDel = head;
            head = head -> next;
            delete toDel;
        }
        else if(pos == count){
            temp = head;
            while(temp -> next -> next != NULL){
                temp = temp -> next;
            }
            ListNode* toDel = temp -> next;
            temp -> next = NULL;
            delete toDel;
        }
        else{
            temp = head;
            for(int i = 1; i < pos - 1; i++){
                temp = temp -> next;
            }
            ListNode* toDel = temp -> next;
            temp -> next = toDel -> next;
            delete toDel;
        }
        return head;
    }
};