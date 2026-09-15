class Sespec0006 {
    static void foo28_helper1_c6(int[] a) {
        int[] aux = new int[a.length];
        for (int blockSize = 1; blockSize < a.length; blockSize *= 2)
            for (int start = 0; start < a.length; start += 2 * blockSize)
                foo28_helper4_c6(a, aux, start, start + blockSize, start + 2 * blockSize);
    }

    static void foo28_helper2_c6(int[] a) {
        int[] from = a;
        int[] to = new int[a.length];
        for (int blockSize = 1; blockSize < a.length; blockSize *= 2) {
            for (int start = 0; start < a.length; start += 2 * blockSize)
                foo28_helper3_c6(from, to, start, start + blockSize, start + 2 * blockSize);
            int[] temp = from; from = to; to = temp;
        }
        if (a != from) for (int k = 0; k < a.length; k++) a[k] = from[k];
    }

    static void foo28_helper3_c6(int[] from, int[] to, int lo, int mid, int hi) {
        if (mid > from.length) mid = from.length;
        if (hi > from.length) hi = from.length;
        int i = lo, j = mid;
        for (int k = lo; k < hi; k++) {
            if (i == mid) to[k] = from[j++];
            else if (j == hi) to[k] = from[i++];
            else if (from[j] < from[i]) to[k] = from[j++];
            else to[k] = from[i++];
        }
    }

    static void foo28_helper4_c6(int[] a, int[] aux, int lo, int mid, int hi) {
        if (mid >= a.length) return;
        if (hi > a.length) hi = a.length;
        int i = lo, j = mid;
        for (int k = lo; k < hi; k++) {
            if (i == mid) aux[k] = a[j++];
            else if (j == hi) aux[k] = a[i++];
            else if (a[j] < a[i]) aux[k] = a[j++];
            else aux[k] = a[i++];
        }
        for (int k = lo; k < hi; k++) a[k] = aux[k];
    }

    static void foo28_helper5_c6(int[] a, int[] aux, int lo, int hi) {
        if (hi - lo <= 1) return;
        int mid = lo + (hi - lo) / 2;
        foo28_helper5_c6(a, aux, lo, mid);
        foo28_helper5_c6(a, aux, mid, hi);
        foo28_helper4_c6(a, aux, lo, mid, hi);
    }

    static void foo6(int[] a) {
        int[] aux = new int[a.length];
        foo28_helper5_c6(a, aux, 0, a.length);
    }
}
