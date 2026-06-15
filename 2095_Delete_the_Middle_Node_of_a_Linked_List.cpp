class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = slow->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};


/*
//Manual Memory Deallocation

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) {
            delete head;
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* target = slow->next;
        slow->next = slow->next->next;
        delete target;
        
        return head;
    }
};
*/
