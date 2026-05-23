public class IsAscending {
    /*@ 
      @ requires arr != null;
      @ ensures true;
      @*/
    public boolean isAscending (int[] arr) {
        int n = arr.length;
        if (n < 2) {
            return true;
        }
        //@ maintaining 0 <= i && i <= n;
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            //@ assume i + 1 < arr.length;
            if(arr[i] >= arr[i+1])
                return false;
        }
        return true;
    }
}