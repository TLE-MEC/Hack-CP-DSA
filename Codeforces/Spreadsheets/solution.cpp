/*
Problem explanation:
In this problem, we have to interconvert between the two formats of naming a cell in common spreadsheets. We have n testcases and for each testcase, we can be given the cell name in either:
1) R<row_number>C<column_number>   or
2) <column_name><row_number>
eg: R23C55 and BC23 represent the same cell in the two formats respectively.

Approach;
I take the input for each testcase in the form of a string in the strinf type variable s. 
Then I check if there is any alphabet after the first occurrence of a digit.
If such an alphabet is found, the string belongs to case 2, else it is case 1.

In case1(), using stringstream, I dump the R and C characters and store the  values of row and column in r and c respectively.
Then I cnvert the column to alphabets using the while loop and concatenate it to get the result in the required format.

In case2(), exact opposite occers and I calculate the intergral value using weights of each letter and then adding to get the required result.
*/
#include <bits/stdc++.h>
using namespace std;

void case1(string s)
{
    long r,c;
    char ch;
    stringstream s1(s);
    s1>>ch;
    s1>>r;
    s1>>ch;
    s1>>c;
    // r and c store the useful values now.
    s="";// previous string is of no use for us now. So, we reuse it to store our new answer.
    s=to_string(r)+s;// Therow value os converted to string for easier handling.
    while(c>0)
        {
            r=c%26; //The remainder helps us determine the next character to be concatenated.
            if(r==0)
            {
                r=26;
                // Modulus values go from o to n-1, where n is 26. So, we will be treating 0 as our 26th letter.
                //eg: 26%26=0 It would give A_, where _ corresponds to 0.
                //So, we take a borrow and A value decreases by 1. Hence, we have 26 at ones place, which will get us the 'Z' character.
                c--;
            }   
            s=(char)((r-1)+'A')+s;
            c/=26;
            // Try running the loop on the given expample as a dry run test for better understanding.
        }
    cout<<s<<endl;
}
void case2(string s)
{
    long c,i,n=s.size(),rv=0;
    for(i=0;isalpha(s[i]);i++)
        rv=rv*26+(s[i]-'A')+1; 
        // We simply convert the alphabets to digits by putting weights.
        // eg: XYZ=> X*(26^2)+Y*(26^1)+Z*(26^0)
        // = 24*(26^2)+25*(26^1)+26*(26^0)
    s=s.substr(i,n-1);
    stringstream s1(s);
    s1>>c;
    cout<<"R"<<c<<"C"<<rv<<endl;
}
int32_t main() {
	//This is the starting point for the program.
	int t;
	cin>>t;
	//t store the number of test cases.
	while(t--) //This runs the same come t times to execute all the testcases.
	{
	    string s;
	    cin>>s; //The input for the testcase is stored in this variable.
	    long i, n=s.size(); //Here, i is the loop variable and n stores the size of string.
	    // This loop checks if we have any alphabet after the first occurrence of a digit,
	    for(i=1;i<n;i++)
	    {
	        if(isalpha(s[i]) && isdigit(s[i-1]))
	        {
	        // Case1 function is called and it does further processing.
	            case1(s);
	            break;
	        }
	    }
	    if(i==n)
	        case2(s);
	        //Case2 function is called and it does further processing.
	}
	return 0;
}
