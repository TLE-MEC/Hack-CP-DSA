//Approach 

// Step 1: Create an empty Stack and a vector
// Step 2: iterate from beginning of given array
// Step 3: while stack is not empty and top of stack is greater than or equal to current array element , pop from stack
// Step4: if stack is empty after above statement then push -1 in resultant vector else push top of stack in resultant vector
// Step 5:push current element in stack
// Step 6: iterate till end of array while following steps 3-5


vector<int> Solution::prevSmaller(vector<int> &A) 
{
    int n = A.size();
    vector<int> right(n, -1); // create the answer list and initialize all of it's values as -1
    stack<int> s; // create a stack
    
    for(int i = 0; i<n; i++)
    {
        // if the stack is not empty and the current value is less than the value on top of the stack, we pop 
        // it out because we won't be going beyond the current minimum point
      
        while(!s.empty() && A[i] <= A[s.top()]) 
            s.pop();

        // if the value is greater than preceding value, put the value which is at the top of the stack at the 
        //position of the current element

        if(!s.empty() && A[i] > A[s.top()])
            right[i] = A[s.top()];

        // push the current element in the stack    

        s.push(i);
    }

    // return the final array 

    return right;
}

//Time Complexity : O(n)
//Time complexity of above program is O(n) as every element is pushed and popped at most once to the stack.

