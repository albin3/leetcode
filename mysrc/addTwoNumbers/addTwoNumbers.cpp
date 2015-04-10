// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Albin. Zeng
// Date   : 2015-04-10

/****************************************************************************************
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 ****************************************************************************************/

 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      ListNode* p1 = l1;
      ListNode* p2 = l2;
      int carry = 0;
      ListNode* result = new ListNode(0);
      ListNode* p = result;
      while (p1!=NULL || p2!=NULL || carry!=0) {
        p->next = new ListNode(0);
        p = p->next;

        int val1 = 0;
        int val2 = 0;
        if (p1!=NULL) {
          val1 = p1->val;
          p1 = p1->next;
        }
        if (p2!=NULL) {
          val2 = p2->val;
          p2 = p2->next;
        }
        p->val = (val1+val2+carry)%10;
        carry  = (val1+val2+carry)/10;
      }
      p = result;
      result = result->next;
      delete p;
      return result;
    }
};
int main(int argc, char* argv[]) {
  ListNode* l1 = new ListNode(2);
  ListNode* lp = l1;
  lp->next = new ListNode(4);
  lp = lp->next;
  lp->next = new ListNode(3);
  
  
  ListNode* l2 = new ListNode(5);
  lp = l2;
  lp->next = new ListNode(6);
  lp = lp->next;
  lp->next = new ListNode(4);

  lp = (new Solution())->addTwoNumbers(l1, l2);
  for (;lp!=NULL;) {
    cout<<lp->val<<endl;
    lp = lp->next;
  }
}
