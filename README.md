# Philosopher Project
## Overview

The Philosopher project is part of the 42 network curriculum, focusing on concurrent programming and resource synchronization. It involves solving the Dining Philosophers Problem, a classic concurrency challenge.

## Concepts Learned
### Concurrency and Parallelism

* **Concurrency**: Managing multiple tasks simultaneously without interference.
* **Parallelism**: Executing multiple tasks at the same time for improved performance.

### Mutex Programming

* **Mutex (Mutual Exclusion)**: Prevents multiple threads from accessing shared resources simultaneously, ensuring data integrity.

### Pthreads

* **Pthreads (POSIX threads)**: Standard for implementing multithreading. Gained experience in creating, synchronizing, and managing threads using the pthread library in C.

## Project Description
**Dining Philosophers Problem**: Five philosophers alternate between thinking and eating at a circular table with five forks.
Philosophers need two forks to eat, leading to potential deadlocks and resource contention.
The goal is to design a protocol ensuring no deadlock and fair access to resources.

## Implementation

* **Threads**: Each philosopher is a separate thread.
* **Mutexes**: Forks are mutexes ensuring mutual exclusion.
    

## Compilation and Execution

```bash
git clone https://github.com/khalidlakbuichy/philosopher.git
```
```bash
cd philosopher
```
``` bash
make
```
```bash
./philosopher number_of_philosophers time_to_die time_to_eat time_to_sleep 
[number_of_times_each_philosopher_must_eat]
```
## Lessons Learned

* **Concurrency Control**: Managing multiple threads effectively.
* **Deadlock Prevention**: Implementing strategies to avoid deadlock.
* **Resource Sharing**: Using mutexes for safe resource access.

## Conclusion

The Philosopher project provided valuable experience in concurrency, synchronization, and multithreading, essential for developing robust applications.
