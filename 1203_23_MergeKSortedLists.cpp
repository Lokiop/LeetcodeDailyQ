#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (h1 && h2)
        {
            if (h1->val < h2->val)
            {
                tail->next = h1;
                h1 = h1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = h2;
                h2 = h2->next;
                tail = tail->next;
            }
        }

        if (h1)
            tail->next = h1;
        else
            tail->next = h2;

        return head->next;
    }

    ListNode *mergeSort(vector<ListNode *> &lists, int start, int end)
    {
        if (start > end)
            return NULL;
        if (start == end)
            return lists[start];
        int mid = start + (end - start) / 2;
        ListNode *l = mergeSort(lists, start, mid);
        ListNode *r = mergeSort(lists, mid + 1, end);
        return merge(l, r);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return mergeSort(lists, 0, lists.size() - 1);
    }
};

int main()
{

    return 0;
}