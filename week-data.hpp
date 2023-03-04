#include<iostream>
#include<string>
class WeekData{
 std::string date;
  int deathCount;
  public:
      WeekData();
      WeekData(const std::string &inString);
      int getDeathCount() const;
      std::string info() const;
      
};