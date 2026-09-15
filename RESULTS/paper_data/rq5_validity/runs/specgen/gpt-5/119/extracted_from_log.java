public class IsDescending {
    //@ requires arr != null;
    //@ requires arr.length < 2;
    //@ assignable \nothing;
    //@ ensures \result;
    /*@ spec_public @*/ public boolean isDescending (int[] arr) {
        int n = arr.length;
        if (n < 2) {
            return true;
        }
        //@ maintaining 0 <= i && i + 1 < n;
        //@ decreases n - (i + 1);
        for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return false;
        }
        return true;
    }
}