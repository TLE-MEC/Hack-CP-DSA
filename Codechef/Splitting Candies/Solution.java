// We are given: 
//-no of candies
//-no of students
//Objective: is to divide the candies among the kids evenly and give the remaining candies to teacher.
//Approach: Easy to understand for beginners.
// TIME COMPLEXITY: O(n)
import java.util.*;
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);//Create object and import Scanner class
        int t = sc.nextInt();//Input no. of test cases
        while(t-->0){
            long n = sc.nextLong();//Input no. of candies
		    long k = sc.nextLong();//Input no. of students
            if(k==0){
                System.out.println(0+" "+n);//If kids are 0 then give all the candies to teacher
            }
            else {
                long students = n / k;//else give same amount of candies to all the kids
                long teacher = n % k;//and remaining candies to teacher.
                System.out.println(students + " " + teacher);//Print result
            }
        }
        sc.close();
	}
}
// Example
// Input:
// 2
// 10 2
// 100 3
// Output:
// 5 0
// 33 1