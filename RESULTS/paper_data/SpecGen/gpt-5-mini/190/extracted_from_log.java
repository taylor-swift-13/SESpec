public class BinarySearch {

    /*@ requires sortedArray != null && sortedArray.length > 0; @*/
    /*@ requires (\forall int i; 0 <= i && i+1 < sortedArray.length; sortedArray[i] <= sortedArray[i+1]); @*/
    /*@ ensures \result >= -1 && \result < sortedArray.length; @*/
    /*@ ensures \result >= 0 ==> sortedArray[\result] == value; @*/
    /*@ ensures (\forall int i; 0 <= i && i < sortedArray.length; sortedArray[i] != value) ==> \result == -1; @*/
    public static int search(int[] sortedArray, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray.length-1]) return -1;
        int lo = 0;
        int hi = sortedArray.length-1;

        //@ maintaining 0 <= lo && lo <= sortedArray.length;
        //@ maintaining -1 <= hi && hi < sortedArray.length;
        //@ maintaining lo <= hi + 1;
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