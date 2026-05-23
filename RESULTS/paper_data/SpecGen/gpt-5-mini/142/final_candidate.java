public class OddEven {

	/*@ public normal_behavior
	  @ ensures \result == (x % 2 == 0);
	  @ assignable \nothing;
	  @*/
	public /*@ spec_public @*/ boolean isEven(int x) {
         	return x%2 == 0;
       	 }

	/*@ public normal_behavior
	  @ ensures \result == (x % 2 != 0);
	  @ assignable \nothing;
	  @*/
	public /*@ spec_public @*/ boolean isOdd(int x) {
         	return x%2 != 0;
       	 }
}