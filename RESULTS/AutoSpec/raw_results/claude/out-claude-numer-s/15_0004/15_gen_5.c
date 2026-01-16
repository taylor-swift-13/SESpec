//svcomp_benchmark38_conjunctive
int unknown();

int hoo15(){
    int x = 0;
    int y = 0;

  

    //loop-body
    /*@
    */
    while (unknown()) {
        x += 4;
        y++;
    }

    //post-condition
    /*@ assert x == 4 * y; */
}