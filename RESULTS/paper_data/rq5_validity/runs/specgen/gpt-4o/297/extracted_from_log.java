class FindLucas {

    //@ requires seed >= 0;
 
 
    public static int findLucas(int seed) {
        if (seed == 0) {
            return 2; // Base case for seed == 0
        }
        if (seed == 1) {
            return 1; // Base case for seed == 1
        }

        int prev1 = 2; // Lucas number at index 0
        int prev2 = 1; // Lucas number at index 1
        int current = 0;

        //@ maintaining 2 <= i && i - 1 <= seed;  
 
        //@ decreases seed - i;
        for (int i = 2; i <= seed; i++) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }

        return current;
    }
}