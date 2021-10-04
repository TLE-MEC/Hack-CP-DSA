//Since before rotation, the array was sorted, this means that we can use binary search.
//In a binary search algorithm, we have three indexes, low, mid and high.
//The mid variable divides the array into two part, one is [low,mid] and another is [mid,high].

int Solution::search(const vector<int> &A, int B) {
    int l=0,r=A.size()-1;
    
    while(l<=r){
        int mid = (l+r)/2; 
        
        // Found Cut
        if(A[mid]==B) return mid;
        
        if(A[l]<=A[mid]){ // That means A[l] to A[mid] is sorted.
        
            if(A[l]<=B && B<A[mid]){ // That means B lies between [A[l],A[mid])
                r = mid-1;
            }
            else{   // That means B lies between (A[mid],A[r]]
                l = mid+1;
            }
        }
        else{ // A[mid] to A[r] is sorted.
            
            if(A[mid]<B && B<=A[r]){ // That means B lies between (A[mid],A[r]]
                l = mid+1;
            }
            else{ // That meanse B lies between [A[l],A[mid])
                r = mid-1;
            }
        }
    }
    return -1;
}