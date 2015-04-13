// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : Albin Zeng
// Date : 2015-04-13

/*****************************************************************************************
 *
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 *****************************************************************************************/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

      ListNode* result = new ListNode(0);
      ListNode* p = result;

      ListNode* p1 = l1;
      ListNode* p2 = l2;
      while (p1!=NULL && p2!=NULL) {

        if (p1->val < p2->val) {
          p->next = p1;
          p1 = p1->next;
        } else {
          p->next = p2;
          p2 = p2->next;
        }

        p = p->next;
      }

      while (p1!=NULL) {
        p->next = p1;
        p = p->next;
        p1 = p1->next;
      }

      while (p2!=NULL) {
        p->next = p2;
        p = p->next;
        p2 = p2->next;
      }

      p = result;
      result = result->next;
      delete p;

      return result;
    }
};

int main() {
  ListNode* p = new ListNode(1);
  ListNode* pp = p;
  pp->next = new ListNode(3);
  ListNode* q = new ListNode(2);

  ListNode* r = (new Solution)->mergeTwoLists(p, q);

  pp = r;
  while (pp!=NULL) {
    cout<<pp->val<<endl;
    pp = pp->next;
  }

  return 0;
}
