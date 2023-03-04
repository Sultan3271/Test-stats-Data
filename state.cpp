#include "state.hpp"
#include "week-data.hpp"
#include <math.h>
int n = 0;
State::State() {
  name = " ";
  numberOfDataPoints = 0;
  weeks = new WeekData[500];
}
State::State(std::string name) { this->name = name; }

State::State(const State &rhs) {
  name = rhs.name;
  numberOfDataPoints = rhs.numberOfDataPoints;
}
State &State ::operator=(const State &rhs) {
  name = rhs.name;
  numberOfDataPoints = rhs.numberOfDataPoints;
}
State::~State() { delete[] weeks; }

std::string State::getName() const { return this->name; }
void State::addWeek(std::string weekData) {
  weeks[n] = WeekData(weekData);
  n++;
}
double State::getMeanDeaths() const {
  double mean = getMean(weeks, n);
  return mean;
}
double State::getStDev() const {
  double stdeviation = stDev(weeks, n);
  return stdeviation;
}

double State::getOutlierCount() const {
  
}
