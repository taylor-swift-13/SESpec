
/*@ 
  logic integer pow10(integer e) = (e <= 0 ? 1 : 10 * pow10(e - 1));
*/

/*@ 
  requires r > 0 ==> b != 0;
  requires r > 0 ==> (b > 0 && num >= 0);
  assigns \nothing;   
  ensures b == \old(b);
  ensures r == \old(r);
  ensures num == \old(num);
  ensures \old(r) <= 0 ==> \result == 0;
  ensures \result == \result;  
*/
int foo386(int num, int b, int r) {

    int result = 0;
        
    /*@
      loop invariant b == \at(b,Pre);
      loop invariant \at(r,Pre) - r >= 0;
      loop invariant (\at(r,Pre) > 0) ==> (b == \at(b,Pre));
      loop invariant (\at(r,Pre) > 0) ==> (0 <= r && r <= \at(r,Pre));
      loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0)&&(r == \at(r,Pre))&&(b == \at(b,Pre))&&(num == \at(num,Pre)));
      loop invariant b == \at(b,Pre);
      loop assigns r, num, result;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / b;
        num %= b;
    }
        
    return result;
}
