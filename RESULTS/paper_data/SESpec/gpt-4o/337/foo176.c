
/*@
  requires num >= 0;
  assigns \nothing;
*/
int foo176(int num) {

    int ret = 0;
    
    /*@
      loop assigns j, ret, num;
    */
    for (int j = 2; j <= num; j++) {
        
        /*@
          loop assigns j, ret, num;
        */
        while (num % j == 0) {
            ret = j;
            num /= j;
        }
        
    }
            
    return ret;
}
