
/*@
  logic integer count_div8(integer x) = x < 0 ? 0 : (x / 8 + 1);
  logic integer count_div7(integer x) = x < 0 ? 0 : (x / 7 + 1);
  logic integer count_div6(integer x) = x < 0 ? 0 : (x / 6 + 1);
  logic integer count_div5(integer x) = x < 0 ? 0 : (x / 5 + 1);
  logic integer count_div4(integer x) = x < 0 ? 0 : (x / 4 + 1);
  logic integer count_div3(integer x) = x < 0 ? 0 : (x / 3 + 1);
  logic integer count_div2(integer x) = x < 0 ? 0 : (x / 2 + 1);
  logic integer count_other(integer x) =
    x < 0 ? 0 : (x + 1 - count_div8(x) - count_div7(x) - count_div6(x) - count_div5(x) - count_div4(x) - count_div3(x) - count_div2(x));
*/

void foo308(unsigned int n) {

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
          loop invariant (0 < \at(n,Pre)) ==> (j + i + k + v4 + v3 + v2 + v1 + v5 + l == \at(l,Pre) + \at(n,Pre));
          loop invariant (0 < \at(n,Pre)) ==> (n == \at(n,Pre));
          loop invariant (0 < \at(n,Pre)) ==> (0 <= l <= n);
          loop invariant (0 < \at(n,Pre)) ==> (v5 == count_div8(l - 1));
          loop invariant (0 < \at(n,Pre)) ==> (v1 == count_div7(l - 1));
          loop invariant (0 < \at(n,Pre)) ==> (v2 == count_div6(l - 1));
          loop invariant (0 < \at(n,Pre)) ==> (v3 == count_div5(l - 1));
          loop invariant (0 < \at(n,Pre)) ==> (v4 == count_div4(l - 1));
          loop invariant (0 < \at(n,Pre)) ==> (i == count_div3(l - 1) - count_div6(l - 1) - count_div9(l - 1));
          loop invariant (0 < \at(n,Pre)) ==> (j == count_div2(l - 1) - count_div4(l - 1) - count_div6(l - 1) - count_div8(l - 1));
          loop invariant (0 < \at(n,Pre)) ==> (k == (l - count_div8(l - 1) - count_div7(l - 1) - count_div6(l - 1) - count_div5(l - 1) - count_div4(l - 1) - count_div3(l - 1) - count_div2(l - 1)));
          loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v5 == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns v5, v1, v2, v3, v4, i, j, k, l;
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
            

  }
