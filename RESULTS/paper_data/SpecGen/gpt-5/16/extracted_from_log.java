class Sespec0016 {
    /*@ ensures size < 0 ==> \result == -1;
      @ ensures (0 <= size && size < 4) ==> \result == 1;
      @ ensures size >= 4 ==> \result == 0;
      @*/
    static int foo16(int size) {
        if (size < 0) return -1;
        if (size < 0 || size >= 4) return 0;
        int[] a = new int[4];
        int i = a[size];
        return 1;
    }
}