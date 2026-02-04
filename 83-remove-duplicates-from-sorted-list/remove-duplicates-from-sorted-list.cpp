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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* temp = head;
        while(temp -> next != nullptr){
            if(temp -> val == temp -> next -> val){
                ListNode* toDel = temp -> next;
                temp -> next = toDel -> next;
                delete toDel;
            }
            else{
                temp = temp -> next;
            }
        }
        return head;
    }
};