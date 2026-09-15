public class BinarySearch {

    //@ requires sortedArray != null && sortedArray.length > 0;
    //@ assignable \nothing;
    //@ ensures (\result == -1) || (0 <= \result && \result < sortedArray.length && sortedArray[\result] == value);
    //@ ensures (value < sortedArray[0] || value > sortedArray[sortedArray.length-1]) ==> \result == -1;
    public static int search(int[] sortedArray, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray.length-1]) return -1;
        int lo = 0;
        int hi = sortedArray.length-1;

        //@ maintaining 0 <= lo && lo <= sortedArray.length;
        //@ maintaining -1 <= hi && hi < sortedArray.length;
        //@ maintaining lo <= hi + 1;
        //@ maintaining (lo > 0 ==> sortedArray[lo-1] < value);
        //@ maintaining (hi < sortedArray.length - 1 ==> sortedArray[hi+1] > value);
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