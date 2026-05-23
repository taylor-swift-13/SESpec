class FindLucas {

    //@ requires num >= 0;
    //@ ensures (num == 0 ? \result == 2 : (num == 1 ? \result == 1 : (\forall int[] lucas; lucas.length == num + 1 && lucas[0] == 2 && lucas[1] == 1 && (\exists int i; 2 < i && i <= num; lucas[i] == lucas[i - 1] + lucas[i - 2]) && lucas[num] == \result)));  
    public static int findLucas(int num) {
        if (num == 0) return 2;
        if (num == 1) return 1;

        int a = 2; // Lucas number at index 0
        int b = 1; // Lucas number at index 1
        int result = 0;

        //@ maintaining 2 <= i && i <= num + 1;
        //@ maintaining (\exists int j; 0 < j && j < i; (j == 0 ? a == 2 : (j == 1 ? b == 1 : result == a + b)));  
        //@ decreases num - i + 1;
        for (int i = 2; i <= num; i++) {
            result = a + b;
            a = b;
            b = result;
        }

        return result;
    }
}