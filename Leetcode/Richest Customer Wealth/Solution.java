class Solution {
    public int maximumWealth(int[][] accounts) {
        
        
        int cost[]=new int[accounts.length];//Created a new array to store cost//
        for(int i=0;i<accounts.length;i++){//For loop to traverse through the customers//
            int sum=0;//for every new customer the sum of the wealth should start from 0//
            for(int j=0;j<accounts[0].length;j++){//for loop to traverse through the money stored in each bank of a customer//
                sum=sum+accounts[i][j];//Claculating walth//
                
            }
            cost[i]=sum;//Appending the value of wealth in the cost array//
        }
     Arrays.sort(cost);//Sorting the cost array//
     return (cost[cost.length-1]); //Accessing the last value of the sorted array to get the maximum wealth//  
    }
}