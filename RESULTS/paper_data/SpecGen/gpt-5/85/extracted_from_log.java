class Sespec0085 {
    //@ requires b >= 0;
    //@ assignable \nothing;
    //@ ensures a == \old(a) && b == \old(b);
    static void foo85(int a, int b) {
        int x = a;
        int y = b;
        int z = 0;
        //@ maintaining y >= 0;
        //@ maintaining z + x * y == a * b;
        //@ decreases y;
        while (y != 0) {
            if (y % 2 == 1) {
                z = z + x;
                y = y - 1;
            }
            x = 2 * x;
            y = y / 2;
        }
    }
}