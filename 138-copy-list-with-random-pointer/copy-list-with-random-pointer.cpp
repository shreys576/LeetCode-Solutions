/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* temp = head;
        Node* prev = head;
        while(temp != NULL){
            temp = temp-> next;
            Node* tempnode = new Node(prev -> val);
            tempnode -> next = temp;
            prev -> next = tempnode;
            prev = temp;
        }
        temp = head;
        while(temp != NULL){
            if(temp -> random != NULL){
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }
        Node* dummy = new Node(0);
        Node* dhead = dummy;
        temp = head;
        while(temp != NULL){
            dhead -> next = temp -> next;
            dhead = dhead -> next;
            temp -> next = temp -> next -> next;
            temp = temp -> next;
        }
        Node* fin = dummy -> next;
        delete dummy;
        return fin;
    }
};