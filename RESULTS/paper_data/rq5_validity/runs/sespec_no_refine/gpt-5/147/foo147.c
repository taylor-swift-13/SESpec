
/*@
  assigns \nothing;
  ensures \result == (\exists integer k; k >= 0 && n == pow3(k));
*/
int foo147(int n) {

        int temp = n;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(\at(n,Pre) != 0 && \at(n,Pre) % 3 == 0)) ==> ((temp == \at(n,Pre))&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns temp;
            */
            while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
            
        return temp == 1;
}
