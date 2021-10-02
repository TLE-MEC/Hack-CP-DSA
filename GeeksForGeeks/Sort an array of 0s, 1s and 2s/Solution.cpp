// Time complexity :- O(n)
// As the array is traversed only once therefore, the time complexity of the algorithm is O(n).

// Space complexity :- O(1)
// As no extra space is used therefore, the space complexity of the algorithm is O(1).

#include<iostream>
using namespace std;


void DNFsort(int array[], int n) // n is the size of the array  
{  
    int low = 0;    
    int mid = 0;  
    int high = n - 1;
      
      //Iterate till (mid<=high)

    while (mid <= high)  
    {  
        switch (array[mid])  
        {  
              
        case 0:  
            swap(array[low], array[mid]);
            low++;
            mid++;  
            break;  
                
        case 1:  
            mid++;  
            break;  
               
        case 2:  
            swap(array[mid], array[high]);
            high--;  
            break;  
        }  
    }  
}  

int main()
{
    int n;
    cout<<"Enter size of array:";
    cin>>n;

    int array[n];
    
    cout<<"Enter elements :";
    for(int i=0;i<n;i++)
    cin>>array[i];

    DNFsort(array,n);
    cout<<"Sorted Array:\n";
    for(int i=0;i<n;i++)
    cout<<array[i]<<" ";
    
    return 0;

}