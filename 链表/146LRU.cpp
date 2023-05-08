/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-08 10:46:08
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-08 14:01:27
 * @FilePath: \leetcode\链表\146LRU.cpp
 * @Description: 双向链表加哈希
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    struct Node
    {
        int key, value;
        Node *left;
        Node *right;
        Node(int _key, int _value) : key(_key), value(_value), left(nullptr), right(nullptr) {}
    } *L, *R;
    int n;
    unordered_map<int, Node *> hash;

    void remove(Node *p)
    {
        p->right->left = p->left;
        p->left->right = p->right;
    }

    void insert(Node *p)
    {
        p->right = L->right;
        p->left = L;
        L->right->left = p;
        L->right = p;
    }

    LRUCache(int capacity)
    {
        n = capacity;
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->right = R;
        R->left = L;
    }

    int get(int key)
    {
        if (hash.count(key) == 0) // if(hash.find(key) == hash.end()) return -1;
            return -1;
        auto p = hash[key];
        remove(p);
        insert(p);
        return p->value;
    }

    void put(int key, int value)
    {
        if (hash.count(key)) // if(hash.find(key) != hash.end())
        {
            auto p = hash[key];
            p->value = value;
            remove(p);
            insert(p);
        }
        else
        {
            if (hash.size() == n)
            {
                auto p = R->left;
                remove(p);
                hash.erase(p->key);
                delete p;
            }
            auto p = new Node(key, value);
            hash[key] = p;  // hash.insert(pair<int,Node*>(key,p));
            insert(p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */