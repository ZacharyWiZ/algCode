/// Source : https://oj.leetcode.com/problems/plus-one/
// Author : wizzhangquan@gmail.com
// Date   : 2014-10-27

/****************************************************************** 
 *
 *    Given a non-negative number represented as an array of digits,
 *    plus one to the number.
 *
 *	  给你一个用数组表示的数，求加一之后的结果，结果还是用数组表示。
 *    The digits are stored such that the most significant digit is 
 *    at the head of the list.
 *
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
        int flag=1;
        for(int i=digits.size()-1; i>=0; i--) {
            if(flag==1) {
                digits[i]+=flag;
                flag=digits[i]/10;
                digits[i]%=10;
                cout<<"digits["<<i<<"]: "<<digits[i]<<" && flag="<<flag<<endl;
            }else break;
        }
        if(flag==1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }

void printVector(vector<int>& v)
{
    cout << "{ ";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "} " << endl;
}


int main()
{
    int a[]={9,9,9};
    vector<int> d(&a[0], &a[0]+sizeof(a)/sizeof(int));
    vector<int> v = plusOne(d);
    printVector(v);
    return 0;
}
