public class LeapYearSeq {

    /*@ public normal_behavior
      @ ensures \result == ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
      @*/
    public  boolean isLeapYear(int year) {
        return ((year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? true : false) : true) : false);
   }
}