public class BinarySearch {

    /*@ 
      @ requires sortedArray != null;
      @ requires sortedArray.length > 0;
      @ requires (\forall int i; 0 <= i && i < sortedArray.length - 1; sortedArray[i] <= sortedArray[i+1]);
      @ ensures \result == -1 || (0 <= \result && \result < sortedArray.length && sortedArray[\result] == value);
      @*/
    public static int search(int[] sortedArray, int value) {
        int lo = 0;
        int hi = sortedArray.length - 1;

        /*@ 
          @ maintaining 0 <= lo && lo <= hi + 1 && hi < sortedArray.length;
          @ maintaining (\forall int i; 0 <= i && i < lo; sortedArray[i] < value);
          @ maintaining (\forall int i; hi < i && i < sortedArray.length; sortedArray[i] > value);
          @ decreases hi - lo + 1;
          @*/
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (sortedArray[mid] == value) {
                return mid;
            } else if (sortedArray[mid] < value) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
}