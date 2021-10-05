#include <iostream>
using namespace std;

int main() {
    int T,N,a[50],i,j,f,HCF,small=2000;
    cin>>T; //input no of testcases
    while(T--)
        {
        small=2000;
        //input number of ingredients
        cin>>N;
        //inputing N number of ingredient quantity
        for(i=0;i<N;i++)
            {
            cin>>a[i];
            if(a[i]<small)
                small=a[i];
            }
            //an if stmt to find the smallest number
            //starting with the smallest number, we try to find the HCF
        for(j=small;j>0;j--)
            {
                f=0;
                for(i=0;i<N;i++)
                    if(a[i]%j!=0)
                        {
                            f=1;
                            break;
                        }
                if(f==0)
                    {
                    HCF=j; 
                    break;
                    }
            }
            //then we divide everything by the HCF found, which is the answer array
        for(i=0;i<N;i++)
            {
                a[i]/=HCF;
                cout<<a[i]<<" ";
            }
        cout<<endl;
        }
	return 0;
}