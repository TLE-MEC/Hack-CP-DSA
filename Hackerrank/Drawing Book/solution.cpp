#include <bits/stdc++.h>
using namespace std;


int pageCount(int n, int p) {

    // n = number of pages of the book
    // p = tatget page

    // The idea is count the number of flip nedded if you want to go to target page from front page
    // and from endpage . And take the minimum of them .
    
    int flip_from_front = p/2; //this counts the flips from front
    int flip_from_end ;

    // to count the flip from end we have two cases 

    if((n%2)==0){
        // if number of page n is even
        flip_from_end = (n-p+1)/2;
    }else{
        // if number of page n is odd
        flip_from_end = (n-p)/2;
    }
    // now return the minimum of the counts
    return min(flip_from_front,flip_from_end);

}