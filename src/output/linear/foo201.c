
/*@
    requires x <= -2 && x >= -3;
    */
    
void foo201(int x) {

        /*@
          loop invariant x >= -3 && (x == -3 || x == -2 || x == -1 || x == 0 || x == 1 || x % 1 == 0);
          loop assigns x;
        */
        while(unknown()){
            if(x < 1){
                x = x + 2;
            }
            else if(x >= 1){
                x = x + 1;
            }
        }

    /*@ assert x >= -5; */
}
