class CompareArray {

    /*@ public normal_behavior
      @   requires a != null && b != null;
      @   ensures \result == (a.length == b.length && (\forall int i; 0 <= i && i < a.length; a[i] == b[i]));
      @*/
    /*@ spec_public @*/ public static boolean arrcmp(int[] a, int[] b) {
        if(a.length != b.length) {
	    return false;
        }

        /*@ 
          @   maintaining 0 <= i && i <= a.length;
          @   maintaining a.length == b.length;
          @   maintaining (\forall int j; 0 <= j && j < i; a[j] == b[j]);
          @   decreases a.length - i;
          @*/
        for(int i = 0; i < a.length; i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }
}