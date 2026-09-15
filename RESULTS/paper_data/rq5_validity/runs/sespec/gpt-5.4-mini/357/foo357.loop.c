
/*@
  logic integer oddmask(integer c) =
    c <= 0 ? 0 :
    oddmask(c - 1) | (((c - 1) % 2 == 1) ? (1 << (c - 1)) : 0);
*/

int foo357(int n) {

        int count = 0;
        int res = 0;
        int temp = n;
        
            
        /*@
          loop invariant count >= 0;
          loop invariant res == oddmask(count);
          loop invariant n == \at(n,Pre);
          loop invariant temp <= \at(n,Pre);
          loop invariant (\at(n,Pre) >= 0) ==> (temp >= 0);
          loop invariant (\at(n,Pre) >= 0) ==> (temp == (\at(n,Pre) >> count));
          loop invariant (\at(n,Pre) >= 0) ==> (res == oddmask(count));
          loop invariant (\at(n,Pre) >= 0) ==> (count + temp <= \at(n,Pre));
          loop invariant (!(\at(n,Pre) > 0)) ==> (temp == \at(n,Pre) && res == 0 && count == 0 && n == \at(n,Pre));
          loop assigns res, temp, count;
            */
            while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
            
        return (n | res);
}
