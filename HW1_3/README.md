Programming Problems<br>
====
Chap.3  3.20*:<br>
------
Design a file-copying program named filecopy using ordinary pipes.<br>
This program will be passed two parameters:the name of the file to be copied and the name of the copied file.<br>
The program will then create an ordinary pipe and write the contents of the file to be copied to the pipe.<br>
The child process will read this file from the pipe and write it to the destination file.<br>
For example, if we invoke the program as follows:<br>
* filecopy input.txt copy.txt
the file input.txt will be written to the pipe.<br>
The child process will read the contents of this file and write it to the destination file copy.txt.<br>
You may write this program using either UNIX or Windows pipes.
![](https://github.com/yoman2251/Operating-System/tree/master/HW1_3/pipi.jpg)