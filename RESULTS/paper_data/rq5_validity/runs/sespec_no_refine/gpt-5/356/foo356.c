
/*@
  logic integer even_mask(integer k) =
    k <= 0 ? 0 : ( ((k - 1) % 2 == 0 ? (1 << (k - 1)) : 0) | even_mask(k - 1) );
*/

/*@ logic integer bit_length(integer x) =
      x <= 0 ? 0 : 1 + bit_length(x >> 1); */
/*@
  requires \true;
  assigns \nothing;
*/
int foo356(int n) {

        int res = 0;
        int count = 0;
        int temp = n;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(n,Pre) > 0) ==> ((0 <= count) && (temp == (\at(n,Pre) >> count)) && (res == even_mask(count)));
          loop invariant (\at(n,Pre) > 0) ==> (res == even_mask(count)) ;
          loop invariant (\at(n,Pre) > 0) ==> ((0 <= count) && (temp == (\at(n,Pre) >> count))) ;
          loop invariant (!(\at(n,Pre) > 0)) ==> ((temp == \at(n,Pre))&&(count == 0)&&(res == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns res, temp, count;
            */
            while (temp > 0) {
            if (count % 2 == 0) {
                res = res | (1 << count);
            }
            count++;
            temp >>= 1;
        }
            
        return n ^ res;
}
