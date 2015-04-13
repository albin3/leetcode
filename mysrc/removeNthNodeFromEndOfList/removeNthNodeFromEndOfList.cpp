// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : Albin Zeng
// Date : 2015-04-12

/********************************************************************************************
 *
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 *   After removing the second node from the end, the linked list becomes 1->2->3->5.
 *   Note:
 *   Given n will always be valid.
 *   Try to do this in one pass.
 *
 ******************************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 队列解法，经典的解法是用双指针的。
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      queue<ListNode*> q;
      
      ListNode* phead = head;
      while (phead!=NULL) {
        q.push(phead);
        if (q.size()>n+1) {
          q.pop();
        }
        phead = phead->next;
      }

      if (q.size() < n) {
        ;
      } else if (q.size() == n) {
        phead = head;
        head = head->next;
        delete phead;
      } else {
        ListNode* pre = q.front();
        q.pop();
        pre->next = q.front()->next;
        delete q.front();
      }

      return head;
    }
};

int main() {
  ListNode* p = new ListNode(1);
  ListNode* pp = p;
  pp->next = new ListNode(2);
  pp = pp->next;
  pp->next = new ListNode(3);
  pp = pp->next;
  pp->next = new ListNode(4);
  pp = pp->next;
  pp->next = new ListNode(5);
  ListNode* r = (new Solution)->removeNthFromEnd(p, 2);

  for (pp=r; pp!=NULL; pp=pp->next) {
    cout<<pp->val<<endl;
  }
}
