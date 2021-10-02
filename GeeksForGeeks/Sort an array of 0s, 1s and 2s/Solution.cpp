//Concept:- Dutch National Flag problem

//We will make 3 pointers low, mid and high
//low = mid = array[0] and high = array[n-1]
//Iterate till (mid<=high)
//If array[mid] = 0 then swap array[low] with array[mid] and increment low and mid by 1 i.e (low=low+1 and mid=mid+1)
//if array[mid] = 1 just increment mid by 1 i.e (mid=mid+1)
//if array[mid] = 2 then swap a[mid] with a[high] and Decrement high by 1 i.e (high=high-1)

// Time complexity :- O(n)
// As the array is traversed only once therefore, the time complexity of the algorithm is O(n).

// Space complexity :- O(1)
// As no extra space is used therefore, the space complexity of the algorithm is O(1).


#include<iostream>
using namespace std;

void DNFsort(int array[], int n) // n is the size of the array  
{  
    int low = 0;         //first element of array
    int mid = 0;         //first element of array
    int high = n - 1;    //last element of array
      
      //Iterate till (mid<=high)

    while (mid <= high)  
    {  
        switch (array[mid])  
        {  
              
        case 0:  
            swap(array[low], array[mid]);
            low++;      // incrementing low by 1
            mid++;      // incrementing mid by 1
            break;  
                
        case 1:  
            mid++;      // incrementing mid by 1
            break;  
               
        case 2:  
            swap(array[mid], array[high]);
            high--;     // decrementing high by 1
            break;  
        }  
    }  
}  

int main()
{
    int n;
    cout<<"Enter size of array:";
    cin>>n;

    int array[n];           //array of n elements containing only 0s , 1s and 2s
    
    cout<<"Enter elements :";
    for(int i=0;i<n;i++)
    cin>>array[i];

    DNFsort(array,n);       //calling the sorting function to sort the array

    cout<<"Sorted Array:\n";
    for(int i=0;i<n;i++)
    cout<<array[i]<<" ";    //printing the sorted array
    
    return 0;

}