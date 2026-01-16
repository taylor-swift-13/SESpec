//svcomp_diamond_1-1
int hoo12(int y){

    //pre-condition
    int x = 0;
    
    //loop-body
    /*@
    loop invariant 0 <= x <= 99;
    loop invariant (x % 2) == (0 ? (y % 2) == 0 : (y % 2) == 1);
    loop assigns x;
    */
    while (x < 99) {
        if(y % 2 == 0){
            x = x + 2;
        } 
        else{
            x = x + 1;
        }
    }

    //post-condition
    /*@ assert (x % 2) == (y % 2); */
}