// We are given: 
//-no of elements
//-no of elements in one group
//-weight of elements

//Objective: is to find the max possible difference between the weight that son and father will carry
//Approach: Easy to understand for beginners.

// TIME COMPLEXITY: O(n^2)

import java.util.*;


class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scan = new Scanner(System.in);//We import the Scanner class and make the scanner class object
        int t = scan.nextInt();//Take input for no. of test cases
        while(t-->0){
            int n = scan.nextInt();//take the input for no. of items
            int s = scan.nextInt();//take the input for no. of Groups
            int[] array = new int[n];//create an array to store n items
            for(int i=0 ; i<n ; i++){//loop to take input for those n items
                array[i]=scan.nextInt();
            }
            Arrays.sort(array);//then sort the array so that less weight items comes to the front of the array
            int sonSum=0,fatherSum=0;
            if(s<=n-s) {//check this condition
                for (int j = 0; j < s; j++) {//loop it for the first group, as we know that the array is sorted and hence the less weight objects are in the beginning and hence the first group will be lighter so that son can carry it.
                    sonSum += array[j];
                }
                for (int k = s; k < n; k++) {//then we loop adn add the remaining objects to father sum, (this is the heavier part, and hence for father)
                    fatherSum += array[k];
                }
            }
            else{//if the is condition fails
                for (int j = 0; j < n-s; j++) {//same as above for these loops
                    sonSum += array[j];
                }
                for (int k = n-s; k < n; k++) {
                    fatherSum += array[k];
                }
            }
            int difference = fatherSum-sonSum;//subtract for the difference
            System.out.println(difference);//print it, and it is the maximum possible difference for the problem
        }
        scan.close();
	}
}

// Example:
//
// Input:
// 2
// 5 2
// 8 4 5 2 10
// 8 3
// 1 1 1 1 1 1 1 1
//
// Output:
// 17
// 2