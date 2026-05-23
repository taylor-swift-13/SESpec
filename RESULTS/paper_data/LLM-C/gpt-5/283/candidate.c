int search(int * arr, int arr_len, int n);

/*@ 
  requires 0 <= arr_len;
  requires 1 <= n <= arr_len;
  requires \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures \exists integer r;
            0 <= r < n &&
            (r == n-1 || (r % 2 == 0 && \old(arr[r]) != \old(arr[r+1]))) &&
            (\forall integer e; 0 <= e < r ==> (e % 2 != 0 || \old(arr[e]) == \old(arr[e+1]))) &&
            \result == \old(arr[r]);
  ensures (\forall integer e; 0 <= e < n-1 ==> (e % 2 != 0 || \old(arr[e]) == \old(arr[e+1]))) ==> \result == \old(arr[n-1]);
*/
int search(int * arr, int arr_len, int n) {

        int i = 0;
        /*@
          loop invariant 0 <= i <= n;
          loop invariant i % 2 == 0;
          loop invariant \forall integer e; 0 <= e < i ==> (e % 2 != 0 || \at(arr[e],Pre) == \at(arr[e+1],Pre));
          loop assigns i;
          loop variant n - i;
        */
        while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
        return arr[n - 1];
}
