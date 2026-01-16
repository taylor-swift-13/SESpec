/*@
  requires a >= 0;
  requires b >= 0;
*/
int hoo37(int a, int b) {
    
    int product = 0;  
    int i = 0;        

    
    /*@
    /*@ 
      loop invariant 0 <= i <= b;
      loop invariant product == a * i;
      loop assigns i, product;
    */
    */
    while (i < b) {
        product = product + a;  
        i = i + 1;
    }

    
    /*@ assert product == a * b; */
}