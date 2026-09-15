
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo223(int n) {

        int res = 0;
        int count = 0;
        int temp = n;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(n,Pre) > 0) ==> (count >= 0);
          loop invariant (\at(n,Pre) > 0) ==> (temp <= \at(n,Pre));
          loop invariant (\at(n,Pre) > 0) ==> (temp <= \at(n,Pre));
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
