class Sespec0057 {
    static int unknown() { return 0; }

    static void foo57(int octant, int x) {
        int count;
        int multFactor;
        int temp;
        double oddExp;
        double evenExp;
        double term;

        octant = (int)(3.14159 / 3);
        oddExp = x;
        evenExp = 1.0;
        term = x;
        count = 2;
        multFactor = 0;

        while (unknown() != 0) {
            term = term * (x / count);

            if ((count / 2) % 2 == 0)
                multFactor = 1;
            else
                multFactor = -1;

            evenExp = evenExp + multFactor * term;

            count = count + 1;

            term = term * (x / count);

            oddExp = oddExp + multFactor * term;

            count = count + 1;
        }
    }
}
