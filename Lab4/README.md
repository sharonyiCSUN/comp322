Sharon Yi CS 322 Philosopher's dining Rice, Rice, and Rice - This project uses semaphores 
in c to help the coder understand how to prevent deadlocks. It shows the coder first-hand
how you can use hold & wait, and circular wait. There are the eat() and think() functions
that put the philosophers into a state of being which then signals the handler for SIGTERM
to then remove them from that cycle. The programmer uses functions such as sem_destroy() and
sem_close() to do so. The overall concept of this project is to help the coder understand 
how semaphores work and use them efficiently within our code.
