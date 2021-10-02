import java.util.Scanner;

public class Main {

    public static int getMinSize(int sum) {

        // Initialize the counter
        int i = 0;

        // Subtract the i*i from the sum
        while (sum - Math.pow((i), 2) > 0) {
            i++;
        }

        // Return the result
        return i;

    }

    public static void main(String[] arStrings) {

        Scanner scanner = new Scanner(System.in);

        // Input the number of testcases
        int testCases = Integer.parseInt(scanner.nextLine());

        // Initialise the sum of the beautiful array to 0
        int sum = 0;

        // Loop through number_of_testcases times
        for (int testNumber = 0; testNumber < testCases; testNumber++) {

            // Input the sum value 's'
            sum = Integer.parseInt(scanner.nextLine());

            /**
             * 
             * Call the function to get the minimum size of the beautiful array created and
             * print the size
             * 
             */

            System.out.println(getMinSize(sum));
        }

        scanner.close();
    }

}
