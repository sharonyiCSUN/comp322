Sharon Yi CS 322

Time 4 Baby and Me-
This program was written to allow the user to see the details and information that is going on behind the scenes that the user usually would not see front base. 
For example, once you have ran the code, you see the Process ID's of the parent and the child, etc. Right now, this instance, there are many process being generated and are still going on in your computer that you do not see or often think of. But this program lets you visualize what is going on in the background of your operating system.

How this program works is that it calls a fork() that generates a child process which initializes the time at that moment and the parent waits until the child is done with all it's functions; symmetrical. The child displays it's process ID, and it's parent's process ID and once it is done, process ID changes and gets sent to the parent's function. In the parent's function, the Process ID is dislayed and also it's parent's ID is displayed along with the Child's ID and the return value of the child. From there the program is written to display the User time, System time, the child's user and system time too. Finally, after the times have been displayed, the program can then display the time and proceed to shut the program down for conclusion. 
