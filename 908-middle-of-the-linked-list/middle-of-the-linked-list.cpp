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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        int count = 1;
        ListNode* temp = head;
        while(temp -> next != nullptr){
            count ++;
            temp = temp -> next;
        }
        int mid;
        if(count % 2 == 0){
            mid = (count / 2) + 1;
        }
        else{
            mid = (count / 2) + 1;
        }
        ListNode* m = head;
        for(int i = 1; i < mid; i++){
            m = m -> next;
        }
        return m;
    }
};