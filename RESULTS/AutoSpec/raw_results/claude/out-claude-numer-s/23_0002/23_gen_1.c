/*@
  requires a > 0;
  requires b > 0;
*/
int hoo23() 
{
    
    int a, b;
    int product = 0; 
    int i = 0;


    
    /*@
    */
    while (i < b) {
        product = product + a;  
        i = i + 1;
    }

    
    
    /*@ assert product * product == (a * b) * (a * b); */
}