class ConvertToFahrenheit {
    /*@ public normal_behavior
      @ ensures \result == celsius * 1.80 + 32.00;
      @ assignable \nothing;
      @*/
    public double convertTemperature(double celsius) {
        return celsius * 1.80 + 32.00;
    }
}