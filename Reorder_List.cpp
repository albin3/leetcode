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
    void reorderList(ListNode *head) {
      if (head==NULL) return;
      vector<ListNode*> v;
      while(head) {
        v.push_back(head);
        head=head->next;
      }
      ListNode* p = new ListNode(0);
      head = p;
      int i=0,j=v.size()-1;
      while (i!=j) {
        p->next=v[i++];
        p=p->next;
        if (i==j) break;
        p->next=v[j--];
        p=p->next;
      }
      p->next = v[i];
      p->next->next = NULL;
      p = head;
      head = p->next;
      delete p;
    }
};

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  (new Solution())->reorderList(head);
  int i=0;
  while(head!=NULL) {
    cout<<"hello: "<<head->val<<endl;
    head=head->next;
    i++;
  }
}
