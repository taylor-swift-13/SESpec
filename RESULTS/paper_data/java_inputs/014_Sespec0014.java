class Sespec0014 {
    static int foo14(int unknown) {
        int arr_len = unknown > 0 ? 1 : 0;
        int[] arr = arr_len != 0 ? new int[arr_len] : null;
        if (unknown > 0) arr[0] = 1;
        if (unknown > 0) return (arr_len == 1 && arr[0] == 1) ? 1 : 0;
        return (arr_len == 0) ? 1 : 0;
    }
}
