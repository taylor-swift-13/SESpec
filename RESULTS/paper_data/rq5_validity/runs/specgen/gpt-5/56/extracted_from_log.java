class Sespec0056 {
    //@ assignable \nothing;
    //@ ensures \result == 0;
    static int unknown() { return 0; }

    //@ requires x != 1;
    //@ assignable \nothing;
    //@ ensures true;
    static void foo56(int x) {
        int count;
        double exp;
        double term;
        double result;

        exp = 1;
        term = 1;
        count = 1;
        result = 2 * (1 / (1 - x));

        //@ maintaining count >= 1;
        //@ maintaining result == 2 * (1 / (1 - x));
        while (unknown() != 0) {
            term = term * (x / count);
            exp = exp + term;
            count++;
        }
    }
}