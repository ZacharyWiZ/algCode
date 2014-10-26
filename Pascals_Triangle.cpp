// Source : https://oj.leetcode.com/problems/pascals-triangle/
// Author : wizzhangquan@gmail.com
// Date   : 2014-10-27

/********************************************************************************** 
* 
* Given numRows, generate the first numRows of Pascal's triangle.
* 
* For example, given numRows = 5,
* Return
* 
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
* 
*               
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
	vector<vector<int>> triangle;
	for(int i=1; i<=numRows; i++){
		vector<int> row(i);
		if(i==1) 
			row[0]=1;
		else {
			row[0]=row[i-1]=1;
			for(int j=1; j<i-1;j++) 
				row[j]=triangle[i][j-1]+triangle[i][j];
		}
		triangle.insert(triangle.end(), row);
		for(int k=0; k<row.size(); i++)
			cout<<row[k]<<" ";
		cout<<endl;
	}
	return triangle;
}
int main(void) {
	generate(5);
	return 0;
}