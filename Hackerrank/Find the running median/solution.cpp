#include <bits/stdc++.h>

using namespace std;

/*  create two heaps to store max heap and min heap
    max heap consist of value lower than median and min value consists of higher value
    the method to get the value in the middle(median) of array*/
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void runningMedian(double number, double &median) {
    
    // case 1, lower values are more than higher values
    if (minHeap.size() < maxHeap.size()){
        // check if entered number is bigger or smaller than previous median
        if (number<median){
            // move the last value in maxHeap to minHeap because the new value is smaller
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(number);
        }
        else
            minHeap.push(number);
        
        // get the average value because there is even number in the array
        median = ((double) maxHeap.top() + (double)minHeap.top())/2.0;
    }
    
    //case 2, higher values are more than lower values
    else if (minHeap.size() > maxHeap.size()){
        // check if entered number is bigger or smaller than previous median
        if (number>median){
            // move the last value in maxHeap to minHeap because the new value is smaller
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(number);
        }
        else
            maxHeap.push(number);

        // get the average value because there is even number in the array
        median = ((double) maxHeap.top() + (double)minHeap.top())/2.0;
    }
    
    //case 3
    else{
        // check if entered number is bigger or smaller than previous median
        if (number<median){
            // assign the number to the lower value heap and the new median
            maxHeap.push(number);
            median = (double) maxHeap.top();
        }
        else{
            // assign the number to the higher value heap and the new median
            minHeap.push(number);               
            median = (double) minHeap.top();    
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    double median = 0;
    double value;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        runningMedian(value, median);
        fout << setprecision(1) << fixed << median << endl;
    }
    fout << "\n";

    fout.close();

    return 0;
}
