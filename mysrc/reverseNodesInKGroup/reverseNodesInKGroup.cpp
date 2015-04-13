// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : Albin Zeng
// Date : 2015-04-13

/************************************************************************************************************
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * 
 * Only constant memory is allowed.
 *
 *
 * For example,
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 *
 *************************************************************************************************************/

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
    // like swap nodes in pairs, devide into K group and merge them to one;
    ListNode *reverseKGroup(ListNode *head, int k) {

      ListNode *result = new ListNode(0);
      ListNode *presult = result;

      // create K group
      vector<ListNode* > kg;
      vector<ListNode* > pkg;
      for (int i=0; i<k; i++) {
        kg.push_back(new ListNode(0));
        pkg.push_back(kg[i]);
      }

      // devide into K group

      while (head!=NULL) {

        for (int i=0; i<k; i++) {

          if (head!=NULL) {
            pkg[i]->next = head;
            head = head->next;
            pkg[i] = pkg[i]->next;
            pkg[i]->next = NULL;
          }

        }

      }


      // merge to one List

      for (int i=0; i<k; i++) {
        pkg[i] = kg[i]->next;
      }

      while (pkg[k-1] != NULL) {

        for (int i=k-1; i>=0; i--) {
          presult->next = pkg[i];
          presult = presult->next;
          pkg[i] = pkg[i]->next;
        }

      }

      for (int i=0; i<k; i++) {
        if (pkg[i] != NULL) {
          presult->next = pkg[i];
          presult = presult->next;
          pkg[i] = pkg[i]->next;
        }
      }

      // delete new memory
      for (int i=0; i<k; i++) {
        delete kg[i];
      }
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

  p = (new Solution)->reverseKGroup(head, 3);

  while (p!=NULL) {
    cout<<p->val<<endl;
    p = p->next;
  }

  return 0;
}
