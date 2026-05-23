
/*@
  // Count of t in [0, l) that are multiples of d>0
  logic integer count_multiples(integer l, integer d) =
    (l <= 0 || d <= 0) ? 0 : (l - (l % d)) / d;

  // Count of t in [0, l) that satisfy the piecewise classification:
  //  - if t % 4 == 0 -> class 0
  //  - else if t % 3 == 0 -> class 1
  //  - else if t % 2 == 0 -> class 2
  //  - else -> class 3
  //
  // These are exact closed-form counts over the half-open interval [0, l).
  logic integer class0(integer l) = count_multiples(l, 4);
  logic integer class1(integer l) = count_multiples(l, 3) - count_multiples(l, 12);
  logic integer class2(integer l) = count_multiples(l, 2) - count_multiples(l, 4) - count_multiples(l, 6) + count_multiples(l, 12);
  logic integer class3(integer l) = l - class0(l) - class1(l) - class2(l);
*/

void foo303(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;

    /*@
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j && j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i && i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k && k <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v4 && v4 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l && l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v4, i, j, k, l;
    */
    while (l < n) {
        if ((l % 4) == 0) {
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
