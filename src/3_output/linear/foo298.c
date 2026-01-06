
void foo298() {
    int x;
    int z;

    x = 0;
    z = 5000000;

    /*@
      loop invariant 0 <= x <= 10000000;
      loop invariant z == 5000000 - (x >= 5000000 ? x - 5000000 : 0);
      loop assigns x, z;
    */
    while(x < 10000000) {
       if(x >= 5000000)
       z--;
       x++;
    }

    /*@ assert z == 0; */
}
