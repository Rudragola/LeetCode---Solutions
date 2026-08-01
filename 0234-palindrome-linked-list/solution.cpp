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
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* reve = rev(slow->next);
        ListNode* first = head;
        ListNode* second = reve;
        while (second != NULL) {
            if (first->val != second->val) {
                rev(reve);
                return false;
            }

            first = first->next;
            second = second->next;
        }
        rev(reve);
        return true;
    }
};
