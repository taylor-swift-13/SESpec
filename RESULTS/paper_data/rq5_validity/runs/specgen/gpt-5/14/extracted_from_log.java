class Sespec0014 {
    //@ ensures \result == 1;
    /*@ spec_public @*/ static int foo14(int unknown) {
        int arr_len = unknown > 0 ? 1 : 0;
        /*@ nullable @*/ int[] arr = arr_len != 0 ? new int[arr_len] : null;
        if (unknown > 0) arr[0] = 1;
        if (unknown > 0) return (arr_len == 1 && arr[0] == 1) ? 1 : 0;
        return (arr_len == 0) ? 1 : 0;
    }
}