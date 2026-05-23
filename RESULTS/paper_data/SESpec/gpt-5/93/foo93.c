int foo93(int num1, int num2, char operator);


/*@
  assigns \nothing;
  ensures (operator == '-') ==> \result == num1 * num2;
  ensures (operator == '*') ==> \result == num1 / num2;
  ensures (operator == '/') ==> \result == num1 + num2;
  ensures (operator == '+') ==> \result == num1 - num2;
  ensures !(operator == '-' || operator == '*' || operator == '/' || operator == '+') ==> \result == -1;
*/
int foo93(int num1, int num2, char operator) {

        int output;

        switch (operator)
        {
            case '-':
            	output = num1 * num2;
                break;

            case '*':
            	output = num1 / num2;
                break;

            case '/':
            	output = num1 + num2;
                break;

            case '+':
            	output = num1 - num2;
		break;

            default:
                return -1;
        }
        return output;
}