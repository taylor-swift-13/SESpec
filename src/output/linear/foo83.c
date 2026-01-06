
void foo83(int y) {
    int x = -5000;
  
    /*@ 
        loop invariant x == -5000 + (y*(y-1))/2 - ((\at(y,Pre)*(\at(y,Pre)-1))/2);
        loop invariant y > \at(y, Pre) - 1;
        loop invariant y >= \at(y, Pre);
        loop assigns x, y;
    */
    while (x < 0) {
        x = x + y;
        y = y + 1;
    }
            
    /*@ assert y > 0; */
}
