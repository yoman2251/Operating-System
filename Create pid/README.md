Programming Problems<br>
====
Chap.3 3.13*:<br>
------ 
An operating system’s pid manager is responsible for managing process identifiers.<br>
When a process is first created, it is assigned a unique pid by the pid manager.<br>
The pid is returned to the pid manager when the process completes execution, and the manager may later reassign this pid.<br>
Process identifiers are discussed more fully in Sec.3.3.1.<br>
What is most important here is to recognize that process identifiers must be unique; no two active processes can have the same pid.<br>
Use the following constants to identify the range of possible pid values:<br>
* #define MIN_PID 300
* #define MAX_PID 5000
You may use any data structure of your choice to represent the availability of process identifiers.<br>
One strategy is to adopt what Linux has done and use a bitmap in which a value of 0 at position i indicates that a process id of value i is available and a value of 1 indicates that the process id is currently in use.<br>
Implement the following API for obtaining and releasing a pid:<br>
* int allocate_map(void): Creates and initializes a daat structure for representing pids; returns -1 if unsuccessful, 1 if successful
* int allocate_pid(void): Allocates and returns a pid; returns -1 if unable to allocate a pid (all pids are in use)
* Void release_pid(int pid): Releases a pid
