// Source : https://oj.leetcode.com/problems/maximum-product-subarray/
// Author : wizzhangquan@gmail.com
// Date   : 2014-11-06
/*****************************************************************
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 *****************************************************************/


#include <iostream>
#include <algorithm>
using namespace std;
int maxProduct(int A[], int n){
  int max_prev, min_prev,
    max_here, min_here,
    max_new;
  max_prev=min_prev=A[0];
  max_here=min_here=max_new=A[0];
  for(int i=1; i<n; i++) {
    max_here = max(min_prev*A[i], max(max_prev*A[i], A[i]));
    min_here = min(min_prev*A[i], min(max_prev*A[i], A[i]));
    max_prev=max_here;
    min_prev=min_here;
    max_new=(max_new>max_here?max_new : max_here);
  }
  return max_new;
}
