
void foo3(int y, int z) {
    int x = 0;
    
    /*@
      loop invariant ((x == 0) && (z == \at(z,Pre)) && (y == \at(y,Pre))) || 
                    (1 <= x <= 5 && (z <= \at(y,Pre) ==> y == z) && (z > \at(y,Pre) ==> y == \at(y,Pre)));
      loop invariant 0 <= x <= 5;
      loop invariant z == \at(z,Pre);
      loop assigns x, y;
    */
    while(x < 5) {
        x += 1;
        if(z <= y) {
            y = z;
        }
    }
   
    /*@ assert z >= y; */
}
