Programming Problems<br>
====
Chap.6  6.33*:<br>
------
Exercise 4.17 asked you to design a multithreaded program that estimated pi using the Monte Carlo technique.<br>
In that exercise, you were asked to create a single thread that generated random points, storing the result in a global variable.<br>
Once that thread exited, the parent thread performed the calculation that estimated the value of pi.<br>
Modify that program so that you create several threads, each of which generates random points and determines if the points fall within the circle.<br>
Each thread will have to update the global count of all points that fall within the circle. Protect against race conditions on updates to the shared global variable by using mutex locks.