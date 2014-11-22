// Source : https://oj.leetcode.com/problems/jump-game-ii/
// Author : wizzhangquan@gmail.com
// Date   : 2014-11-22

/********************************************************************************** 
* 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* 
* Each element in the array represents your maximum jump length at that position. 
* 
* Your goal is to reach the last index in the minimum number of jumps.
* 
* For example:
* Given array A = [2,3,1,1,4]
* 
* The minimum number of jumps to reach the last index is 2. 
* (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
* 
*               
**********************************************************************************/

int jump(int A[], int n) {
  int comp=A[0];
  int jump=0;
  int m, i=0;
  if(n<=1) 
    return 0;
  
  while(i<comp && i<n) {
    jump++;
    if(comp>=n-1)
      return jump;
    
    for(int j=i, m=i; j<=comp; j++)
      if(m+A[m]<j+A[j])
	       m=j;
    comp=A[m]+m;
    i=m;
  }
  return 0; 
}
