/*

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.


 */

public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    int index1 = 0;
    int index2 = 0;
    int med1 = 0;
    int med2 = 0;

//        using merge sort algorthim here to sort the array 

    for (int i=0; i<=(nums1.length+nums2.length)/2; i++)
    {
            med1 = med2;
        if (index1 == nums1.length)
        {
            med2 = nums2[index2];
            index2++;
        }
        else if (index2 == nums2.length)
        {
            med2 = nums1[index1];
            index1++; //updating index1 as we move to the next iteration
        }
        else if (nums1[index1] < nums2[index2] )
        {
            med2 = nums1[index1];
            index1++;
     }
        else
        {
            med2 = nums2[index2];
            index2++;
        }
        }

    // the median is the average of two numbers
    if ((nums1.length+nums2.length)%2 == 0)
    {
        return (float)(med1+med2)/2;
    }

    return med2;
    }