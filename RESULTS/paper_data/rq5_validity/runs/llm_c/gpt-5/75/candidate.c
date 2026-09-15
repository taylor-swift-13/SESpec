/*@ predicate cat9(integer t) = t % 9 == 0;
    predicate cat8(integer t) = t % 9 != 0 && t % 8 == 0;
    predicate cat7(integer t) = t % 9 != 0 && t % 8 != 0 && t % 7 == 0;
    predicate cat6(integer t) = t % 9 != 0 && t % 8 != 0 && t % 7 != 0 && t % 6 == 0;
    predicate cat5(integer t) = t % 9 != 0 && t % 8 != 0 && t % 7 != 0 && t % 6 != 0 && t % 5 == 0;
    predicate cat4(integer t) = t % 9 != 0 && t % 8 != 0 && t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 == 0;
    predicate cat3(integer t) = t % 9 != 0 && t % 8 != 0 && t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 == 0;
    predicate cat2(integer t) = t % 9 != 0 && t % 8 != 0 && t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 == 0;
    predicate cat1(integer t) = t % 9 != 0 && t % 8 != 0 && t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 != 0;
*/

/*@ 
  assigns \nothing; 
*/

/*@ 
  requires \true;
  assigns i, j, k, v1, v2, v3, v4, v5, v6, l;
  ensures l == n;
  ensures v6 == \numof integer t; 0 <= t < n && cat9(t);
  ensures v5 == \numof integer t; 0 <= t < n && cat8(t);
  ensures v1 == \numof integer t; 0 <= t < n && cat7(t);
  ensures v2 == \numof integer t; 0 <= t < n && cat6(t);
  ensures v3 == \numof integer t; 0 <= t < n && cat5(t);
  ensures v4 == \numof integer t; 0 <= t < n && cat4(t);
  ensures i  == \numof integer t; 0 <= t < n && cat3(t);
  ensures j  == \numof integer t; 0 <= t < n && cat2(t);
  ensures k  == \numof integer t; 0 <= t < n && cat1(t);
  ensures i + j + k + v1 + v2 + v3 + v4 + v5 + v6 == n;
  ensures \forall integer t; 0 <= t < n ==> 
            ((cat9(t) ? 1 : 0) + (cat8(t) ? 1 : 0) + (cat7(t) ? 1 : 0) +
             (cat6(t) ? 1 : 0) + (cat5(t) ? 1 : 0) + (cat4(t) ? 1 : 0) +
             (cat3(t) ? 1 : 0) + (cat2(t) ? 1 : 0) + (cat1(t) ? 1 : 0) == 1);
*/
void foo313(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int v5;
    unsigned int v6;
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
    v6 = 0;

    /*@
      loop invariant 0 <= l <= n;
      loop invariant v6 == \numof integer t; 0 <= t < l && cat9(t);
      loop invariant v5 == \numof integer t; 0 <= t < l && cat8(t);
      loop invariant v1 == \numof integer t; 0 <= t < l && cat7(t);
      loop invariant v2 == \numof integer t; 0 <= t < l && cat6(t);
      loop invariant v3 == \numof integer t; 0 <= t < l && cat5(t);
      loop invariant v4 == \numof integer t; 0 <= t < l && cat4(t);
      loop invariant i  == \numof integer t; 0 <= t < l && cat3(t);
      loop invariant j  == \numof integer t; 0 <= t < l && cat2(t);
      loop invariant k  == \numof integer t; 0 <= t < l && cat1(t);
      loop invariant i + j + k + v1 + v2 + v3 + v4 + v5 + v6 == l;
      loop assigns i, j, k, v1, v2, v3, v4, v5, v6, l;
      loop variant n - l;
    */
    while (l < n) {
       if((l % 9) == 0){
       v6 = v6 + 1;
      }
       else if((l % 8) == 0){
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

  }
