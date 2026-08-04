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

        while (cur != NULL) {
            // flatten
            if (cur->child != NULL) {
                Node* nextt = cur->next;
                cur->next = flatten(cur->child);
                cur->next->prev = cur;
                cur->child = NULL;

                // TAIL
                while (cur->next != NULL) {
                    cur = cur->next;
                }

                // atach
                if (nextt != NULL) {
                    cur->next = nextt;
                    nextt->prev = cur;
                }
            }

            cur = cur->next;
        }

        return head;
    }
};
