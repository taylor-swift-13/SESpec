/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
*/
void foo312(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int v5;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;
    v5 = 0;

    /*@
      loop invariant 0 <= \integer(l) <= \integer(n);
      loop invariant 0 <= \integer(i) <= \integer(l);
      loop invariant 0 <= \integer(j) <= \integer(l);
      loop invariant 0 <= \integer(k) <= \integer(l);
      loop invariant 0 <= \integer(v1) <= \integer(l);
      loop invariant 0 <= \integer(v2) <= \integer(l);
      loop invariant 0 <= \integer(v3) <= \integer(l);
      loop invariant 0 <= \integer(v4) <= \integer(l);
      loop invariant 0 <= \integer(v5) <= \integer(l);
      loop invariant \integer(v5) + \integer(v1) + \integer(v2) + \integer(v3) + \integer(v4) + \integer(i) + \integer(j) + \integer(k) == \integer(l);
      loop invariant \forall integer t; 0 <= t < \integer(l) ==>
         ((t % 8) == 0) ||
         (((t % 8) != 0) && ((t % 7) == 0)) ||
         (((t % 8) != 0) && ((t % 7) != 0) && ((t % 6) == 0)) ||
         (((t % 8) != 0) && ((t % 7) != 0) && ((t % 6) != 0) && ((t % 5) == 0)) ||
         (((t % 8) != 0) && ((t % 7) != 0) && ((t % 6) != 0) && ((t % 5) != 0) && ((t % 4) == 0)) ||
         (((t % 8) != 0) && ((t % 7) != 0) && ((t % 6) != 0) && ((t % 5) != 0) && ((t % 4) != 0) && ((t % 3) == 0)) ||
         (((t % 8) != 0) && ((t % 7) != 0) && ((t % 6) != 0) && ((t % 5) != 0) && ((t % 4) != 0) && ((t % 3) != 0) && ((t % 2) == 0)) ||
         (((t % 8) != 0) && ((t % 7) != 0) && ((t % 6) != 0) && ((t % 5) != 0) && ((t % 4) != 0) && ((t % 3) != 0) && ((t % 2) != 0));
      loop assigns i, j, k, v4, v3, v2, v1, v5, l;
      loop variant \integer(n) - \integer(l);
    */
    while (l < n) {
       if((l % 8) == 0){
       v5 = v5 + 1;
      }
       else if((l % 7) == 0){
       v1 = v1 + 1;
      }
       else if((l % 6) == 0){
       v2 = v2 + 1;
      }
       else if ((l % 5) == 0){
       v3 = v3 + 1;
      }
       else if ((l % 4) == 0) {
       v4 = v4 + 1;
      }
       else if((l % 3) == 0){
       i = i + 1;
      }
       else if((l % 2) == 0){
       j = j + 1;
      }
       else{
       k = k + 1;
      }
       l = l + 1;
      }

    /*@ assert \integer(l) == \integer(n); */
    /*@ assert \integer(v5) + \integer(v1) + \integer(v2) + \integer(v3) + \integer(v4) + \integer(i) + \integer(j) + \integer(k) == \integer(n); */

  }
