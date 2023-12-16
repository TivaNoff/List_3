#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;

    std::cout << "Example 1: " << std::boolalpha << solution.hasCycle(head1) << std::endl;

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2;

    std::cout << "Example 2: " << std::boolalpha << solution.hasCycle(head2) << std::endl;

    ListNode* head3 = new ListNode(1);

    std::cout << "Example 3: " << std::boolalpha << solution.hasCycle(head3) << std::endl;

    return 0;
}
