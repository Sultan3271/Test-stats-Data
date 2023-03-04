#include<iostream>
#include<vector>

class State{
  std::string name;
  WeekData* weeks;
  int numberOfDataPoints;

  public:
     State();
     State(std::string name);
     State(const State& rhs);
     State& operator=(const State& rhs);
     ~State();
     std::string getName() const;
     void addWeek(std::string weekData);
     double getMeanDeaths() const;
     double getStDev()const; 
     double getOutlierCount() const; 
     std::vector<std::string> getOutlierInfos()const;
};