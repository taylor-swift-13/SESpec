
int foo375(int num, int p) {

    if (p > num - p)
        p = num - p;
    int b = 1;
        
    /*@
      loop invariant 1 <= r ==> r >= 1;
      loop invariant r <= \at(p,Pre) ==> r <= \at(p,Pre);
      loop invariant 1 <= r && r <= \at(p,Pre) ==> num - r + 1 >= num - \at(p,Pre) + 1;
      loop invariant r >= 1 ==> num - r + 1 <= num; 
      loop invariant (r <= \at(p,Pre)) ==> (num == \at(num,Pre));
      loop invariant num == \at(num,Pre);
      loop assigns r, b;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (num - r + 1) / r;
    }
        
    return b;
}
