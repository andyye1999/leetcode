/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-23 21:06:12
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-23 22:54:22
 * @FilePath: \leetcode\链表\21合并两个有序链表.cpp
 * @Description: 
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @description: 虚拟头节点，一个链表遍历完后直接连接到另一个链表
 * @param {ListNode} *list1
 * @param {ListNode} *list2
 * @return {*}
 */
ListNode *hebin(ListNode *list1, ListNode *list2)
{
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    while (list1 != nullptr && list2 != nullptr)
    {

        if (list1->val > list2->val)
        {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }
        else
        {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }
    }
    if (list1 == nullptr)
    {
        cur->next = list2;
    }
    if (list2 == nullptr)
    {
        cur->next = list1;
    }
    return head->next;
}