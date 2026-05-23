class Sespec0036 {
    static double foo46_helper1_c36(long l) {
        if (!(l < 100L && l > -100L)) throw new AssertionError();
        return (double) l;
    }

    static double foo36(double x) {
        if (x < 0.0) x *= 10.0;
        else x /= 10.0;
        long l = (long) x;
        return foo46_helper1_c36(l);
    }
}
