#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *fanzhuan(ListNode *head)
{
    ListNode *tmp;
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur != nullptr)
    {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int main()
{
    ListNode *LHead = new ListNode();
    ListNode *cur = nullptr;
    ListNode *pre = LHead;
    int n;
    while (cin >> n)
    {
        cur = new ListNode(n);
        pre->next = cur;
        pre = cur;
        if (getchar() == '\n')
        {
            break;
        }
    }
    cur = LHead->next;
    ListNode* result;
    result = fanzhuan(cur);
    while(result)
    {
        cout << result->val << ' ';
        result = result->next;
    }
}