//svcomp_odd
int hoo9(){

    //pre-condition
    int x = 1;

    //loop-body
    /*@
    Looking at the pattern of loop invariants in the examples and the code structure, here are the loop invariants for the `hoo9` function:
    
    ```c
    loop invariant x % 2 == 1;
    loop invariant x >= 1;
    loop assigns x;
    ```
    */
    while(unknown()){
        x = x + 2;
    }

    //post-condition
    /*@ assert x % 2 == 1; */
    
}