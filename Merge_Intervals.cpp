// Source : https://oj.leetcode.com/problems/merge-intervals/
// Author : Hao Chen
// Date   : 2014-08-26

/********************************************************************************** 
* 
* Given a collection of intervals, merge all overlapping intervals.
* 
* For example,
* Given [1,3],[2,6],[8,10],[15,18],
* return [1,6],[8,10],[15,18].
* 
*               
**********************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespacse std;

struct Interval {
  int start;
  int end;
  Interval():start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
  
  static bool cmp(const Interval& a, const Interval &£â){
    return (a.start==b.start) ? a.end<b.end : a.start<b.start;
  }
  /*cmp是定义在一个类中的成员函数。开始的时候老是报错：no matching function for call to 'sort(...), <unresolved overloaded function type>'。后来我把该成员定义成静态函数，问题解决。原因可能和类成员函数的函数原型有关。所有成员函数都有一个隐含的指针参数，即this。这就和sort需要的comp函数原型不一致了，所以就报错了。而static函数就没有这个隐含参数了

如果类中有个cmp函数,调用时,类型就多了个this指针, 当然类型不对*/
  vector<Interval> merge(vector<Interval> &intervals) {

    vector<Interval> result;

    if (intervals.size() <= 0) return result;

    sort(intervals.begin(), intervals.end(), compare);
    for(int i=0; i<intervals.size(); i++) { 
        int size = result.size();
        if( size>0 && result[size-1].end >= intervals[i].start) {
            result[size-1].end = max(result[size-1].end, intervals[i].end); 
        }else{
            result.push_back(intervals[i]);
        }
    }
    
    return result;
}
}
