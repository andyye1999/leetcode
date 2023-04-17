#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};


// 快慢指针相遇后，一个从头节点出发，一个从相遇节点出发，相遇即环形入口
ListNode* huanxing(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            ListNode* ptr1 = head;
            ListNode* ptr2 = fast;
            while(ptr1 != ptr2)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }
    }
    return nullptr;
}