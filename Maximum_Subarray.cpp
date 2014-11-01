// Source : https://oj.leetcode.com/problems/maximum-subarray/
// Author : wizzhangquan@gmail.com
// Date   : 2014-11-01

/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest sum.
* 
* For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
* 
* More practice:
* 
* If you have figured out the O(n) solution, try coding another solution using 
* the divide and conquer approach, which is more subtle.
* 
*               
**********************************************************************************/
#include <iostream>

using namespace std;

int maxSubarray(int A[], int n) {
  int max, tmp;
  tmp=max=A[0];
  for(int i=1; i<n; i++) {
    if(tmp>=0) tmp+=A[i];
    else tmp=A[i];
    if(tmp>max)
      max=tmp;
  }
  return max;
}
int main(void) {
  int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout<<maxSubarray(A, 9);
  return 0;
}
