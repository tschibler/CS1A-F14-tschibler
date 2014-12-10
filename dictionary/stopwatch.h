// StopWatch class
// P. Conrad, Feb 26, 2004
// measures elapsed CPU time

#include <time.h>

clock_t clock(void);

class StopWatch 
{
 private: 
  clock_t startTime; // time the stop watch was started
  clock_t stopTime; // stop the stop watch
  int value;  // current value of stop watch
 public:
  StopWatch(); // constructor: make a new stopwatch
  void reset(); // reset the stopwatch
  void stop(); // stop the stopwatch
  void start(); // start the stopwatch
  int readValue(); // read the value of the stopwatch in seconds.

};
