int firstMissingPositive(int * arr, int arr_len, int n);

/*@ 
  requires arr_len >= 0;
  requires 0 <= n <= arr_len;
  requires \valid(arr + (0 .. n-1));

  assigns arr[0 .. n-1];

  ensures 1 <= \result <= n + 1;

  // Smallest missing positive w.r.t. the initial contents of arr[0..n-1]
  ensures (\forall integer v; 1 <= v < \result ==> 
            (\exists integer k; 0 <= k < n && \at(arr[k], Pre) == v));
  ensures (\forall integer k; 0 <= k < n ==> \at(arr[k], Pre) != \result);
*/
int firstMissingPositive(int * arr, int arr_len, int n) {

        int i = 0;
        /*@
          loop invariant 0 <= i <= n;
          loop invariant \valid(arr + (0 .. n-1));
          loop assigns arr[0 .. n-1], i;
        */
        while (i < n) {
            if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
                i++;
            } else {
                int temp = arr[i];
                /*@ assert 1 <= temp && temp <= n; */
                /*@ assert 0 <= temp - 1 < n; */
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
            }
        }
        /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
          loop assigns i;
          loop variant n - i;
        */
        for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
}
