#include"week-data.hpp"

WeekData::WeekData(){
    date="0000-00-00";
    deathCount= 0;  
}
WeekData::WeekData(const std::string &inString){
std::istringstream Stream(inString);
std::string word;

std::getline(Stream, word, ','); 
  this->date=word;
  std::getline(Stream, word, ','); 
  this->deathCount=stoi(word);

  }
int WeekData::getDeathCount() const{
   return this->deathCount;
}
std::string WeekData::info()const{
   std::cout<<date<<" - total deaths: "<<deathCount;
}





