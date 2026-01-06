
void foo107(int m,int j,int a) {

    int k = 0;
    
    /*@
      loop invariant  ((k == 0)&&(a == \at(a,Pre))&&(j == \at(j,Pre))&&(m == \at(m,Pre))) || (m == \max(\at(m,Pre), a));
      loop invariant  k == 0 || k == 1;
      loop invariant a == \at(a,Pre);
      loop invariant j == \at(j,Pre);
      loop assigns k, m;
    */
    while (k < 1) {
        if(m < a) {
            m = a;
        }
        k = k + 1;
    }

    /*@ assert a <= m; */
}
