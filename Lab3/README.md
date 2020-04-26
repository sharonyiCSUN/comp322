Sharon Yi CS 322 catcher - This project allows the user to input signals that would like to be monitored; for example: ./catcher
TERM USR1 USR2. The program will return the process ID to the user that they can use to manipulate signals; for example: 
./catcher: $$ = 1337. You can use that ID to kill processes in a second console window; for example: kill -USR1 1337. You will 
then be able to terminate the program if you call kill -TERM (PID) 3 times. From there, the program will display the total 
count of how many times you have caught (kill) a process. 
