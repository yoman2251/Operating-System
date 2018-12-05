Programming Problems<br>
====
Chap.8 8.25*:<br>
------ 
Assume that a system has a 32-bit virtual address with a 4-KB page size.<br>
Write a C program that is passed a virtual address (in decimal) on the command line and have it output the page number and offset for the given address.<br>
As an example, your program would run as follows:<br>
* ./a.out 19986<br>
Your program would output:<br>
The address 19986 contains:<br>
* page number=4<br>
* offset=3602<br>
<br>
Writing this program will require using the appropriate data type to store 32 bits.<br>
We encourage you to use unsigned data types as well.<br>
