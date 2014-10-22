#include <iostream>
using namespace std;
int main() {
    double a=5,b=3,c=1.0/3;
    int x, y, z, n;
    while(cin>>n && n!=0) {
        if(33>n) return 1;
        else {
            /*cout<<"x=0,y=0,z=100"<<endl;
            if(n>=36)
                for(int i=1; i*3+c*(100-i)<=n; i++)
                    cout<<"x=0,y="<<i<<",z="<<(100-i)<<endl;
            if(n>=38) {
                for(int i=1,j=0; 5+j*3+c*(100-j-i)<=n; i++) {
                    for(; i*5+j*3+c*(100-i-j)<=n; j++)
                        cout<<"x="<<i<<",y="<<j<<",z="<<(100-i-j)<<endl;
                }
            }*/
            for(x=0; 5*x<n; x++)
                for(y=0; 3*y<n; y++) {
                    z=100-x-y;
                    if((z*c+5*x+3*y<=n) && z>=0)
                        cout<<"x="<<x<<",y="<<y<<",z="<<z<<endl;
                }
        }
    }
    return 0;
}
