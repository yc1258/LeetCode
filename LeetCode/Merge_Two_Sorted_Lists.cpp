/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/
#include <stdio.h>
/**
* Definition for singly-linked list.
**/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        else if (l2 == NULL){
            return l1;
        }
        ListNode *head = NULL;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        ListNode *p = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 == NULL) {
            p->next = l2;
        }
        else{
            p->next = l1;
        }
        return head;
    }
    
    //a recursive method
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists2(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists2(l2->next, l1);
            return l2;
        }
    }
};
