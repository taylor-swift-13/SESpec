public class BinarySearch {

    //@ requires sortedArray != null && sortedArray.length > 0;
    //@ requires (\forall int i, j; 0 <= i && i < j && j < sortedArray.length; sortedArray[i] <= sortedArray[j]);
    //@ ensures (\result == -1) || (0 <= \result && \result < sortedArray.length && sortedArray[\result] == value);
    //@ ensures (\result == -1) <==> (value < sortedArray[0] || value > sortedArray[sortedArray.length-1] || (\forall int i; 0 <= i && i < sortedArray.length; sortedArray[i] != value));
    public static int search(int[] sortedArray, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray.length-1]) return -1;
        int lo = 0;
        int hi = sortedArray.length-1;

        //@ maintaining 0 <= lo && hi < sortedArray.length + 1;
        //@ maintaining (\forall int i; 0 <= i && i < lo; sortedArray[i] < value);
        //@ maintaining (\forall int i; hi < i && i < sortedArray.length; sortedArray[i] > value);
        //@ decreases hi - lo + 1;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (sortedArray[mid] == value) {
                return mid;
            } else if (sortedArray[mid] < value) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return -1;
    }
}