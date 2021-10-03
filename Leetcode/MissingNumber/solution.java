class Solution{
    public int missingNumber(int [] array) {
        int i = 0;
        while (i < array.length) {
            int correct = array[i] ;
            if (array[i] < array.length && array[i] != array[correct]) {
                swap(array, i, correct);
            } else {
                i++;
            }
        }
        for (int index = 0; index < array.length; index++) {
            if (array[index] != index) {
                return index;
            }
        }
        return array.length;
    }

    void swap(int [] array, int first, int second){
        int temp = array[first];
        array[first] = array[second];
        array[second] = temp;
    }
}
