//svcomp_mod4
int unknown();
int hoo8(){
    

    //pre-condition
    int x = 0;

    //loop-body
    /*@
    loop invariant x % 4 == 0;
    loop assigns x;
    loop variant /* any integer expression that decreases, e.g., 0 (if unknown() does not guarantee termination) */;
    */
    while(unknown()){
        x = x + 4;
    }

    //post-condition
    /*@ assert x % 4 == 0; */
    
}