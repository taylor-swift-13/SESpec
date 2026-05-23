


void foo75(unsigned int n) {

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

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= l <= \at(n,Pre);
          loop invariant 0 <= v6 && 0 <= v5 && 0 <= v1 && 0 <= v2 && 0 <= v3 && 0 <= v4 && 0 <= i && 0 <= j && 0 <= k;
          loop invariant (l == 0) ==> ((v6 == 0) && (v5 == 0) && (v1 == 0) && (v2 == 0) && (v3 == 0) && (v4 == 0) && (i == 0) && (j == 0) && (k == 0));
          loop invariant (l > 0) ==> (v6 >= 1);   // t = 0 contributes to v6 at first increment
          loop invariant (v6 + v5 + v1 + v2 + v3 + v4 + i + j + k) <= l;
          loop invariant (0 < \at(n,Pre)) ==> (l <= \at(n,Pre));
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= j <= l) && (j == l - (v6 + v5 + v1 + v2 + v3 + v4 + i + k))) ;
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= i <= l) && (i == l - (v6 + v5 + v1 + v2 + v3 + v4 + j + k))) ;
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= k <= l) && (k == l - (v6 + v5 + v1 + v2 + v3 + v4 + i + j))) ;
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= v4 <= l) && (v4 == l - (v6 + v5 + v1 + v2 + v3 + i + j + k))) ;
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= v3 <= l) && (v3 == l - (v6 + v5 + v1 + v2 + v4 + i + j + k))) ;
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= v2 <= l) && (v2 == l - (v6 + v5 + v1 + v3 + v4 + i + j + k))) ;
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= v1 <= l) && (v1 == l - (v6 + v5 + v2 + v3 + v4 + i + j + k))) ;
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= v5 <= l) && (v5 == l - (v6 + v1 + v2 + v3 + v4 + i + j + k))) ;
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= v6 <= l) && (v6 == l - (v5 + v1 + v2 + v3 + v4 + i + j + k))) ;
          loop invariant (0 < \at(n,Pre)) ==> ((0 <= l <= \at(n,Pre)) && (l == v6 + v5 + v1 + v2 + v3 + v4 + i + j + k)) ;
          loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v6 == 0)&&(v5 == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns v6, v5, v1, v2, v3, v4, i, j, k, l;
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
