struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

inline bool operator<(const Point& a, const Point& b) {
  if (a.x<b.x) return 1;
  else if(b.x<a.x) return 0;

  if (a.y<b.y) return 1;
  else return 0;
}
struct Line {
    double k;
    double b;
    vector<Point> vp;
    Line() : k(0), b(0) {}
    Line(double x, double y) : k(x), b(y) {}
    bool operator<(const Line &b) const {
      if (this->k<b.k) return 1;
      else if (this->k>b.k) return 0;

      if (this->b<b.b) return 1;
      else if (this->b>=b.b) return 0;
    }
    bool operator==(const Line &o) const {
      return k==o.k && b==o.b;
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
      int s = points.size();
      if (s == 0) return 0;
      if (s == 1) return 1;
      if (s == 2) return 2;
      int i=0;
      if (points[0].x==points[s-1].x && points[0].y==points[s-1].y) {
        i=0;
        while(i<s-1 && points[i].x==points[i+1].x && points[i].y==points[i+1].y) {
          i++;
        }
        if (i == s-1) {
         return s;
        }
      }
      map<Point, int > m_points;
      vector<Point>::iterator vit = points.begin();
      for (; vit!=points.end(); vit++) {
        m_points[*vit]++;
      }
      vector<Point> ps(m_points.size());
      map<Point, int>::iterator mit = m_points.begin();
      i=0;
      for (; mit!=m_points.end(); mit++,i++) {
        ps[i] = mit->first;
      }
      points = ps;

      map<Line, int> m;
      int j;
      for (i=0; i<points.size(); i++) {

        map<Line, int> m_tmp;
        int samepointexist = 0;
        for (j=i+1; j<points.size(); j++) {
          Point A = points[i];
          Point B = points[j];
          if (A.x==B.x && A.y==B.y) {
            continue;
          };
          double k = 1e32;
          if (B.x-A.x!=0) {
            k = (B.y-A.y)*1.0/(B.x-A.x);
          }
          double b = A.x;
          if (k!=1e32) {
            b=A.y-k*A.x;
          }
          Line l(k,b);
          if (m_tmp[l] == 0)
            m_tmp[l] = m_points[A] + m_points[B];
          else 
            m_tmp[l] += m_points[B];
        }
        map<Line, int>::iterator mit = m_tmp.begin();
        for(;mit!=m_tmp.end(); mit++) {
          if (m[mit->first] == 0) {
            m[mit->first] = m_tmp[mit->first];
          }
        }
      }

      int max=0;
      map<Line, int>::iterator it = m.begin();
      for(; it!=m.end(); it++) {
        if (it->second > max) max = it->second;
      }
      return max;
    }
};

int main() {
  vector<Point> v;
  Point p1(0,-12);
  Point p2(5,2);
  Point p3(2,5);
  Point p4(0,-5);
  Point p5(1,5);
  Point p6(2,-2);
  Point p7(5,-4);
  Point p8(3,4);
  Point p9(-2,4);
  Point p10(-1,4);
  Point p11(0,-5);
  Point p12(0,-8);
  Point p13(-2,-1);
  Point p14(0,-11);
  Point p15(0,-9);
  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);
  v.push_back(p4);
  v.push_back(p5);
  v.push_back(p6);
  v.push_back(p7);
  v.push_back(p8);
  v.push_back(p9);
  v.push_back(p10);
  v.push_back(p11);
  v.push_back(p12);
  v.push_back(p13);
  v.push_back(p14);
  v.push_back(p15);
  cout<<(new Solution)->maxPoints(v);
  int i;
  cin>>i;
  return 0;
}
