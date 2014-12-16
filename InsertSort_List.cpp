#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
      if (head==NULL||head->next==NULL) return head;

      ListNode* p = new ListNode(1);
      ListNode* pl=head;
      p->next=NULL;

      while (pl!=NULL) {
        ListNode* pm=p;
        while(pm->next!=NULL && pm->next->val<pl->val) pm=pm->next;
        ListNode* tmp = pm->next;
        pm->next=pl;
        pl=pl->next;
        pm->next->next=tmp;
      }
      pl = p->next;
      delete p;
      return pl;
    }
};

int main() {
  ListNode *p = new ListNode(1);
  p->next = new ListNode(1);
  ListNode *tmp = p;
  while(tmp!=NULL) {
    cout<<tmp->val<<endl;
    tmp=tmp->next;
  }
  p = (new Solution())->insertionSortList(p);
  cout<<"=================="<<endl;
  tmp = p;
  while(tmp!=NULL) {
    cout<<tmp->val<<endl;
    tmp=tmp->next;
  }
}
