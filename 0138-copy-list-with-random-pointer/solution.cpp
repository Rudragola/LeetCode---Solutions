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
        if (head == NULL)
            return NULL;
        unordered_map<Node*, Node*> mpp;
        Node* oldTemp = head->next;
        Node* newHead = new Node(head->val);
        Node* newTemp = newHead;
        mpp[head] = newHead;

        // copy simple list
        while (oldTemp != NULL) {
            Node* copy = new Node(oldTemp->val);
            mpp[oldTemp] = copy;
            newTemp->next = copy;
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        // copy random nodes
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            if (oldTemp->random != NULL) {
                newTemp->random = mpp[oldTemp->random];
            } else {
                newTemp->random = NULL;
            }
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
