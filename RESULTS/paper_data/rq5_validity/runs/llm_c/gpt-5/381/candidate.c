/*@ 
  logic integer min_int(integer a, integer b) = (a <= b) ? a : b;

  logic integer count_common_divisors(integer a, integer b, integer n) =
    n <= 0 ? 0 :
    count_common_divisors(a,b,n-1) + (((a % n) == 0 && (b % n) == 0) ? 1 : 0);
*/

int numCommDiv(int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures (x <= 0 || y <= 0) ==> \result == 0;
  ensures (x > 0 && y > 0) ==> \result == count_common_divisors(x,y, min_int(x,y));
  ensures (x > 0 && y > 0) ==> 0 <= \result <= min_int(x,y);
*/
int numCommDiv(int x, int y) {

        int count = 0;
        /*@ 
          loop invariant 1 <= i;
          loop invariant count == count_common_divisors(x,y, i-1);
          loop invariant 0 <= count <= i-1;
          loop invariant (x > 0 && y > 0) ==> i <= min_int(x,y) + 1;
          loop assigns count, i;
          loop variant (x > 0 && y > 0) ? (min_int(x,y) - i + 1) : 0;
        */
        for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
        return count;
}
