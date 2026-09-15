int foo8(int num1, int num2, char operator);


/*@ 
  requires \true; 
  assigns \nothing; 
  ensures (operator == '+' ==> \result == num1 + num2) &&
          (operator == '-' ==> \result == num1 - num2) &&
          (operator == '*' ==> \result == num1 * num2) &&
          (operator == '/' && num2 != 0 ==> \result == num1 / num2) &&
          (operator == '%' && num2 != 0 ==> \result == num1 % num2) &&
          ((operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%') ==> \result == -1);
*/
int foo8(int num1, int num2, char operator) {

        int output;

        switch (operator)
        {
            case '+':
            	output = num1 + num2;
                break;

            case '-':
            	output = num1 - num2;
                break;

            case '*':
            	output = num1 * num2;
                break;

            case '/':
            	output = num1 / num2;
		break;

	    case '%':
		output = num1 % num2;
                break;

            default:
                return -1;
        }
        return output;
}