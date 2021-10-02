//
// The median is the middle value in an ordered (sorted) integer list. 
// Case 1: If the size of list is odd, then the median is the middlemost element.
// Case 2: If the size of the list is even, there is no middle value and the median is the mean of the two middle values.
//
// We can solve this problem using the concept of priority queue
// Priority queue :
// A priority queue is an abstract data type similar to a regular queue data structure
// in which each element additionally has a "priority" associated with it.

// We try to order elements such that when put one after another
// they result in sorted non- decreasing order order.
// And , our answer always lies at:
// Case 1: either the end of First queue i.e (largest element in first queue)
//       : the starting of Second queuue i.e (smallest element in second queue)
// Case 2: is the averge value of both.

class MedianFinder {
public:
    /** initialize your data structure here. */
    
    //Initializing two priority queue
    
    // stores elements in non decreasing order
    // largest element is stored at the top
    priority_queue<int> pqMax;
    
    //stores elements in non- increasing order
    // smallest element is stored at the top
    priority_queue<int,vector<int>,greater<>> pqMin;
    
    //  <....elements of pqMax>   <elements of pqMin....>
    
    // intializing median value
    double m=0;
    MedianFinder() {
        
    }
    double average(int a,int b){
        //return the average of two numbers
        
        return (double(a)+double(b))/2;
    }
    void addNum(int num) {
        
        // size of pqMax
        int szL=pqMax.size();
        
        //size of pqMin
        int szR=pqMin.size();
        
        // if size of the two queue are not equal
        if(szL!= szR){
            
            if(num>m){
                pqMin.push(num);
                szR++;
            }
            else{
                pqMax.push(num);
                szL++;
            }
            
            // rearrange the queues if they are unbalanced i.e, their size difference is greater than 1.
            // pop the top of one and push in the another queue.
            if(szL-szR>1){
                int tmp= pqMax.top();
                pqMax.pop();
                pqMin.push(tmp);
            }
            else if(szR-szL>1){
                int tmp= pqMin.top();
                pqMin.pop();
                pqMax.push(tmp);
            }
            
            // recalculate the median value 
            m= average(pqMax.top(),pqMin.top());
        }
        
        
        else {
        
        // if the size of both queue are equal , then push the new element to the left side if it is less than median 'm'.
            if(num<m){
                pqMax.push(num);
                
                // reassign the median as the largest element of left side
                m=pqMax.top();
            }
            
        // if the size of both queue are equal, then push the new element to the right side if it is greater than median 'm' 
            else
            {
                pqMin.push(num);
                
                //reassign the median as the smallest element of right side
                m=pqMin.top();
            }
        }
    }
    
    double findMedian() {
    // return median value at the point it is called
    
        return m;
    }
};

