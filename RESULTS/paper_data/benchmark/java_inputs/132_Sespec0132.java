class Sespec0132 {
    static int foo132(int[] a) {
        if (a.length == 0) return -1;
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < a.length; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
        return res;
    }
}
