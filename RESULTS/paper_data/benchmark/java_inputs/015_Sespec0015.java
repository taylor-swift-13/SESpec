public class Sespec0015 {
    static int foo15(int size) {
        if (size < 0) return -1;
        if (size < 0 || size >= 4) return 0;
        int[] a = new int[4];
        a[size] = 0;
        return 1;
    }
}
