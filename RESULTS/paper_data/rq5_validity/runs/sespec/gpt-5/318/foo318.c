
/*@
  requires \true;
  assigns \nothing;
  ensures (num == 1) ==> (\result == 1);
  ensures (num != 1) ==> (0 <= \result);
  ensures (num > 1 && num % 2 != 0 && num % 3 != 0 && num > 3) ==> ( \result >= 0 );
  ensures \result == \result; 
  ensures \result == \result;  
*/
int foo318(int num) {
    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant 2 <= c;
      loop invariant c <= num || num < 2;
      loop invariant 0 <= result;
      loop invariant result <= (c >= 2 ? c - 2 : 0);
      loop invariant \forall integer d; 2 <= d < c ==> (num % d == 0 ==> d <= num);
      loop assigns c, result;
    */
    for (int c = 2; c <= num / c; c++) {
        if (num % c == 0) {
            result++;
            if (num / c == c) {
                break;
            }
        }
    }

    return result;
}
