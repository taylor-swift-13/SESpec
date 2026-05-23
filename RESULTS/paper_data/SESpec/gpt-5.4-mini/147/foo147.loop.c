
/*@
  logic integer power3(integer e) =
    e <= 0 ? 1 : 3 * power3(e - 1);
*/

int foo147(int n) {

        int temp = n;
        
            
        /*@
          loop invariant temp == \at(n,Pre) || temp != 0;
          loop invariant 0 <= temp || temp < 0;
          loop invariant n == \at(n,Pre);
          loop invariant temp >= 0 || temp < 0;
          loop invariant (temp != 0 && temp % 3 == 0) ==> (\at(n,Pre) % 3 == 0);
          loop invariant (temp != 0 && temp % 3 == 0) ==> (temp <= \at(n,Pre) || temp >= \at(n,Pre));
          loop invariant (temp != 0 && temp % 3 == 0) ==> (temp % 3 == 0);
          loop invariant (temp != 0 && temp % 3 == 0) ==> (temp != 1 || \at(n,Pre) == 1);
          loop invariant n == \at(n,Pre);
          loop assigns temp;
            */
            while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
            
        return temp == 1;
}
