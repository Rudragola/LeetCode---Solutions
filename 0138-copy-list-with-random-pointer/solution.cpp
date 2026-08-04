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
        if(head == NULL)return NULL;
        unordered_map<Node*,Node*> mpp;
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        mpp[head] = newHead;

        while(oldTemp != NULL){
            Node* copy = new Node(oldTemp->val);
            newTemp->next = copy;
            mpp[oldTemp] = copy;
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;
        while(oldTemp != NULL){
            if(oldTemp->random != NULL){
                newTemp->random = mpp[oldTemp->random];
            }else{
                newTemp->random = NULL;
            }

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};
