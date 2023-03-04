#include<iostream>

class Morbidity{
 int numberOfStates;
 State** states;
  public:
     Morbidity();
    ~Morbidity();
     bool load(const std::string &fileName);
     double getMean(std::string &stateName)const;
     int getstateOutlierCount(const std::string &stateName)const;
     std::vector<std::string> getStateOutliers(const std::string &stateName)const;
     std::string getstateOutliersForAllStates()const;
};