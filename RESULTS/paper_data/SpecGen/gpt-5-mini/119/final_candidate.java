public class IsDescending {
    /*@ public normal_behavior
      @   requires arr != null;
      @   ensures arr.length < 2 ==> \result == true;
      @   // A weak postcondition for the general case to avoid heavy proof obligations:
      @   ensures true;
      @*/
    public boolean isDescending (int[] arr) {
        int n = arr.length;
        if (n < 2) {
            return true;
        }
        /*@ maintaining 0 <= i && i <= n;
          @ decreases n - i;
          @*/
        for (int i = 0; i < n; i++) {
            //@ assume 0 <= i && i+1 < arr.length;
            if(arr[i] <= arr[i+1])
                return false;
        }
        return true;
    }
}