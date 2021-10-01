#include<bits/stdc++.h>
using namespace std;

int main(){

	/*
    My approach:
    We intialise Page Number 1 with index 1
    Page Number 2 and 3 with index 2
    Page Number 4 and 5 with index 3
    and so on....
    Then we find index of Page Number p and last page.
    Subsequently we find the Number of pages to turn when started from start and end.
    The minimum of both will be our required answer.
    Time complexity: O(1)
    */

    int n;
    cin >> n;

    int p; 
    cin >> p; 

    //The index on which page number p is situated.
    int v1 = ceil((p+1)/2.0);
    //The index on which last page is situated.
    int v2 = ceil((n+1)/2.0);

    int fromStart = (v1-1); //Number of pages to turn when started from start.
    int fromLast = (v2-v1); //Number of pages to turn when started from end.
    int answer = min(fromStart, fromLast); //Minimum of both will be our answer.
    
    cout << answer << "\n";

    return 0;
}
