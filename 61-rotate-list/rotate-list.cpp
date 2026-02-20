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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;
        int count = 0;
        ListNode* tc = head;
        while(tc != NULL){
            count++;
            tc = tc -> next;
        }
        int a = k % count;
        for(int i = 0; i < a; i++){
            ListNode* temp = head -> next;
            ListNode* prev = head;
            while(temp -> next != NULL){
                temp = temp -> next;
                prev = prev -> next;
            }
            temp -> next = head;
            prev -> next = NULL;
            head = temp;
        }
        return head;
    }
};