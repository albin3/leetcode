// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : Albin Zeng
// Date : 2015-04-13

/*****************************************************************************************************
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 *****************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // TODO: 采用最小堆求解

    // 使用分治法解
    ListNode *mergeKLists(vector<ListNode *> &lists) {
      ListNode *result = NULL;
      
      if (lists.size() == 0) return result;

      while (lists.size() != 1) {
        vector<ListNode *> tmp;
        
        int s = lists.size();
        for (int i=0; i<(s+1)/2; i++) {
          if (i*2+1 < s) {
            tmp.push_back(mergeTwoList(lists[i*2], lists[i*2+1]));
          } else {
            tmp.push_back(mergeTwoList(lists[i*2], NULL));
          }
        }

        lists = tmp;
      }

      result = lists[0];

      return result;
    }
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
      ListNode *head = new ListNode(0);

      ListNode *p = head;

      while (l1!=NULL && l2!=NULL) {

        if (l1->val < l2->val) {
          p->next = l1;
          l1 = l1->next;
        } else {
          p->next = l2;
          l2 = l2->next;
        }

        p = p->next;
      }

      while (l1!=NULL) {
        p->next = l1;
        l1 = l1->next;
        p = p->next;
      }

      while (l2!=NULL) {
        p->next = l2;
        l2 = l2->next;
        p = p->next;
      }

      p = head;
      head = head->next;
      delete p;

      return head;
    }
};

int main() {
  vector<ListNode *> vl;
  vl.push_back(new ListNode(12));
  vl.push_back(new ListNode(11));
  vl.push_back(new ListNode(13));
  vl.push_back(new ListNode(17));
  vl.push_back(new ListNode(13));
  vl.push_back(new ListNode(10));

  ListNode* p = (new Solution)->mergeKLists(vl);

  while (p!=NULL) {
    cout<<p->val<<endl;
    p = p->next;
  }
}
