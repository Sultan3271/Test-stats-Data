# Project 1 Morbidity Data Analysis
[![Points badge](../../blob/badges/.github/badges/points.svg)](../../actions)
## Project Outcomes:

Develop a C++ program that uses:
- File input
- String parsing/generation (istringstream)
- Make, makefile and modular design
- Dynamic array (C array) allocation/management
- Basic statistical calculations

## Preparatory Readings:

- zyBook chapter 1, 2, 3
- zyBook Primer chapters
- Object array topic
- Memory management in classes topic

## Project Description

### Background
Data-driven apps are garnering a lot of attention in the modern world. The data
I/O component and the data analysis component are two essential parts of a
typical data-driven application.

The data I/O component concentrates on the methods for loading the data and
producing the output. To load from and save to the same data persistance module
is one solution. One of the most straightforward methods for data persistence
is based on file I/O on CSV (comma-separated values) files.

The data analysis component makes an effort to identify trends in the data and
produce insightful reports. Data analysis can be performed using statistical
functions or more complicated machine learning models. We will focus on
statistical functions here.

In this project, we will develop an app to load a real-world morbidity database
from a CSV file and allow user to query statistical metrics for data analysis
purposes.

### Statistical functions
#### Mean
The average, denoted **&mu;**, of a data set is usually referred to as the
*mean* of the data. For a data set `1, 2, 3, 5, 6`, the mean of that set is the
sum of all the data divided by the number of data points. e\.g\.

<img src="https://latex.codecogs.com/png.image?\dpi{110}&space;\bg_white&space;\frac{1&plus;2&plus;3&plus;5&plus;6}{5}=3.4" title="average" />

#### Standard Deviation
Standard deviation, often denoted **&sigma;** is an important statistical
metric to represent variation of a set of observations (data). It is calculated
as follows:

<img src="https://latex.codecogs.com/png.image?\dpi{110}&space;\bg_white&space;\sigma=\sqrt{\frac{\Sigma\(x_{i}-\mu\)^{2}}{N}}" title="standard deviation formula" />

`N` is the number of data points in the set (referred to in statistics as a
_population_). Thus, for the sample data set `1, 2, 3, 5, 6`, the mean
calculated above is 3.4. Plugging in for &sigma;, we'd get

<img src="https://res.cloudinary.com/dm3fdmzec/image/upload/v1597336594/stdev.png" alt="Standard deviation example" width=600 />

One important application of the standard deviation metric is to **identify
abnormal observations, outliers**. An outlier is an observation that are not
following the general trend of the data. In some convention, an observation
(data point) that is more than two standard deviations from the mean is
considered an outlier. Outliers are usually improperly measured, or unexpected
data points.

### Project Objective

