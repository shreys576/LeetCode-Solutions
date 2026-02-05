/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast){
                ListNode* intersect = slow;
                slow = head;
                while(slow != intersect){
                    slow = slow -> next;
                    intersect = intersect -> next;
                }
            return intersect;
            }
        }
        return NULL;
    }
};