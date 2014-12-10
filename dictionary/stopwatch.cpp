#include "stopwatch.h"

int StopWatch::readValue(void)
{
  return ( static_cast<int> (value));
}

StopWatch::StopWatch()
{
  value = 0;
}

void StopWatch::reset(void)
{
  value = 0;
}

void StopWatch::stop(void)
{
  stopTime = clock();
  value += static_cast<int>(stopTime - startTime);
}

void StopWatch::start(void)
{
  startTime = clock();
}
