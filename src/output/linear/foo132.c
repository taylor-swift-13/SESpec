
void foo132(int j,int c,int t) {
    int i = 0;

    /*@
      loop invariant i >= 0;
      loop invariant c == \at(c,Pre);
      loop invariant (c <= 48 || c >= 57) ==> (i == 0 && t == \at(t,Pre) && j == \at(j,Pre));
      loop assigns i, j, t;
    */
    while(unknown()) {
        if(c > 48) {
            if (c < 57) {
                j = i + i;
                t = c - 48;
                i = j + t;
            }
        }
    }
     
    /*@ assert i >= 0; */
}
