
#include <stddef.h> // Include the header to define NULL

/*@
  // Predicate to check if a number is even
  predicate is_even(integer x) = (x % 2 == 0);
*/

/*@
  requires \valid(a + (0..a_len-1)); // Array a must be valid for reading and writing
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100; // Array elements are bounded
  requires a_len >= 0; // Array length must be non-negative
  assigns \nothing; // No memory outside the function is modified
  ensures a == \null ==> \result == -1; // If a is NULL, return -1
  ensures a != \null && a_len == 1 ==> \result == 0; // If a_len is 1, return 0
  ensures a != \null && a_len > 1 ==> \result >= 0; // Result is non-negative
   // Result is the count of even XOR pairs
*/
int foo166(int * a, int a_len, int n) {

    if (a == NULL) {
        return -1;
    }
    if (a_len == 1) {
        return 0;
    }

    int evenPairCount = 0;

    /*@
      loop invariant 0 <= i && i <= a_len; // Loop index is within bounds
      loop invariant evenPairCount >= 0; // evenPairCount is non-negative
      loop invariant \forall integer k, l; 0 <= k < l < i ==> 
                     (is_even(a[k] ^ a[l]) ==> evenPairCount >= 0); // Valid pairs up to i
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre); // Array elements are unchanged
      loop assigns i, evenPairCount; // Variables modified in the loop
    */
    for (int i = 0; i < a_len; i++) {

        /*@
          loop invariant i + 1 <= j <= a_len; // Inner loop index is within bounds
          loop invariant evenPairCount >= 0; // evenPairCount is non-negative
          loop invariant \forall integer k, l; 0 <= k < l < i || 
                         (k == i && i + 1 <= l < j) ==> 
                         (is_even(a[k] ^ a[l]) ==> evenPairCount >= 0); // Valid pairs up to i, j
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre); // Array elements are unchanged
          loop assigns j, evenPairCount; // Variables modified in the inner loop
        */
        for (int j = i + 1; j < a_len; j++) {
            int x = a[i];
            int y = a[j];
            int v = x ^ y;
            if ((v & 1) == 0) {
                evenPairCount++;
            }
        }
    }

    return evenPairCount;
}
