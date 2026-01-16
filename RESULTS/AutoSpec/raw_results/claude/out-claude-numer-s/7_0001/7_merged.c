//svcomp_even
int hoo7(int a){
    
    //pre-condition
    int x = 0;

    //loop-body
    /*@
    loop invariant x % 2 == 0;
    loop invariant 0 <= x;
    loop assigns x;
    */
    while(unknown()){
        x = x + 2;
    }

    //post-condition
    /*@ assert x % 2 == 0; */
    
}