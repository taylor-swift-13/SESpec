void foo311(unsigned int n) {

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
    loop invariant v4 == \sum(integer t, 0, l-1, ((t % 4) == 0 && (t % 7) != 0 && (t % 6) != 0 && (t % 5) != 0 && (t % 3) != 0 && (t % 2) != 0));
    loop invariant v4 == \numof{integer t; 0 <= t < l && t % 4 == 0 && t % 5 != 0 && t % 6 != 0 && t % 7 != 0};
    loop invariant v4 == \floor(l/4);
    loop invariant v4 <= l;
    loop invariant v3 == \sum(integer t, 0, l-1, ((t % 5) == 0 && (t % 7) != 0 && (t % 6) != 0 && (t % 4) != 0 && (t % 3) != 0 && (t % 2) != 0));
    loop invariant v3 == \numof{integer t; 0 <= t < l && t % 5 == 0 && t % 6 != 0 && t % 7 != 0};
    loop invariant v3 == \floor(l/5);
    loop invariant v3 <= l;
    loop invariant v2 == \sum(integer t, 0, l-1, ((t % 6) == 0 && (t % 7) != 0 && (t % 5) != 0 && (t % 4) != 0 && (t % 3) != 0 && (t % 2) != 0));
    loop invariant v2 == \numof{integer t; 0 <= t < l && t % 6 == 0 && t % 7 != 0};
    loop invariant v2 == \floor(l/6);
    loop invariant v2 <= l;
    loop invariant v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0;
    loop invariant v1 == \sum(integer t, 0, l-1, ((t % 7) == 0 && (t % 6) != 0 && (t % 5) != 0 && (t % 4) != 0 && (t % 3) != 0 && (t % 2) != 0));
    loop invariant v1 == \numof{integer t; 0 <= t < l && t % 7 == 0};
    loop invariant v1 == \floor(l/7);
    loop invariant v1 <= l;
    loop invariant l <= n;
    loop invariant k == \sum(integer t, 0, l-1, ((t % 7) != 0 && (t % 6) != 0 && (t % 5) != 0 && (t % 4) != 0 && (t % 3) != 0 && (t % 2) != 0));
    loop invariant k == \numof{integer t; 0 <= t < l && t % 2 != 0 && t % 3 != 0 && t % 4 != 0 && t % 5 != 0 && t % 6 != 0 && t % 7 != 0};
    loop invariant k <= l;
    loop invariant j == \sum(integer t, 0, l-1, ((t % 2) == 0 && (t % 7) != 0 && (t % 6) != 0 && (t % 5) != 0 && (t % 4) != 0 && (t % 3) != 0));
    loop invariant j == \numof{integer t; 0 <= t < l && t % 2 == 0 && t % 3 != 0 && t % 4 != 0 && t % 5 != 0 && t % 6 != 0 && t % 7 != 0};
    loop invariant j <= l;
    loop invariant i >= 0 && j >= 0 && k >= 0;
    loop invariant i == \sum(integer t, 0, l-1, ((t % 3) == 0 && (t % 7) != 0 && (t % 6) != 0 && (t % 5) != 0 && (t % 4) != 0));
    loop invariant i == \numof{integer t; 0 <= t < l && t % 3 == 0 && t % 4 != 0 && t % 5 != 0 && t % 6 != 0 && t % 7 != 0};
    loop invariant i <= l;
    loop invariant i + j + k + v1 + v2 + v3 + v4 == l;
    loop invariant \forall unsigned int t; t < l && t % 7 == 0 ==> v1 >= 1;
    loop invariant \forall unsigned int t; t < l && t % 6 == 0 && t % 7 != 0 ==> v2 >= 1;
    loop invariant \forall unsigned int t; t < l && t % 5 == 0 && t % 6 != 0 && t % 7 != 0 ==> v3 >= 1;
    loop invariant \forall unsigned int t; t < l && t % 4 == 0 && t % 5 != 0 && t % 6 != 0 && t % 7 != 0 ==> v4 >= 1;
    loop invariant 0 <= l;
    loop assigns v4;
    loop assigns v3;
    loop assigns v2;
    loop assigns v1;
    loop assigns l;
    loop assigns k;
    loop assigns j;
    loop assigns i;
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
