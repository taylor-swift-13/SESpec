
/*@ 
  predicate reaches{L}(integer x, int* b, integer n) =
    x == 0
    || (\exists integer y; 0 <= y < n && reaches{L}(y,b,n) && y + b[y] + 1 == x);
*/

/*@
  requires bits_len >= 0;
  requires \valid_read(bits + (0 .. bits_len - 1));
  requires \forall integer k; 0 <= k < bits_len ==> (bits[k] == 0 || bits[k] == 1);
*/
int foo121(int * bits, int bits_len) {

    int n = bits_len, i = 0;
    
    /*@
      loop invariant 0 <= i;
      loop invariant n == \at(bits_len,Pre);
      loop invariant bits_len == \at(bits_len,Pre);
      loop invariant bits == \at(bits,Pre);
      loop invariant \valid_read(bits + (0 .. \at(bits_len,Pre) - 1));
      loop invariant \forall integer k; 0 <= k < \at(bits_len,Pre) ==> (bits[k] == 0 || bits[k] == 1);
      loop invariant \forall integer k; 0 <= k < i ==> (bits[k] == 0 || bits[k] == 1);
      loop invariant reaches(i, bits, n);
      loop assigns i;
    */
    while (i < n - 1) {
        i += bits[i] + 1;
    }
        
    return i == n - 1;
}
