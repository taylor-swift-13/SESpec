class Sespec0058 {
    static int unknown() { return 0; }

    static void foo58(int octant1, int octant2, int x) {
        int count;
        int multFactor;
        int temp;
        double oddExp;
        double evenExp;
        double term;

        octant1 = 0;
        octant2 = (int)(3.14159 / 8);
        oddExp = x;
        evenExp = 1.0;
        term = x;
        count = 2;
        multFactor = 0;

        while (unknown() != 0) {
            int q1 = Integer.divideUnsigned(x, count);
            term = term * (double) q1;

            if (Integer.remainderUnsigned(Integer.divideUnsigned(count, 2), 2) == 0)
                multFactor = 1;
            else
                multFactor = -1;

            evenExp = evenExp + multFactor * term;

            count = count + 1;

            int q2 = Integer.divideUnsigned(x, count);
            term = term * (double) q2;

            oddExp = oddExp + multFactor * term;

            count = count + 1;
        }
    }
}
