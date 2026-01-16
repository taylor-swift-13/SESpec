//svcomp_bin-suffix-5
int unknown();
int hoo2(){
    //pre-condiiton
    int x =5;
   
    //loop-body
    /*@
    loop invariant (x % 8) == 5;
    loop assigns x;
    */
    while(unknown()){
        x = x + 8;
    }

    //post-condition
    /*@ assert (x % 8) == 5; */
}