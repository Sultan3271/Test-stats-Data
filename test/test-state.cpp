#include <sstream>

#include "../state.hpp"
#include "catch/catch.hpp"

TEST_CASE("Testing State class on calculation") {
  State bama("Alabama");
  CHECK("Alabama" == bama.getName());

  bama.addWeek("2020-05-02,2000");
  bama.addWeek("2020-05-09,2000");
  bama.addWeek("2020-05-16,100");
  bama.addWeek("2020-05-23,2000");
  bama.addWeek("2020-05-30,2000");
  bama.addWeek("2020-06-06,2000");

  CHECK(Approx(1683.33).epsilon(0.01) == bama.getMeanDeaths());

  CHECK(Approx(708.08).epsilon(0.01) == bama.getStDev());

  CHECK(1 == bama.getOutlierCount());
  auto outliers = bama.getOutlierInfos();
  CHECK("2020-05-16 - total deaths: 100" == outliers.at(0));
}

TEST_CASE("Testing State class on rule of three") {
  State bama("Alabama");
  CHECK("Alabama" == bama.getName());
  State bama1(bama);
  CHECK("Alabama" == bama1.getName());
  State bama2;
  bama2 = bama;
  CHECK("Alabama" == bama2.getName());
}
