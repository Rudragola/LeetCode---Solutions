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
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left , ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(left!= NULL && right != NULL){
            if(left->val < right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if(left)temp->next = left;
        else temp->next = right;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        ListNode* left = head;
        middle->next = NULL;

        left = sortList(left);
        right= sortList(right);

        return merge(left , right);
    }
};
