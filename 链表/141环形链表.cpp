#include <iostream>

using namespace std;



// 环形链表，慢指针一次移动一格，快指针一次移动两格，在环内相遇，while的条件不会写
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool huanxing(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}