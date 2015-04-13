// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : Albin Zeng
// Date : 2015-04-13

/**********************************************************************************************************************************
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 *
 * For example,
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 *
 *
 ********************************************************************************************************************************/

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    // divide into two and merge to one;
    ListNode *swapPairs(ListNode *head) {

      ListNode* result = new ListNode(0);
      ListNode* presult = result;

      ListNode *one = new ListNode(0);
      ListNode *pone = one;
      ListNode *two = new ListNode(0);
      ListNode *ptwo = two;

      // Devide
      while (head != NULL) {

        if (head!=NULL) {
          pone->next = head;
          head = head->next;
          pone = pone->next;
          pone->next = NULL;
        }

        if (head!=NULL) {
          ptwo->next = head;
          head = head->next;
          ptwo = ptwo->next;
          ptwo->next = NULL;
        }

      }


      // Merge
      pone = one->next;
      ptwo = two->next;
      while (ptwo!=NULL) {

        presult->next = ptwo;
        ptwo = ptwo->next;
        presult = presult->next;

        presult->next = pone;
        pone = pone->next;
        presult = presult->next;

      }
      while (pone!=NULL) {
        presult->next = pone;
        pone = pone->next;
        presult = presult->next;
      }

      delete one;
      delete two;
      presult = result;
      result = result->next;
      delete presult;

      return result;
    }
};

int main() {
  ListNode *head = new ListNode(3);
  ListNode *p = head; 
  p->next = new ListNode(4);
  p = p->next;
  p->next = new ListNode(5);
  p = p->next;
  p->next = new ListNode(6);
  p = p->next;
  p->next = new ListNode(7);

  p = (new Solution)->swapPairs(head);

  while (p!=NULL) {
    cout<<p->val<<endl;
    p = p->next;
  }

  return 0;
}
