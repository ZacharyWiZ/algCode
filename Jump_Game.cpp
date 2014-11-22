// Source : https://oj.leetcode.com/problems/jump-game/
// Author : wizzhangquan@gmail.com
// Date   : 2014-11-22

/********************************************************************************** 
* 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* 
* Each element in the array represents your maximum jump length at that position. 
* 
* Determine if you are able to reach the last index.
* 
* For example:
* A = [2,3,1,1,4], return true.
* 
* A = [3,2,1,0,4], return false.
* 
*               
**********************************************************************************/
bool canJump(int A[], int n) {
  int comp=0;
  for(int i=0; i<=comp && i<n; i++) {
    if(i+A[i]>comp)
      comp=i+A[i];
    if(comp>=n-1)
      return true;
  }
  return false;
}
