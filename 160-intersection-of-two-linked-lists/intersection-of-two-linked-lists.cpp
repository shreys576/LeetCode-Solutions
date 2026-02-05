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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = 0;
        int lb = 0;
        ListNode* tempA = headA;
        while(tempA != NULL){
            la++;
            tempA = tempA -> next;
        }
        ListNode* tempB = headB;
        while(tempB != NULL){
            lb++;
            tempB = tempB -> next;
        }
        int mini = min(la, lb);
        int fa = la - mini;
        for(int i = 0; i < fa; i++){
            headA = headA -> next;
        }
        int fb = lb - mini;
        for(int i = 0; i < fb; i++){
            headB = headB -> next;
        }
        tempA = headA;
        tempB = headB;
        for(int i = 0; i < mini; i++){
            if(tempA == tempB) return tempA;
            else{
                tempA = tempA -> next;
                tempB = tempB -> next;
            }
        }
        return NULL;
    }
};