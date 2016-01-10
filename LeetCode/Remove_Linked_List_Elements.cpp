/*
 Remove all elements from a linked list of integers that have value val.
 
 Example
 Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 Return: 1 --> 2 --> 3 --> 4 --> 5
 */
#include <stdio.h>
/**
 Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val) {
            head = head->next;
        }
        if(!head)
            return head;

        ListNode* p = head;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            }
            else
                p = p->next;
        }
        if (p->val == val) {
            p = NULL;
        }
        return head;
    }
    
    //also a smart solution of double pointer on leetcode discussion
    ListNode* removeElements2(ListNode* head, int val) {
        ListNode** tmp = &head;
        while(*tmp){
            if((*tmp)->val == val) *tmp = (*tmp)->next;
            else tmp = &((*tmp)->next);
        }
        return head;
    }
};