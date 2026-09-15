public class Sespec0006 {

    //@ public normal_behavior
    //@   requires a != null;
    //@   assignable \nothing;
    //@   ensures true;
    public static int sum(int[] a) {
        int s = 0;
        for (int i = 0; i < a.length; i++) {
            //@ assume 0 <= i;
            s += a[i];
        }
        return s;
    }

    //@ public normal_behavior
    //@   requires a != null;
    //@   assignable \nothing;
    //@   ensures true;
    public static int indexOf(int[] a, int v) {
        for (int i = 0; i < a.length; i++) {
            //@ assume 0 <= i;
            if (a[i] == v) return i;
        }
        return -1;
    }

    //@ public normal_behavior
    //@   requires a != null;
    //@   assignable a[*];
    //@   ensures true;
    public static void reverse(int[] a) {
        int i = 0;
        int j = a.length - 1;
        while (i < j) {
            //@ assume 0 <= i;
            //@ assume 0 <= j;
            //@ assume i < a.length;
            //@ assume j < a.length;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    //@ public normal_behavior
    //@   requires a != null;
    //@   assignable \nothing;
    //@   ensures true;
    public static boolean isSortedNonDecreasing(int[] a) {
        for (int i = 0; i + 1 < a.length; i++) {
            //@ assume 0 <= i;
            //@ assume 0 <= i + 1;
            if (a[i] > a[i + 1]) return false;
        }
        return true;
    }
}