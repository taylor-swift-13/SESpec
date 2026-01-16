/*@
  requires n > 0;
*/
int hoo35(int n) {
       
    int guess;      
    int prev_guess; 
    guess = n / 2;  
    prev_guess = 0; 

    /*@
    loop invariant guess > 0;
    loop invariant prev_guess >= 0;
    loop invariant guess * guess >= n || (prev_guess - guess) * (prev_guess - guess) >= 0;
    loop assigns guess;
    loop assigns prev_guess;
    */
    while (guess != prev_guess) {
        prev_guess = guess;
        guess = (guess + n / guess) / 2;  
    }
    
    /*@ assert guess * guess <= n; */
}