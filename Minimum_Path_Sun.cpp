// Source : https://oj.leetcode.com/problems/minimum-path-sum/
// Author : wizzhangquan@gmail.com  
// Date   : 2014-10-30

/********************************************************************************** 
* 
* Given a m x n grid filled with non-negative numbers, find a path from top left to 
* bottom right which minimizes the sum of all numbers along its path.
* 
* Note: You can only move either down or right at any point in time.
*               
**********************************************************************************/

#include <iostream>
#include <vector>
/*递归不可取，因为可以减边，最上和最左边可以直接得到。
int minPathSum(vector<vector<int> > &grid){
  int n,m,minSum1,minSum2;
  m = grid.size();
  n = grid[0].size();
  minSum1=get_node(grid,m,n,0,0,0);
  minSum2=get_node(grid,m,n,0,0,1);
  return minSum1>minSum2?minSum2:minSum1;
}
int get_node(vector<vector<int> >&grid, int m,int n, int i, int j, int direction){
  /* direnction: 0->right
   *            1->down
   * return: the pathnum or -1:no path
   */
  /*
  int right_num, down_num;
  if(i==(m-1) && j==(n-1))
    return grid[i][j];
  if(direction == 1) //down
    if(i<m){
      right_num=get_node(grid,m,n,i+1,j,0);
      down_num=get_node(grid,m,n,i+1,j,1);
      if(right_num == -1)
	if(down_num == -1)
	  return -1;
        else return down_num+grid[i][j];
      else 
	if(down_num == -1)
	  return right_num+grid[i][j];
        else 
	  return (down_num>right_num? right_num: down_num) + grid[i][j];
    }else 
      return -1;
  if(direction == 0) //left
     if(j<n){
      right_num=get_node(grid,m,n,i,j+1,0);
      down_num=get_node(grid,m,n,i,j+1,1);
      if(right_num == -1)
	if(down_num == -1)
	  return -1;
        else return down_num+grid[i][j];
      else 
	if(down_num == -1)
	  return right_num+grid[i][j];
        else 
	  return (down_num>right_num? right_num: down_num) + grid[i][j];
    }else 
      return -1;
}*/
//动态规划
int minPathSum(vector<vector<int> > &grid) {
  int m, n;
  //int a[10000][10000];
  m=grid.size();
  n=grid[0].size();
  //if(m==0 || n==0)  return 0;
  //a[0][0]=grid[0][0];
  for(int i=1; i<m; i++)
    grid[i][0]=grid[i-1][0]+grid[i][0];
  for(int i=1;i<n;i++)
    grid[0][i]=grid[0][i-1]+grid[0][i];
  for(int i=1;i<m;i++)
    for(int j=1;j<n;j++)
      grid[i][j]+=(grid[i][j-1]>grid[i-1][j]?grid[i-1][j]:grid[i][j-1]);
  return grid[m-1][n-1];
}


int main()
{
    int a[6][2]={{7,2},{6,6},{8,6},{8,7},{5,0},{6,0}};
    vector< vector<int> > grid;
    for(int i=0; i<6; i++){
        vector<int> v;
        for(int j=0; j<2; j++){
            v.push_back(a[i][j]);
        }
        grid.push_back(v);
    }
    cout<<minPathSum(grid);
    return 0;
}
