
/*@ 
  logic integer sum_pow4_even(integer c) =
    c <= 0 ? 0 : sum_pow4_even(c-1) + (2*c) * (2*c) * (2*c) * (2*c);
*/

/*@
  requires p == \at(p,Pre);
  assigns \nothing;
  ensures p == \at(p,Pre);
*/
int foo395(int p) {

    int odd = 0;
        
    /*@
      loop invariant p == \at(p,Pre);
      loop assigns c, odd;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        odd = odd + (tmp * tmp * tmp * tmp);
    }
            
    return odd;
}
