Philosopher Project
Overview

The Philosopher project is a part of the 42 network curriculum designed to teach students fundamental concepts in concurrent programming and resource synchronization. The project involves implementing a solution to the classic Dining Philosophers Problem, which serves as a practical exercise in understanding and applying concurrency, parallelism, mutex programming, and the use of pthreads.
Concepts Learned
Concurrency and Parallelism

    Concurrency: The ability of a system to handle multiple tasks at the same time. This project taught me how to manage concurrent processes, ensuring that they do not interfere with each other in a multi-threaded environment.
    Parallelism: The simultaneous execution of multiple tasks. I learned to leverage multi-core processors by running threads in parallel to improve performance.

Mutex Programming

    Mutex (Mutual Exclusion): A synchronization primitive used to prevent multiple threads from accessing a shared resource simultaneously. By using mutexes, I ensured that only one philosopher could pick up a fork at a time, preventing data races and ensuring data integrity.

Pthreads

    Pthreads (POSIX threads): A POSIX standard for implementing multithreading at the operating system level. This project provided hands-on experience with creating, synchronizing, and managing threads using the pthread library in C.

Project Description
The Dining Philosophers Problem

The Dining Philosophers Problem is a classic synchronization problem proposed by Edsger Dijkstra. The scenario involves five philosophers who alternately think and eat. They sit around a circular table with a bowl of spaghetti in the center and five forks placed between them. To eat, a philosopher must pick up the two forks adjacent to them. The challenge is to design a protocol that ensures:

    No two philosophers can use the same fork simultaneously.
    No philosopher will starve (each philosopher gets a chance to eat).
    The system does not deadlock (where all philosophers are waiting for a fork indefinitely).

Implementation Details

    Threads: Each philosopher is represented as a separate thread.
    Mutexes: Forks are represented by mutexes to ensure mutual exclusion when accessing them.
    Thread Synchronization: Proper synchronization techniques are used to ensure that no two philosophers pick up the same fork simultaneously, and to avoid deadlock situations.

Key Functions

    philosopher_thread(): The main function executed by each philosopher thread. It alternates between thinking and eating states.
    pickup_forks(): Function to pick up the two forks. It uses mutex locks to ensure mutual exclusion.
    putdown_forks(): Function to put down the two forks, releasing the mutex locks.
    think() and eat(): Simulated actions for thinking and eating, using sleep functions to mimic time spent in each state.

Compilation and Execution

To compile and run the project, use the following commands:

sh

gcc -pthread -o philosopher philosopher.c
./philosopher

Lessons Learned

    Concurrency Control: Learned to manage multiple threads and ensure they operate correctly without interfering with each other.
    Deadlock Prevention: Implemented strategies to prevent deadlock, ensuring that all philosophers eventually get to eat.
    Resource Sharing: Gained practical experience in using mutexes to manage access to shared resources safely.

Conclusion

The Philosopher project was an invaluable learning experience in understanding and applying concurrency and synchronization concepts. It provided a solid foundation in using pthreads and mutexes, which are essential tools in the development of robust, multi-threaded applications.
