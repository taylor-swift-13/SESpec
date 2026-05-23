
void foo101(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

        /*@
          loop invariant iBegin == \at(iBegin,Pre);
          loop invariant iEnd == \at(iEnd,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant b_len == \at(b_len,Pre);
          loop invariant k == \at(iBegin,Pre) + (k - \at(iBegin,Pre));
          loop invariant \forall integer t; 0 <= t < iBegin ==> a[t] == \at(a[t], Pre);
          loop invariant \forall integer t; iEnd <= t < a_len ==> a[t] == \at(a[t], Pre);
          loop invariant k == iBegin ==> (\forall integer t; iBegin <= t < iEnd ==> a[t] == \at(a[t], Pre));
          loop invariant k > iBegin ==> (\exists integer u; iBegin <= u < k && a[u] == b[u]);
          loop invariant k - \at(iBegin,Pre) >= 0;

          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (iBegin <= k <= iEnd) ;

          loop invariant (!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)));
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant iEnd == \at(iEnd,Pre);
          loop invariant iBegin == \at(iBegin,Pre);
          loop invariant b_len == \at(b_len,Pre);
          loop invariant b == \at(b,Pre);

          loop invariant \forall integer t; 0 <= t < iBegin ==> a[t] == \at(a[t], Pre);
          loop invariant \forall integer t; iEnd <= t < a_len ==> a[t] == \at(a[t], Pre);

          loop assigns a[iBegin..iEnd-1], k;
        */
        while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }

}
