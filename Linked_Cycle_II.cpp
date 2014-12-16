#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      if (head==NULL) return NULL;
      ListNode *p1 = head;
      ListNode *p2 = head;
      int first = 0;
      while (first==0||p2!=NULL&&p1!=p2)  {
        first=1;
        p1 = p1->next;
        p2 = p2->next;
        if (p2!=NULL) p2=p2->next;
      }
      if(p2==NULL) return NULL;
      p1 = head;
      while(p1!=p2) {
        p1 = p1->next;
        p2 = p2->next;
        cout<<p1<<"::"<<p2<<endl;
      }
      return p1;
    }
};

int main() {
  ListNode* p = new ListNode(0);
  p->next = p;
  ListNode* r = (new Solution())->detectCycle(p);
}
