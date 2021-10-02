import java.io.*;
import java.util.*;

public class MergeWithoutExtraSpace {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String inputLine[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int m = Integer.parseInt(inputLine[1]);

            int arr1[] = new int[n];
            int arr2[] = new int[m];

            inputLine = br.readLine().trim().split(" ");

            for (int i = 0; i < n; i++) {
                arr1[i] = Integer.parseInt(inputLine[i]);
            }

            inputLine = br.readLine().trim().split(" ");

            for (int i = 0; i < m; i++) {
                arr2[i] = Integer.parseInt(inputLine[i]);
            }

            new MergeWithoutExtraSpace().merge(arr1, arr2, n, m);

            StringBuffer str = new StringBuffer();
            for (int i = 0; i < n; i++) {
                str.append(arr1[i] + " ");
            }
            for (int i = 0; i < m; i++) {
                str.append(arr2[i] + " ");
            }
            System.out.println(str);
        }
    }

    static void swap(int[] arr1, int[] arr2, int a, int b) {
        int temp = arr1[a];
        arr1[a] = arr2[b];
        arr2[b] = temp;
    }

    static int gap(int gap) {
        return (gap%2 == 0 || gap == 1) ? gap/2 : (gap/2) + 1;
    }

     void merge(int arr1[], int arr2[], int n, int m) {
        int gap = m+n;
        for(gap = gap(gap); gap>=1; gap = gap(gap)) {
            int i = 0;
            int j = gap;
            while(i<n && j<n) {
                if(arr1[i] > arr1[j] )
                    swap(arr1,arr1,i,j );
                i++;j++;
            }
            j = (gap>n) ? gap-n : 0;
            while(i<n && j<m) {
                if(arr1[i] > arr2[j] )
                    swap(arr1,arr2,i,j );
                i++;j++;
            }
            if(j<m) {
                j=0;
                while(j+gap < m) {
                    if(arr2[j] > arr2[j+gap] )
                        swap(arr2,arr2,j+gap,j );
                    j++;
                }
            }
        }
    }
    }// } Driver Code Ends

