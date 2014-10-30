// Source : https://oj.leetcode.com/problems/pascals-triangle-ii/
// Author : wizzhangquan@gmail.com
// Date   : 2014-10-30
/*****************************************************************
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *****************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
 * 递归
int getNum(int row, int index);
vector<int> getRow(int rowIndex) {
	vector<int> a(rowIndex);
	int half_len= (rowIndex+1)/2;
	for(int i=0; i<half_len; i++) {
		a[i]=getNum(rowIndex, i);
		a[rowIndex-1-i]=a[i];
	}
	return a;
}
int getNum(int row, int index) {
	if(row==1 && index==0)
		return 1;
	if(index==0 || index==row-1)
		return 1;
	return getNum(row-1, index-1)+getNum(row-1, index);
}*/
/*
 *这种方法用了二项式的方法，这样就一个循环就能搞定，但是大数问题随着相乘出现了
 * 但这不失为一种好方法
 *vector <int> getRow(int rowIndex) {
	vector<int> a(rowIndex+1);
	int half_len= (rowIndex+2)/2;
	for(int i=0; i<half_len; i++) {
		if(i==0) a[i]=1;
		else if(i==1) a[i]=rowIndex;
		else{
			a[i]=(a[i-1]/i)*(rowIndex-i+1);
		}
		a[rowIndex-i]=a[i];
		cout<<a[i]<<endl;
	}
	return a;
}*/
/*
 *这种方法以倒着加值以保证row(n+1)的数字不会覆盖到需要用到的row(n)的值
 *但效率不高
 */
vector <int> getRow(int rowIndex){
	vector<int> a(rowIndex+1);
	for(int i=a[0]=1; i<=rowIndex; i++)
		a[i]=0;
	for(int i=1;i<=rowIndex; i++)
		for(int j=i; j>0; j--)
			a[j]+=a[j-1];
	return a;
}
int main(){
	getRow(5);
	return 0;
}