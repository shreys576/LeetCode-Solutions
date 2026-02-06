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

    ListNode* reverse(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head -> next;
        ListNode* temp3 = temp2 -> next;
        temp1 -> next = NULL;
        while(temp2 != NULL){
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            if(temp3 != NULL){
                temp3 = temp3 -> next;
            }
        }
        return temp1;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        ListNode* tempcount = head;
        ListNode* prev = dummy;
        int count = 0;
        while(tempcount != NULL){
            count++;
            tempcount = tempcount -> next;
        }
        ListNode* temp = head;
        while(count >= k){
            ListNode* temphead = temp;
            for(int i = 1; i < k; i++){
                temp = temp -> next;
            }
            ListNode* cont = temp -> next;
            temp -> next = NULL;
            temp = cont;
            ListNode* reversehead = reverse(temphead);
            prev -> next = reversehead;
            temphead -> next = temp;
            prev = temphead;
            count -= k;
        }
        prev -> next = temp;
        return dummy -> next;
    }
};