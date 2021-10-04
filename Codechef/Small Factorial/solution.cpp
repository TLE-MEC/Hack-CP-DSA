#include <iostream>
using namespace std;

//since it is not possible to store such big number in a int variable
//we are using an array of integers to represent one number
//where each array item will obviously be each digit 

//initilazing to zero
void zero(int a[])
    {
        for(int i=0;i<200;i++)
            {
                a[i]=0;
            }
    }

//a function to add 2 numbers reperesented using arrays
void add(int x[],int y[])
    {
        int xt=0,t,i;
        for(i=0;i<200;i++)
            {
            t=x[i]+y[i]+xt;
            x[i]=t%10;
            xt=t/10;
            }
    }

//function to print the number
void show(int a[])
        {
            int x,i;
            for(i=199;i>=0;i--)
                cout<<a[i];
            cin>>x;
        }

//function to multiply one number represented as array with one digit represented with an integer
void mult(int a[],int n)
    {

        int z;
        int f[200],s[200],i,b=0,tp;
        zero(f);
        zero(s);
        int t=(n/10);
        int o=n%10;
        //multiplying first digit
        for(i=0;i<200;i++)
            {
                tp=a[i]*o+b;
                f[i]=tp%10;
                b=tp/10;
            }
        b=0;
        //multiplying second digit digit , so it will have 0 in the end
        for(i=0;i<199;i++)
            {
                tp=a[i]*t+b;
                s[i+1]=tp%10;
                b=tp/10;
            }
            //adding them
        add(f,s);
        for(i=0;i<200;i++)
            {
                a[i]=f[i];
            }

    }

int main() {
	int a[200],x,c,i,f;
	zero(a);
	a[0]=2;
	cout<<endl;
	cin>>c;
    while(c)
	    {
	        zero(a);
	        a[0]=1; //setting the product number to 1
	        c--;
	        f=0;
	        cin>>x;
	        for(;x>0;x--)
            {
                mult(a,x); //multiplying that number with x whose value will be decremented and multiplied again to get factorial
            }
	       cout<<endl;
	       for(i=199;i>=0;i--)
	            {
	                if(f==0&&a[i]==0)
	                    continue;
	               else
	                    {
	                        cout<<a[i];
	                        f=1;
	                    }

	            }
            cout<<endl<<endl;
	    }

	return 0;
}