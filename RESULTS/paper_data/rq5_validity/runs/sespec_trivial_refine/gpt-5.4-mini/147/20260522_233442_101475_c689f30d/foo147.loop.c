
        /*@
        logic integer pow3(integer x);
        */
        
int foo147(int n) {

        int temp = n;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop assigns temp;
            */
            while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
            
        return temp == 1;
}
