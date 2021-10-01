
/*Input Format

The first line contains two space-separated integers denoting the respective values of  (the number of variable-length arrays) and  (the number of queries).
Each line  of the  subsequent lines contains a space-separated sequence in the format k a[i]0 a[i]1 … a[i]k-1 describing the -element array located at .
Each of the  subsequent lines contains two space-separated integers describing the respective values of  (an index in array ) and  (an index in the array referenced by ) for a query.

Constraints

All indices in this challenge are zero-based.
All the given numbers are non negative and are not greater than
Output Format

For each pair of  and  values (i.e., for each query), print a single integer that denotes the element located at index  of the array referenced by . There should be a total of  lines of output.
///////////////////////////
Sample Input 1

2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3
Sample Output 1

5
9
/////////////////////////////
Sample Input 2
2 3
2 5 0
7 1 2 3 5 4 6 7
1 5
0 0

Sample Output 2
6
5
//////////////////////////////
*/
//solution:-
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  // creating nao variable  :- number of arrays
  // creating noo variable  :- number of operations to be performed (on arrays)
  // creating var :- number of elements in array
    int noa, noo, var;
    
    cin>>noa;
    cin>>noo;
    int **dpnoa;
    // created double pointer to nao
    // now creating a 2D array using malloc
    dpnoa= (int**)malloc(noa * sizeof(int*));
    // created nao number of arrays of pointers

    //running a for loop for nao number of arrays and assigning each one with respective var
    for(int i=0; i< noa ; i++)
    {
        cin>>var;
        *(dpnoa+i)=(int*)malloc(var * sizeof(int));
        for(int j=0 ; j<var ; j++)
        {
            // assigning elements in respective array
            cin>>dpnoa[i][j];

        }

    }
    // number of operations to be performed on array
    for(int k=0; k<noo ; k++)
    {
        int ask1,ask2;
        cin>>ask1;
        cin>>ask2;

        cout<< dpnoa[ask1][ask2]<<endl;

    }

    return 0;
}
