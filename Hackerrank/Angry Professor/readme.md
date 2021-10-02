# Angry Professor
Problem Link : https://www.hackerrank.com/challenges/angry-professor/problem

## Problem Statement:
A Discrete Mathematics professor has a class of students. Frustrated with their lack of discipline, the professor decides to cancel class if fewer than some number of students are present when class starts. Arrival times go from on time ( *arrivalTime <= 0* ) to arrived late ( *arrivalTime > 0* ).

Given the **arrival time** of each student and a **threshold** number of attendees, determine if the class is cancelled.

### Example
*n = 5* <br> *k = 3* <br> *a = [-2,-1,0,1,2]* <br>
The first **3** students arrived on. The last **2** were late. The threshold is **3** students, so class will go on. Return **YES**.

> Note: Non-positive arrival times ( *a[i] <= 0* ) indicate the student arrived early or on time; <br> &emsp; &emsp;  positive arrival times ( *a[i] > 0* ) indicate the student arrived *a[i]* minutes late.

### Function Description
Complete the angryProfessor function in the editor. It must return YES if class is cancelled, or NO otherwise.
angryProfessor has the following parameter(s):
* int k: the threshold number of students
* int a[n]: the arrival times of the *n* students

### Returns
* string: either YES or NO

#### Sample 1
__Input__
```
4 3
-1 -3 4 2
```
__Output__
```
YES
```

#### Sample 2
__Input__
```
4 2
0 -1 2 1
```
__Output__
```
NO
```
