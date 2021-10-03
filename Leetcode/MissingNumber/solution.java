/* Used Cycle Sort Algorithm since missing number is in range from (0,n) 
Logic Used: Since numbers given are from (0,n) then in an sorted aray, number at i th index = index value.
*/

class Solution{
    public int missingNumber(int [] array) {
        int i = 0;
        while (i < array.length) {                                              // sorting array
            int correct = array[i] ;                                            // sorting array
            if (array[i] < array.length && array[i] != array[correct]) {        // sorting array
                swap(array, i, correct);                                        // sorting array
            } else {                                                            // sorting array
                i++;                                                            // sorting array
            }
        }
        for (int index = 0; index < array.length; index++) {
            if (array[index] != index) {   // checking if number at i th index = index value, if not then returning the index since missing element == index value
                return index;
            }
        }
        return array.length;
    }

    void swap(int [] array, int first, int second){     // Function to Swap 2 elements of the array
        int temp = array[first];
        array[first] = array[second];
        array[second] = temp;
    }
}
