/*@
  requires n > 0;
*/
int hoo29(int n) {
    
    int guess;      
    int prev_guess; 

    guess = n / 2;  
    prev_guess = 0; 

    /*@
    /*@ 
      loop invariant guess > 0;
      loop invariant prev_guess >= 0;
      loop invariant guess * guess <= n;
      loop invariant prev_guess * prev_guess <= n;
      loop assigns guess, prev_guess;
    */
    */
    while (guess != prev_guess) {
        prev_guess = guess;
        guess = (guess + n / guess) / 2;  
    }
    
    /*@ assert (guess + 1) * (guess + 1) > n; */
}