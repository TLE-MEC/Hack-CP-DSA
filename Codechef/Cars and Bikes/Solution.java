
import java.util.*;
class CarsandBikes
{
	public static void main (String[] args) throws java.lang.Exception
	{

    	Scanner sc=new Scanner(System.in);
    	int T=sc.nextInt();  //Input number of test cases
    	while(T-->0)
    	{
    	    int n=sc.nextInt();//Inputting number of tyres
    	    if(n%4!=0)//if number of tyres are divisible by 4 then there can't be any bike
            System.out.println("YES");
            else
            System.out.println("NO");
    	}
	}
}
