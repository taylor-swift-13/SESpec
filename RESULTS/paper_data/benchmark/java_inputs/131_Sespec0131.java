class Sespec0131 {
    static int foo131(int[] a) {
        if (a.length == 0) return -1;
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < a.length; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
        return res;
    }
}
