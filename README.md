# UOS 4th Seminar Assignments

-----

You work in a company that deals with, among other things, data processing and analysis. Your CTO has decided that for a new project you will use decision trees to make predictions. They have the advantage of being easy to interpret, as well as a simple system of decision rules that your client can easily understand.

Your colleague prepared a Python script and put it in this GIT repository. The script generates a decision tree from the input dataset and renders it into an image. Now you need to test it.

However, the production data is unavailable at this time. So it will be up to you to prepare a simple random generator that will return a CSV file that can be used as an input for your colleague's script. It is important for you to make the generation efficient. That is why you have chosen the C language. 

But fortunately you remembered that you've already made a simple generator in C (attached below) that returns random weather data. So it's okay to just modify it and then save its output to a file.

-----

## Your tasks

### 1. Clone this GIT repository

Clone it to the uos server. You can use your home directory for this.

### 2. Verify dependencies

Run a command that verifies that all the necessary Python packages (in requirements.txt) are installed and if not, install them. Try to run `tree.py` script using `python3`. This should check that the necessary packages are available. However, the script will return an error that it did not find the CSV file with the data.

### 3. Prepare a C generator

Prepare a C program which generates the input data. Since we are dealing with [classification](https://www.simplilearn.com/tutorials/machine-learning-tutorial/classification-in-machine-learning#what_is_classification), it is important that these are records that belong to different classes.

In the example below, for instance, the random weather data for each day is included along with information about raining tomorrow. The decision tree can then be used as a simple system of rules that will generally determine if it rains tomorrow.

Also in your case, each row have to have information about the class (raining / not raining, healthy / sick, etc.). The recommendation is to have two classes for simplicity, but you can have more (not raining / raining a little / raining a lot).

If you want to use the code below, edit at least

- dataset size,
- header names,
- columns count,
- columns value ranges.

### 4. Save output into a file

The resulting generator from the previous step should be set up to return a data dump to standard output (stdout). 

At this stage, you will need to compile the program. If it doesn't contain any syntax errors, the compilator should create an executable binary in your current directory.

Now run the compiled program and redirect its output to a file named `data.csv`. This data file should be located in the same directory as the `tree.py` script.

### 5. Run the Python script and get the result

Try to run `tree.py` script using `python3` again. If everything is okay, the script will print your dataset to stdout and generate an image with a decision tree visualization. This image should be named `decistion_tree.png`. Download it to your computer, for example using WinSCP and have a look.

-----

## Bonus tasks for extra points

1. Create your own GIT repository on GitHub, GitLab or Bitbucket. Create and push a commit that contains your modifications - the C program, the decision tree image, and generated `data.csv` file.

2. Create a bash script that automates the entire process: clone the repository, run the C program, save the output to `data.csv`, and run the Python script that generates the decision tree.

3. Redesign the C program so that it creates the `data.csv` file directly after execution and doesn't return its contents to the standard output.

-----

## Your OG generator written in C

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int min, int max) {

    // Random number in interval [min, max]
    return rand() % (max - min + 1) + min;
}

int main() {

    // Number of records in the dataset
    const int DATASET_SIZE = 50;

    // Seed random number generator with current time
    srand(time(NULL));

    printf("%s\n", // Dataset header (must match the number of columns)
        "clouds,a_pressure,temperature,humidity,rainy_tomorrow"
    );

    for (int i = 0; i < DATASET_SIZE; i++) {

        printf(
            "%d,%d,%d,%d,%s\n",
            random(0, 100),                     // clouds in %
            random(970, 1050),                  // atmospheric pressure in hPa 
            random(-10, 35),                    // temperature in °C
            random(30, 95),                     // relative humidity in %
            random(0, 1) ? "\"yes\"" : "\"no\"" // rainy or not
        );
    }

    return 0;
}
```