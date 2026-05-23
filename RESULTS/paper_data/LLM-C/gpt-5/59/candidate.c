/*@ 
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int unknown();

/*@
  assigns x, y;
  ensures y == 0 || y == 1;
*/
void foo243() {

    unsigned int x;
    unsigned int y;

    y = 1;

    /*@
      loop assigns x, y;
      loop invariant y == 0 || y == 1;
      loop variant 0;
    */
    while(unknown()){
       if(x % 3 == 1){
       /*@ assert x % 3 == 1; */
       x = x + 2;
       /*@ assert x % 3 == 0; */
       y = 0;
       /*@ assert y == 0; */
      }
       else{
       if(x % 3 == 2){
       /*@ assert x % 3 == 2; */
       x = x + 1;
       /*@ assert x % 3 == 0; */
       y = 0;
       /*@ assert y == 0; */
      }
       else{
       /*@ assert x % 3 == 0; */
       if(unknown()){
       x = x + 4;
       /*@ assert x % 3 == 1; */
       y = 1;
       /*@ assert y == 1; */
      }
       else{
       x = x + 5;
       /*@ assert x % 3 == 2; */
       y = 1;
       /*@ assert y == 1; */
      }
      }
      }
      /*@ assert y == 0 <==> x % 3 == 0; */
      }

  }
