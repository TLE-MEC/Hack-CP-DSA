public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    int totalLength = nums1.length + nums2.length;

    // if we merged both arrays, this would be the index containing the median (if totalLength is even, it would give the "last" median index)
    var indexAtMedian = (totalLength / 2);

    // counters to keep up with "merging" both arrays (we actually do not care with the merged array, just the value at median)
    var i = 0;
    var j = 0;

    // hold values of the two latest values at the median index (in case totalLength is even)
    var beforeMedian = 0;
    var medianIfOdd = 0;

    for (int pos = 0; pos <= indexAtMedian; pos++) {
        int valueAtPos = 0;
        if (i < nums1.length && (j >= nums2.length || nums1[i] <= nums2[j])) {
            valueAtPos = nums1[i];
            i++;
        } else {
            valueAtPos = nums2[j];
            j++;
        }

        if (pos == indexAtMedian - 1) {
            beforeMedian = valueAtPos;
        }
        if (pos == indexAtMedian) {
            medianIfOdd = valueAtPos;
        }
    }

    var isEven = totalLength % 2 == 0;

    if (isEven) {
        return ((double) beforeMedian + (double) medianIfOdd) / 2;
    } else {
        return medianIfOdd;
    }
}
