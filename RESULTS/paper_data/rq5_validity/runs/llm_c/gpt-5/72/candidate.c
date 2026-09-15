/*@ 
  predicate P6(integer t) = t % 6 == 0;
  predicate P5(integer t) = t % 6 != 0 && t % 5 == 0;
  predicate P4(integer t) = t % 6 != 0 && t % 5 != 0 && t % 4 == 0;
  predicate P3(integer t) = t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 == 0;
  predicate P2(integer t) = t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 == 0;
  predicate P1(integer t) = t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 != 0;
*/

/*@ 
  assigns \nothing;
*/
void foo310(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;

    /*@
      loop invariant 0 <= \integer(l) <= \integer(n);
      loop invariant \integer(v2) == \numof integer t; 0 <= t < \integer(l); P6(t);
      loop invariant \integer(v3) == \numof integer t; 0 <= t < \integer(l); P5(t);
      loop invariant \integer(v4) == \numof integer t; 0 <= t < \integer(l); P4(t);
      loop invariant \integer(i)  == \numof integer t; 0 <= t < \integer(l); P3(t);
      loop invariant \integer(j)  == \numof integer t; 0 <= t < \integer(l); P2(t);
      loop invariant \integer(k)  == \numof integer t; 0 <= t < \integer(l); P1(t);
      loop invariant \integer(v2) + \integer(v3) + \integer(v4) + \integer(i) + \integer(j) + \integer(k) == \integer(l);
      loop assigns i, j, k, l, v2, v3, v4;
      loop variant \integer(n) - \integer(l);
    */
    while (l < n) {
       if((l % 6) == 0){
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
    /*@ assert \integer(v2) + \integer(v3) + \integer(v4) + \integer(i) + \integer(j) + \integer(k) == \integer(n); */
    /*@ assert \integer(v2) == \numof integer t; 0 <= t < \integer(n); P6(t); */
    /*@ assert \integer(v3) == \numof integer t; 0 <= t < \integer(n); P5(t); */
    /*@ assert \integer(v4) == \numof integer t; 0 <= t < \integer(n); P4(t); */
    /*@ assert \integer(i)  == \numof integer t; 0 <= t < \integer(n); P3(t); */
    /*@ assert \integer(j)  == \numof integer t; 0 <= t < \integer(n); P2(t); */
    /*@ assert \integer(k)  == \numof integer t; 0 <= t < \integer(n); P1(t); */

  }
