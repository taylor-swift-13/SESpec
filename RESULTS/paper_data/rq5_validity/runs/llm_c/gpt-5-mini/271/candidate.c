int getOddOccurrence(int * arr, int arr_len, int arrSize);

/*@
    requires arrSize >= 0;
    requires arrSize == 0 || \valid(arr + (0 .. arrSize-1));
    assigns \nothing;
    behavior none_found:
        assumes \forall integer t; 0 <= t < arrSize ==> ((\sum integer j; 0 <= j <= t; ((arr[j] % 2) != 0 ? 1 : 0)) % 2) == 0;
        ensures \result == 0;
    behavior found:
        assumes \exists integer k; 0 <= k < arrSize &&
                ((arr[k] % 2) != 0) &&
                ((\sum integer j; 0 <= j <= k; ((arr[j] % 2) != 0 ? 1 : 0)) % 2) == 1 &&
                (\forall integer l; k < l < arrSize ==> ((\sum integer j; 0 <= j <= l; ((arr[j] % 2) != 0 ? 1 : 0)) % 2) == 0);
        ensures \result == arr[\old((\max integer m; 0 <= m < arrSize && ((\sum integer j; 0 <= j <= m; ((arr[j] % 2) != 0 ? 1 : 0)) % 2) == 1) ? (\max integer m; 0 <= m < arrSize && ((\sum integer j; 0 <= j <= m; ((arr[j] % 2) != 0 ? 1 : 0)) % 2) == 1) : 0))];
    complete behaviors none_found, found;
    disjoint behaviors none_found, found;
*/
int getOddOccurrence(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        /*@
            loop invariant 0 <= i <= arrSize;
            loop invariant count == (\sum integer j; 0 <= j < i; ((arr[j] % 2) != 0 ? 1 : 0));
            loop invariant ( result == 0 ) <==> (\forall integer t; 0 <= t < i ==> ((\sum integer j; 0 <= j <= t; ((arr[j] % 2) != 0 ? 1 : 0)) % 2) == 0);
            loop invariant ( result != 0 ) ==>
                (\exists integer k; 0 <= k < i &&
                    ((arr[k] % 2) != 0) &&
                    ((\sum integer j; 0 <= j <= k; ((arr[j] % 2) != 0 ? 1 : 0)) % 2) == 1 &&
                    (\forall integer l; k < l < i ==> ((\sum integer j; 0 <= j <= l; ((arr[j] % 2) != 0 ? 1 : 0)) % 2) == 0) &&
                    result == arr[k]);
            loop assigns i, count, result;
            loop variant arrSize - i;
        */
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] % 2 != 0) {
                count++;
                if (count % 2 != 0) {
                    result = arr[i];
                }
            }
        }
        return result;
}
