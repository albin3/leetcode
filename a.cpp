#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next; 
    ListNode(int x) : val(x), next(NULL) {} 
}; 

class Solution {
public:
    ListNode *mergeList(ListNode* p1, ListNode* p2) {
      ListNode* p = new ListNode(0);
      ListNode* head = p;
      while (p1!=NULL||p2!=NULL) {
        if (p1==NULL) while(p2!=NULL) {p->next=p2;p=p->next;p2=p2->next;};
        if (p2==NULL) while(p1!=NULL) {p->next=p1;p=p->next;p1=p1->next;};
        if (p1!=NULL && p2!=NULL &&p1->val<p2->val) {p->next=p1;p=p->next;p1=p1->next;};
        if (p1!=NULL && p2!=NULL &&p1->val>=p2->val) {p->next=p2;p=p->next;p2=p2->next;};
      }
      p = head;
      head = head->next;
      delete p;
      return head;
    }
    ListNode *sortList(ListNode *head) {
      if (head==NULL || head->next==NULL) return head;

      ListNode* p = new ListNode(0);
      p->next = head;
      ListNode* p1 = p;
      ListNode* p2 = p;
      while(p2!=NULL) {
        p1 = p1->next;
        p2 = p2->next;
        if (p2!=NULL) p2=p2->next;
        if (p2!=NULL && p2->next==NULL) break;
      }
      delete p;
      p2=p1->next;
      p1->next=NULL;
      p1=head;
      return mergeList(sortList(p1),sortList(p2));
    }
};

int main() {
  srand((unsigned) time(NULL));
  ListNode* head = new ListNode(rand()%100);
  ListNode* p = head;
  int i=0;
  for(; i<9; i++) {
    p->next = new ListNode(rand()%100);
    p = p->next;
  }
  for (p=head,i=0;p!=NULL;p=p->next,i++) {
    cout<<i<<" p.val:"<<p->val<<endl;
  }
  head = (new Solution)->sortList(head);
  cout<<"==================================="<<endl;
  for (p=head,i=0;p!=NULL;p=p->next,i++) {
    cout<<i<<" p.val:"<<p->val<<endl;
  }
}
