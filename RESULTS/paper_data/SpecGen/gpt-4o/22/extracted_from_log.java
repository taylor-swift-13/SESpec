class arraylength1 {
    //@ requires size >= 0;
    //@ ensures \result == -1 <==> size < 0;
    //@ ensures \result == 0 <==> (size > 0 && (\forall int[] int_array; int_array.length != size));  
    //@ ensures \result == 1 <==> (size >= 0 && (\exists int[] int_array; int_array.length == size));  
    public static int func(int size) {
        if (size < 0) return -1;
        int int_array[] = new int[size];

        if (int_array.length != size)
            return 0;
        return 1;
    }
}