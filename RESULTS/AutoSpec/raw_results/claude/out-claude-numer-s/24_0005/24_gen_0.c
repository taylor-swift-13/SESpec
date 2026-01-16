/*@
  requires n > 0;
*/
int hoo24(int n,int guess,int prev_guess) {


    guess = n / 2;  
    prev_guess = 0; 

    /*@
    /*@ 
      loop invariant guess > 0 && prev_guess >= 0;
      loop invariant guess <= n;
      loop invariant prev_guess < guess || prev_guess == 0;
      loop assigns guess, prev_guess;
    */
    */
    while (guess != prev_guess) {
        prev_guess = guess;
        guess = (guess + n / guess) / 2;  
    }
    
    /*@ assert guess * guess <= n; */
}