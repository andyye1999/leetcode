#include <iostream>

using namespace std;


// 熟悉链表结构，会自己写链表，虚拟头节点，会自己写链表输入输出
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteval(ListNode *head, int val)
{
    ListNode *virhead = new ListNode(0);
    virhead->next = head;
    ListNode *cur = virhead;
    while (cur->next != nullptr)
    {
        if (cur->next->val == val)
        {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else
        {
            cur = cur->next;
        }
    }
    cur = virhead->next;
    delete virhead;
    return cur;
}

int main()
{
    ListNode* LHead = new ListNode();
    ListNode* pre = LHead;
    ListNode* cur = nullptr;

    int val;
    cin >> val;
    int n;
    while(cin >> n)
    {
        cur = new ListNode(n);
        pre->next = cur;
        pre = cur;
        if(getchar() == '\n')
        {
            break;
        }
    }

    cur = LHead->next;
    ListNode* result;
    result = deleteval(cur,val);
    while(result)
    {
        cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}