We'll be using the above statistical functions on a set of input data to
identify unusual morbidity data reports grouped by state. The data from the CDC
was sourced
[here](https://data.cdc.gov/NCHS/Weekly-Counts-of-Deaths-by-State-and-Select-Causes/muzy-jte6)
and
[here](https://data.cdc.gov/NCHS/Weekly-Counts-of-Deaths-by-State-and-Select-Causes/3yf8-kanr).


### Project Requirements:
Your application must function as described below:
1. In order to ensure that your statistical calculations are correct, your
   program must pass all of the given tests in the cpp files in the
   [test](test/) directory.
    1. The test suites are:
        1. [test-week](test/test-week.cpp) - This tests the object used to
        store the data for a given week.
        1. [test-stats](test/test-stats.cpp) - This tests the static methods
        needed to do the necessary calculations.
        1. [test-state](test-state.cpp) - This tests the object used to store
        the data for a given state.
        1. [test-morbidity](test/test-morbidity.cpp) - This tests your file
        reading functions and is essentially an integration test. Once it
        is running, you are ready to build the main program (which should
        at that point be rather trivial).
    1. Must able to pass all tests with `make test-all`.
1. Must be able to compile a main executable using the command  `make main`.
2. Must be able to run your program using `./main` after it is compiled.
1. Running the main program should prompt a user for the input file name. If
   the input file is not present, **Unable to read input file** should be
   displayed and the user should be prompted again to enter a valid
   file name.
1. Once the file has been loaded, your program should offer the ability to
   query for the following outputs:
    1. All-time average (mean) of a given state.
    1. List of weeks that are statistical outliers of a given state.
    1. List all states and their respective count of outlier weeks, whose death
       count are more than two standard deviations from the mean.
1. You will lose points on memory leaks.

## Code Organization

Read the [Makefile](Makefile) for files required in this project. Hint: A .o
files required in the Makefile means a corresponding cpp file.

Read the tests in the cpp files in the [test](test/) directory for the expected
usages of all classes and functions.

### Class descriptions and UML Class diagrams
Read this [document](https://plantuml.com/class-diagram) for
more information about the syntax of class diagrams (PlantUML style).

+ The stats library (not a class!)

  Two statistical functions to calculate the mean and standard deviation of
  deaths out of an array of WeekData objects.

    - ``double getMean(WeekData *weeks, int count);``
    - ``double stDev(WeekData *weeks, int count);``

+ The WeekData class

![UML of Week class](http://www.plantuml.com/plantuml/png/SoWkIImgAStDuKhEIImkLWXFJSrsIIn9LAZcqbKeBacniYekAShCIrT8IIn91GfbvfKefAGcbcGuvvVcbN1fmpLeQ29palFpYajGzAjbvWM3MK1rO5FIKqjSu0PfQ2g0jG3ba3G1rQNbmwLgkHnIyrA0JWK0)

+ The State class

    - You can allocate **500** as the size for the ``weeks`` array.

![UML of State class](http://www.plantuml.com/plantuml/png/RO-zJWCn48JxUugj8dx42qI08d4D1GGf1VNcl4aix5taNLyA1C-EdQ0xW-X6ytbcrYirJ9PZw8Q0gh0nD8AFxWRKt7AfbZplWJ5IiLw9tdeql89ZKLeSpmQSuvRIUbV9YnH7k-jppyNbfFwspMGGLZlh1QI3JcG1yau9JTBTlu--vessVK_sZB7uS0eLEeftWCxLytyTSlpvJwrmahU1Qlg9a7j2EsZJCUEDzJGsnBDLUvqjU4eFajaQUfeRQJ19jytqVHDvv9tCKv_TYjZb6Bu1)

+ The Morbidity class

    - The ``states`` instance variable is a **one dimension array of pointers**
      to the objects rather than a two dimensional array of the objects! You
      can assume that there be at most **65** states and allocate the array
      using this size.
    - The ``load()`` method should return false on a file that cannot be
      opened.

![UML of Morbidity class](http://www.plantuml.com/plantuml/png/bP3DIiKm48NtVOfPIRtY2rn4AeBWedRX4oJDj0GcCv2P22Bwx3QfuWyklBlCdEyx2HdKNBQIg9l9gS8esSSGxHbUkak8RC0bUSpJycZEKBTbEy3XeFlYuilfpxVfxUVeHGX8NEXdOJLG2yUZMewymjaI2Tabh62GuWbXHHlHyLzqk_2Xuj3IJOfirMXFcefHn7mhXUsVUikVS3R9Lz_Owz-TUahVdjUA3_kU5xcJV4Eq_s7_ARns0t8eYTu1)
### Sample data

The data will be in the following format. For this project, it is safe assume
the data is properly formatted, that is exactly 3 columns will be present in
each row of data.

    State,Week Ending Date,All Cause
    Florida,2014-01-04,2101
    Florida,2014-01-11,3877
    Florida,2014-01-18,3800

There is a data.csv file provided in the repository. You can test your code on
it. It is suggested to make a smaller data file with some representative data
in it in testing or debugging processes.

### Sample Run
<pre><code>
Welcome to the data viewer!
Enter the file name with the morbidity data: <b>foo.bar</b>
Unable to read input file!
Enter the file name with the morbidity data: <b>data.csv</b>
    1 - Output the mean for a state
    2 - Get a list of outliers for a state
    3 - List all states with outlier counts
    anything other than 1-3 will end the application.
Please choose an option from the above menu: <b>1</b>
Enter the name of the state to search: <b>Texas</b>
-------------------------
The mean deaths for Texas is 4000.91
-------------------------
    1 - Output the mean for a state
    2 - Get a list of outliers for a state
    3 - List all states with outlier counts
    anything other than 1-3 will end the application.
Please choose an option from the above menu: <b>2</b>
Enter the name of the state to search: <b>North Carolina</b>
-------------------------
Statistical outliers for North Carolina
    2020-12-19 - total deaths: 2588
    2020-12-26 - total deaths: 2670
    2021-01-02 - total deaths: 2837
    <b>... Sample output truncated for brevity</b>
    2021-07-24 - total deaths: 495
    2021-07-31 - total deaths: 434
    2021-08-07 - total deaths: 319
-------------------------
    1 - Output the mean for a state
    2 - Get a list of outliers for a state
    3 - List all states with outlier counts
    anything other than 1-3 will end the application.
Please choose an option from the above menu: <b>3</b>
-------------------------
    Alabama: 16 outlying weeks
    Alaska: 18 outlying weeks
    <b>... Sample output truncated for brevity</b>
    Wisconsin: 14 outlying weeks
    Wyoming: 18 outlying weeks
-------------------------
   1 - Output the mean for a state
   2 - Get a list of outliers for a state
   3 - List all states with outlier counts
   anything other than 1-3 will end the application.
Please choose an option from the above menu: <b>9999</b>
</code> </pre>

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and
  whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects
  received after that time will get a penalty or zero.
- Never change the test files! The results you get will be pointless as they
  will not align with our grading.
- Never change the makefile unless you are asked to do so
- Please review the academic honesty policy.
  - Note that viewing another student's solution, whether in whole or in part,
    is considered academic dishonesty.
  - Also note that submitting code obtained through the Internet or other
    sources, whether in whole or in part, is considered academic dishonesty.
    **All programs submitted will be reviewed for evidence of academic
    dishonesty, and all violations will be handled accordingly**.

### Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted"
   the assignment.
   1. After pushing, with `git push origin main`, visit the web URL of your
   repository to verify that your code is there. If you don't see the code
   there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your score for your submission.
   1. The auto-grading build should begin automatically when you push your code
      to GitHub.
   2. If your program will not compile, the graders will not be responsible for
      trying to test it.
   3. You should get an email regarding the status of your build, if it does
      not pass, keep trying.
4. **Never remove provided files!** Some data file and input files are
   essential in testing and autograding.

## Grading
- Breakdown
  + 90 pts GitHub Auto-grading
    * 10 pts test-week
    * 10 pts test-stats
    * 10 pts test-state
    * 10 pts test-morbidity
    * 10 pts query Hawaii mean
    * 10 pts query Florida for outliers
    * 10 pts list all states for outlying counts
    * 20 pts memory leak check
  + 10 pts Code style
- Auto-grading results can be checked at the top of this document like as a
  badge ***40/90***.
- View details:
    1. On your GitHub repo page, Click the :arrow_forward: **Actions** tab to
       see your graded results.
    1. If it isn't a green check mark (:heavy_check_mark:) then at least part of
       the testing failed.
    1. Click the commit message for the failing version then click "Autograding"
       on the left side of the page.
    1. Follow the :x: path and expand things to see what errors exist.
    1. It is usually **education/autograding@v1** and you can expend this path to
       view the detail.
