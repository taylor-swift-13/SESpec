/*@
  requires a >= 0;
  requires b >= 0;
*/
int hoo37(int a, int b) {
    
    int product = 0;  
    int i = 0;        

    
    /*@
    */
    while (i < b) {
        product = product + a;  
        i = i + 1;
    }

    
    /*@ assert product == a * b; */
}