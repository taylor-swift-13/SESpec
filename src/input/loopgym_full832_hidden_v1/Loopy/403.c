                                                                            
extern int unknown_int(void);
extern int unknown_bool(void);
/*@
  requires 0 <= k && k <= 1 && i == 1;
*/
void loopy_403(int i, int k) {
  
  
  
  while (unknown_bool()) {
    i = i + 1;
    k = k - 1;
  }
  {;

}

  return;
}