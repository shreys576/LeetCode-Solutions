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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;

        int carry = 0;

        while(l1 != NULL && l2 != NULL){
            int tempVal = l1 -> val + l2 -> val + carry;
            carry = 0;
            if(tempVal >= 10){
                carry = tempVal / 10;
                tempVal = tempVal % 10;
            }
            ListNode* newnode = new ListNode(tempVal);
            ptr -> next = newnode;
            ptr = ptr -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1 != NULL){
            int tempVal = l1 -> val + carry;
            carry = 0;
            if(tempVal >= 10){
                carry = tempVal / 10;
                tempVal = tempVal % 10;
            }
            ListNode* newnode = new ListNode(tempVal);
            ptr -> next = newnode;
            ptr = ptr -> next;
            l1 = l1 -> next;
        }

        while(l2 != NULL){
            int tempVal = l2 -> val + carry;
            carry = 0;
            if(tempVal >= 10){
                carry = tempVal / 10;
                tempVal = tempVal % 10;
            }
            ListNode* newnode = new ListNode(tempVal);
            ptr -> next = newnode;
            ptr = ptr -> next;
            l2 = l2 -> next;
        }

        while(carry != 0){
            int tempVal = carry;
            if(tempVal >= 10){
                tempVal = tempVal % 10;
            }
            carry = carry - tempVal;
            ListNode* newnode = new ListNode(tempVal);
            ptr -> next = newnode;
            ptr = ptr -> next;
        }
        return dummy -> next;
    }
};