#include <bits/stdc++.h>
using namespace std;

// SC := O(1)
// TC := O(n)

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;

        ListNode *slow = head, *fast = head;
        do
        {
            fast = fast->next;
            if (fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            else
            {
                return NULL;
            }
        } while (fast && slow != fast);

        if (!fast)
            return NULL;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main()
{

    return 0;
}