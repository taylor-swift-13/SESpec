//svcomp_mod4
int unknown();
int hoo8(){
    

    //pre-condition
    int x = 0;

    //loop-body
    /*@
    loop invariant x % 4 == 0;
    loop invariant 0 <= x;
    loop assigns x;
    */
    while(unknown()){
        x = x + 4;
    }

    //post-condition
    /*@ assert x % 4 == 0; */
    
}