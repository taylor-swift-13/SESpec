class Sespec0017 {
    static int foo17(int index) {
        if (index < 0 || index >= 4) return 0;
        int[] a = new int[4];
        a[index] = 0;
        return 1;
    }
}
