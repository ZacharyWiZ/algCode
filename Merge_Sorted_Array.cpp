// Source : https://oj.leetcode.com/problems/merge-sorted-array/
// Author : wizzhangquan@gmail.com
// Date   : 2014-10-25
/***************************************************************
 *Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 *Note:
 *You may assume that A has enough space (size that is greater or equal to m + n)
 *to hold additional elements from B. The number of elements initialized in A and
 * B are m and n respectively.
 *
 ***************************************************************/
#include <iostream>
using namespace std;

void merge(int A[], int m, int B[], int n) {
    int i, j, k;
    for(i=m-1,j=n-1,k=m+n-1; k>=0; k--){
        if(i!=-1&&j!=-1) {
            if(A[i]<B[j]){
                A[k]=B[j--];
            }else {
                A[k]=A[i--];
            }
        }
        else if(i==-1&&j!=-1) {
        	A[k]=B[j--];
        }else {
        	return ;
        }
    }
 }
void printf_array(int A[], int n){
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";
        cout<<endl;
}
int main() {
    int A[9]={1,2,4,7,9,0,0,0,0};
    int B[4]={3,5,6,8};
    merge(A,5,B,4);
    printf_array(A, 9);
    return 0;
}
