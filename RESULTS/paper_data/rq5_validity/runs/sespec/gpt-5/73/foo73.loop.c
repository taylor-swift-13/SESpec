
/*@ predicate class7(integer t) = t % 7 == 0; */
/*@ predicate class6(integer t) = t % 7 != 0 && t % 6 == 0; */
/*@ predicate class5(integer t) = t % 7 != 0 && t % 6 != 0 && t % 5 == 0; */
/*@ predicate class4(integer t) = t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 == 0; */
/*@ predicate class3(integer t) = t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 == 0; */
/*@ predicate class2(integer t) = t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 == 0; */
/*@ predicate class1(integer t) = t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 != 0; */

/*@ predicate classes_partition(integer t) =
      class7(t) || class6(t) || class5(t) || class4(t) || class3(t) || class2(t) || class1(t); */

/*@ predicate classes_disjoint(integer t) =
      !(class7(t) && class6(t)) &&
      !(class7(t) && class5(t)) &&
      !(class7(t) && class4(t)) &&
      !(class7(t) && class3(t)) &&
      !(class7(t) && class2(t)) &&
      !(class7(t) && class1(t)) &&
      !(class6(t) && class5(t)) &&
      !(class6(t) && class4(t)) &&
      !(class6(t) && class3(t)) &&
      !(class6(t) && class2(t)) &&
      !(class6(t) && class1(t)) &&
      !(class5(t) && class4(t)) &&
      !(class5(t) && class3(t)) &&
      !(class5(t) && class2(t)) &&
      !(class5(t) && class1(t)) &&
      !(class4(t) && class3(t)) &&
      !(class4(t) && class2(t)) &&
      !(class4(t) && class1(t)) &&
      !(class3(t) && class2(t)) &&
      !(class3(t) && class1(t)) &&
      !(class2(t) && class1(t)); */

void foo73(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;

    /*@
      loop invariant \forall integer t; 0 <= t < l ==> classes_partition(t);
      loop invariant \forall integer t; 0 <= t < l ==> classes_disjoint(t);

      loop invariant \forall integer t; 0 <= t < l ==> ((t % 7 == 0) <==> class7(t));
      loop invariant \forall integer t; 0 <= t < l ==> ((t % 7 != 0 && t % 6 == 0) <==> class6(t));
      loop invariant \forall integer t; 0 <= t < l ==> ((t % 7 != 0 && t % 6 != 0 && t % 5 == 0) <==> class5(t));
      loop invariant \forall integer t; 0 <= t < l ==> ((t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 == 0) <==> class4(t));
      loop invariant \forall integer t; 0 <= t < l ==> ((t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 == 0) <==> class3(t));
      loop invariant \forall integer t; 0 <= t < l ==> ((t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 == 0) <==> class2(t));
      loop invariant \forall integer t; 0 <= t < l ==> ((t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 != 0) <==> class1(t));

      loop invariant v1 + v2 + v3 + v4 + i + j + k == l;
      loop invariant 0 <= l <= n;
      loop invariant 0 <= v1 <= l;
      loop invariant 0 <= v2 <= l;
      loop invariant 0 <= v3 <= l;
      loop invariant 0 <= v4 <= l;
      loop invariant 0 <= i  <= l;
      loop invariant 0 <= j  <= l;
      loop invariant 0 <= k  <= l;

      loop invariant (0 < \at(n,Pre)) ==> (l <= n);
      loop invariant (0 < \at(n,Pre)) ==> (v1 + v2 + v3 + v4 + i + j + k == l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j && j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i && i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k && k <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v4 && v4 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v3 && v3 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v2 && v2 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v1 && v1 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l && l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v1, v2, v3, v4, i, j, k, l;
    */
    while (l < n) {
      if((l % 7) == 0){
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
