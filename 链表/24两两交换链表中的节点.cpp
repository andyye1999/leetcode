#include <iostream>

using namespace std;


// tmp的确定
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *jiaohuan(ListNode *head)
{
    ListNode *virhead = new ListNode(0);
    ListNode *cur = virhead;
    virhead->next = head;
    while (cur->next != nullptr && cur->next->next != nullptr)
    {
        ListNode *tmp = cur->next;
        ListNode *tmp1 = cur->next->next->next;
        cur->next = cur->next->next;
        cur->next->next = tmp;
        cur->next->next->next = tmp1;
        cur = cur->next->next;
    }
    ListNode *result = virhead->next;
    return result;
}

int main()
{
    int n;
    ListNode *LHead = new ListNode(0);
    ListNode *pre = LHead;
    ListNode *cur = nullptr;
    while (cin >> n)
    {
        cur = new ListNode(n);
        pre->next = cur;
        pre = cur;
        if (getchar() == '\n')
            break;
    }

    cur = LHead->next;
    ListNode *result = jiaohuan(cur);
    while (result)
    {
        cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}