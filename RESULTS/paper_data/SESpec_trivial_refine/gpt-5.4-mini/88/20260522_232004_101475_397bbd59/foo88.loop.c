
        /*@
        */
        
void foo88(int k){

    int y=0;
    int x=0;
    int c=0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= 0;
          loop invariant y == c;
          loop invariant x == c*(c+1)*(2*c+1)*(3*c*c+3*c-1)/30;
          loop assigns c, y, x;
            */
            while(c < k){
     c = c +1 ;
     y = y +1;
     x = y*y*y*y+x;
    }
            

}
