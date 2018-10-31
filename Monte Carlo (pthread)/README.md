Programming Problems<br>
====
Chap. 4  4.17*:<br>
------
An interesting way of calculating PI is to use a technique known as Monte Carlo, which involves randomization.<br>
This technique works as follows:<br>
Suppose you have a circle inscribed within a square, as shown in Figure 4.18.<br>
(Assume that the radius of this circle is 1.)<br>
First, generate a series of random points as simple (x,y) coordinates.<br>
These points must fall within the Cartesian coordinates that bound the square.<br>
Of the total number of random points that are generated, some will occur within the circle.<br>
Next, estimate PI by performing the following calculation: PI =4*(number of points in circle)/(total number of points)
<br>
Write a multithreaded version of this algorithm that creates a separate thread to generate a number of random points. The thread will count the number of points that occur within the circle and store the result in a global variable. When this thread has exited, the parent thread will calculate and output the estimated value of PI. 

