/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while(cur != NULL){
            if(cur->child != NULL){
                //flatten
                Node* next =cur->next;
                cur->next = flatten(cur->child);
                cur->next->prev = cur;
                cur->child = NULL;

                //tail
                while(cur->next != NULL){
                    cur = cur->next;
                }

                //attach
                if(next != NULL){
                    cur->next = next;
                    cur->next->prev = cur;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};
