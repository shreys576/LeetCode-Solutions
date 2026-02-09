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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 -> val < temp2 -> val){
                prev -> next = temp1;
                temp1 = temp1 -> next;
            }
            else{
                prev -> next = temp2;
                temp2 = temp2 -> next;
            }
            prev = prev -> next;
        }
        while(temp1 != NULL){
            prev -> next = temp1;
            temp1 = temp1 -> next;
            prev = prev -> next;
        }    
        while(temp2 != NULL){
            prev -> next = temp2;
            temp2 = temp2 -> next;
            prev = prev -> next;
        }
        return dummy -> next;
    }
};