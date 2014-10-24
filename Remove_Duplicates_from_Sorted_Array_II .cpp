// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : wizzhangquan@gmail.com
// Date   : 2014-10-24

/************************************************************************************
 *
 *Follow up for "Remove Duplicates":
 *What if duplicates are allowed at most twice?
 *
 *For example,
 *Given sorted array A = [1,1,1,2,2,3],
 *
 *Your function should return length = 5, and A is now [1,1,2,2,3].
 *
 *************************************************************************************/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int flag=0;
        if(n==0) return 0;//这里一定要注意n=0的情况
        for(int i=1; i<n; i++) {
        	if(A[i]!=A[flag]) {
        		A[++flag]=A[i];
        	}else if(A[i]!=A[flag-1]) {
        		A[++flag]=A[i];
        	}
        }
        return flag+1;
    }
};