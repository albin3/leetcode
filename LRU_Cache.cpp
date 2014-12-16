#include <iostream>
#include <map>
#include <vector>

using namespace std;

class LRUCache{
public:
    map<int, int> m;
    map<int, int> mk_t;
    map<int, int> mt_k;
    int l;
    int t;
    LRUCache(int capacity):l(capacity),t(0) {
    }
    
    int get(int key) {
      if (mk_t.find(key)!=mk_t.end()) {
        mt_k.erase(mk_t[key]);
        mk_t[key] = ++t;
        mt_k[t] = key;
        return m[key];
      } else {
        return -1;
      }
    }
    
    void set(int key, int value) {
      m[key] = value;
      if (mk_t.find(key)!=mk_t.end()) {
        mt_k.erase(mk_t[key]);
        mk_t[key] = ++t;
        mt_k[t] = key;
        return ;
      } else if(mk_t.size()==l) {
        pair<int,int> p = (pair<int, int>)(*mt_k.begin());
        mt_k.erase(p.first);
        mk_t.erase(p.second);
        mk_t[key] = ++t;
        mt_k[t] = key;
        return ;
      } else {
        mk_t[key] = ++t;
        mt_k[t] = key;
        return ;
      }
    }
};

int main() {
  LRUCache * l = new LRUCache(2);
  l->set(2,2);
  l->set(2,2);
  l->set(3,3);
  l->set(4,4);
  cout<<l->get(3)<<endl;
  cout<<l->get(2)<<endl;
  cout<<l->get(4)<<endl;
}
