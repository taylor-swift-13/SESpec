
/*@
  logic integer odd_with(int *a, integer lo, integer hi, integer v) =
    lo >= hi ? 0 :
    odd_with(a, lo, hi - 1, v) + (((a[hi - 1] ^ v) % 2 == 1) ? 1 : 0);

  logic integer odd_pairs(int *a, integer lo, integer hi) =
    lo >= hi ? 0 :
    odd_pairs(a, lo, hi - 1) + odd_with(a, lo, hi - 1, a[hi - 1]);
*/
        
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
*/
int foo238(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant count >= 0;
          loop invariant length == \at(a_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns i, count;
            */
            for (int i = 0; i < length; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i;
              loop invariant i <= length;
              loop invariant i + 1 <= j <= length;
              loop invariant 0 <= count;
              loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
              loop assigns j, count;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
            
        }
            
        return count;
}
