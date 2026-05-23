
/*@ 
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires \valid(&ar[0] + (0..ar_len-1));
  requires \forall integer i; 0 <= i < ar_len ==> 0 <= ar[i] <= 100;
  requires ar_len > 0;
  requires ar_len < 100;
  assigns \nothing;
  ensures (\old(n) == 0 || \old(n) == 1) ==> \result == 1;
*/
int foo239(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        
            
        /*@
          loop invariant (i <= n) ==> (i >= 1 && missing >= 1);
          loop invariant \forall integer k; 0 <= k < ar_len ==> ar[k] == \at(ar[k], Pre);
          loop assigns i, missing;
            */
            for (int i = 1; i <= n; i++) {
            if (ar[i - 1] == i) {
                missing = i;
            } else if (ar[i - 1] != i) {
                return i;
            }
        }
            
        return missing;
}
