// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : wizzhangquan@gmail.com
// Date   : 2014-10-24

/***********************************************************************************************
 *
 * Given a sorted array, remove the duplicates in place such that each element appear 
 * only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 *
 ***********************************************************************************************/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int flag=0;
        if(n==0) return 0;//这里一定要注意n=0的情况
        for(int i=1; i<n; i++) {
        	if(A[i]!=A[flag]) {
        		A[++flag]=A[i];
        	}
        }
        return flag+1;
    }
};