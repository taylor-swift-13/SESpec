int foo354(int num);


/*@
ensures \exists integer even_62, sum_61; (sum_61 <= 0) && (0 <= even_62) && (sum_61 == num >> even_62) ==> (\result == (num | 0));

assigns \nothing;
*/

int foo354(int num) 
{

    int even = 0;
    int result = 0;
    int sum = num;
        
    /*@
      loop invariant num == \at(num,Pre);
      loop invariant 0 <= even;
      loop invariant sum == (\at(num,Pre) >> even);
      loop assigns result, even, sum;
    */
    while (sum > 0) {
        if (even % 2 == 1) {
            result |= (1 << even);
        }
        even++;
        sum >>= 1;
    }
            
    return (num | result);
}