import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

    /*@
      @ ensures a == null ==> \result == -1;
      @ ensures a != null ==> 0 <= \result && \result <= (a.length * (a.length - 1)) / 2;
 
      @     (\result