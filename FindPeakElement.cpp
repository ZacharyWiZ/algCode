// Source : https://oj.leetcode.com/problems/find-peak-element/
// Author : wizzhangquan@gmail.com
// Date   : 2014-12-06

/********************************************************************************** 
* 
* A peak element is an element that is greater than its neighbors.
* 
* Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.
* 
* You may imagine that num[-1] = num[n] = -¡Þ.
* 
* For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
* 
* click to show spoilers.
* 
* Note:
* Your solution should be in logarithmic complexity.
* 
* Credits:Special thanks to @ts for adding this problem and creating all test cases.
*               
**********************************************************************************/
/*********************************************************************************
int findPeakElement(const vector<int> &num) {
  int len=num.size();
  if(num.size()==1)
    return num[0];
  if(num[0]>num[1])
    return num[0];
  if(num[len-1]>num[len-2])
    return num[len-1];
  for(int i=1; i<len-1; ){
    if(num[i]>num[i-1] && num[i]>num[i+1])
      return num[i];
    if(num[i]>=num[i+1])
      i+=2;
    else 
      i++;
  }
}
*********************************************************************************/
int findPeakElement(const vector<int> &num) {
  int low=0, high=num.size()-1, mid;
  if(num.size()==1)
    return 0;
  if(num[0]>num[1])
    return 1;
  if(num[high]>num[high-1])
    return high;
  
  while(low <= high) {
    if(low==high)
      return low;
    mid=(low+high)>>1;
    if(num[mid]>num[mid-1]  &&  num[mid]>num[mid+1])
      return mid;
    if(num[mid]<num[mid+1])
      low=mid+1;
    else 
      high=mid-1;
  }
}
