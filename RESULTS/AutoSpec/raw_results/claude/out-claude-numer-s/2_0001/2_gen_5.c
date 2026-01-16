//svcomp_bin-suffix-5
int unknown();
int hoo2(){
    //pre-condiiton
    int x =5;
   
    //loop-body
    /*@
    */
    while(unknown()){
        x = x + 8;
    }

    //post-condition
    /*@ assert (x % 8) == 5; */
}