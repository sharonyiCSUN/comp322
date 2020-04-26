Sharon Yi CS 322
Launch Tube - This project allows the user to see how the command-line tool that launches another process work first hand by printing 
out certain outputs based on what the user decides to input. There are 2 parts to this project, the first is Launch and the latter is
Tube. Launch uses child, parent processes to execute a particular program that you have inputted into the command-line. Based on what
has been entered, you can manipulate what you are able to see from /bin/ls. This is after you have compiled using "make all" in the 
console and then typing in "./launch /bin/ls" or "./launch /bin/ls -1 2>/dev/null" or "./launch /bin/ls -l foobar >/dev/null". If you
have done so, you will see the various outcomes that launch will display for the user.
Tube also uses child and parent processes for specific programs to be executed. In this part of the project, after we have chose to 
run "./tube /bin/cat filename, /usr/bin/head -2" or "./tube /bin/cat filename , /usr/bin/head -2 2>/dev/null" or "./tube /bin/cat
filename , /usr/bin/head -2 >/dev/null" in the command-line, the program will choose to envoke 2 child processes. From there a pipe
between the two processes will inter-process communicate to retrieve the data that is needed for this project. It will display the 
content within the filename that was inputted by the user.
