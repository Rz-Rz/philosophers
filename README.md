# Philosophers
### Introduction
The dining philosophers problem is a classic problem in computer science and philosophy that was first introduced by Edsger Dijkstra in 1965. The problem deals with a scenario in which five philosophers are sitting at a round table with five plates of food and five chopsticks. Each philosopher must pick up two chopsticks in order to eat, one from their plate and one from the plate to their left. The problem lies in the fact that the philosophers may become deadlocked or starve as they wait for a chopstick that is being held by another philosopher.

This problem serves as a metaphor for **resource allocation and synchronization** in a concurrent system, and has been used to demonstrate the difficulties of developing correct and efficient algorithms for coordinating multiple tasks. The dining philosophers problem continues to be a popular topic of research and discussion in the field of concurrent algorithms and is widely considered to be one of the classic problems in computer science.

### Special Spin: Adding dynamic values !
Now just working with 5 philosophers is quite boring right ? How about working with n philosophers (up to a two hundred (or more...))? And what if we could assign to each of them different amount of time they have to perform a different set of action ? Well that's what we are going to do, we will give them a specific amount of time for each action. So we will give our ./program the **<nb_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>** and why not add an optional parameter that is the **<max_nb_of_meals>**. The time_to_die will be used to set the death of a philosopher in case he did not eat for that length of time. Then our philos will be eating for time_to_eat, and finally they will have to sleep for time_to_sleep. Quite important to note, all length of time will be given in **milliseconds** (ms). There is one more action they can perform, that is thinking, but does not take dynamic values.

### Installation
To test the project, go to one of the folders philo or philo_bonus and use **make**. Then, you can test the project using an executable.

usage :
```bash
./philo <number_philosopher> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_time_each_philosophers_must_eat>]
```
example :
```
./philo_one 4 410 200 200
```

### Rules
Let's remind ourselves of the rules:
- N philosophers are sitting around a round table, surrounded by a big plate of delicious spaghetti.
- These philosophers have three modes of existence: eating, thinking, and sleeping.
- If they're eating, they can't think or sleep.
- If they're sleeping, they can't eat or think.
- If they're thinking, they can't eat or sleep (what a shame!)
- There are five forks on the table, one for each philosopher.
- Eating spaghetti with just one fork is tough work, so a philosopher grabs the fork to their left and the fork to their right to enjoy their meal.
- Once they're done eating, they put the forks back on the table, take a nap, and then start thinking again.
- The simulation ends if a philosopher dies from hunger.
- All philosophers need to eat and must not die of hunger!
- The philosophers don't talk to each other and don't know if one of them is about to bite the dust.
- And finally, no philosopher shall pass away from hunger.

### Allowed Functions
Only the following functions are allowed : 
memset, printf, malloc, free, write, 
usleep, gettimeofday, pthread_create,pthread_detach, 
pthread_join, pthread_mutex_init, pthread_mutex_destroy, 
pthread_mutex_lock, pthread_mutex_unlock

### Logs
Any change in a philosopher's state must be recorded in the following format:  
[timestamp_in_ms] X has taken a fork  
[timestamp_in_ms] X is eating  
[timestamp_in_ms] X is sleeping  
[timestamp_in_ms] X is thinking  
[timestamp_in_ms] X died  
Each message must be displayed separately and not mixed with other messages.
The message announcing the death of a philosopher must be displayed within 10 milliseconds of the philosopher's death.
And, once again, philosophers must not die!

This will allow us to track exactly what happens in our philos. Here's an example of a standard output:
<img src="https://user-images.githubusercontent.com/52322219/218322685-d32c2865-2373-4ae4-b072-5e99740fd103.png" width="560px" height="470px">

### Functions we can use (otherwise it's too easy)
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock

## Solving the Dilemma with Threads and Mutexes.

#### Threads and Philosophers
First we want to create our "philosophers", and to do that we have to use threads. In computer science, a thread is a separate flow of execution within a process. Each thread has its own stack, program counter, and set of registers, but it shares the same address space and global variables with other threads in the same process. Threads are useful for implementing concurrent or parallel execution of tasks, where multiple tasks can run simultaneously and independently.

In the context of the dining philosophers problem, each philosopher can be represented by a separate thread. Each thread can execute its own code that represents the behavior of the corresponding philosopher. For example, the code for a philosopher thread include the following actions:

**Eating**: The philosopher tries to acquire the mutexes for the left fork, then the right fork. The philosopher eats some spaghetti if they have successfully acquired both forks (for the specified length <time_to_eat>). The philosopher then releases the mutexes for the two forks.  
**Sleeping**: the philosopher takes a nap to digest the spaghetti (for the specified length <time_to_sleep>).  
**Thinking**: If the philosopher cannot pick up the left fork, he think and reflects on the meaning of life until he can.  

The usefulness of using threads to represent the philosophers lies in the ability to execute the code for each philosopher concurrently and independently. With multiple threads, each philosopher can run their own code and make progress without waiting for the other philosophers. This allows for a more efficient use of resources, as the CPU can switch between threads to execute different parts of the code, making the best use of the available processing power.

**Creating the threads representing each philosopher**:
```pseudocode
FUNCTION init_threads():
  SET i to -1
  SET all_ate to false
  GET start_time
  WHILE i is less than the number of philosophers:
    i = i + 1
    IF unable to create a new thread for philosopher number i 
      CALL release_threads with argument i #This function will take the parameters i and join all threads that have been created until i == 0.
      FREE philosopher array
      FREE forks array
      RETURN false
  END WHILE
  RETURN true
END FUNCTION
```
To learn to use the posix thread library, you can find amazing resources on the web. 
https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html 

#### Forks and Mutex

Now the first hurdle: how to represent the forks ? How to give to each philosophers a left fork and a right fork ? This is very crucial step in our program, as the forks represent the symbolic resources that must be protected. Well to protect them we can use mutexes. 

A mutex (short for "mutual exclusion") is a synchronization tool used to ensure that only one process at a time can access a shared resource, such as a data structure or a critical section of code. Mutexes are used to prevent race conditions, which occur when multiple processes attempt to access the same resource simultaneously, leading to unpredictable and inconsistent results.

Mutexes are useful for representing a fork in the dining philosophers problem because they provide a way to enforce the constraint that a philosopher can only pick up two forks if and only if neither fork is being used by another philosopher. By using a mutex to represent each fork, the philosophers can attempt to acquire the mutexes for the two forks they need. If both mutexes are available, the philosopher can pick up the forks and eat. If either mutex is already held by another philosopher, the philosopher will wait until the mutex is released before attempting to acquire it. In this way, the mutexes ensure that the philosophers never deadlock (get stuck waiting for each other) and that each philosopher only eats if they have the required forks.

In summary, mutexes are useful for representing a fork in the dining philosophers problem because they provide a way to enforce the constraint that a philosopher can only pick up two forks if and only if neither fork is being used by another philosopher.

**Creating the forks with Mutexes**: 
```pseudocode
FUNCTION init_mutex():
  SET i to 0
  ALLOCATE memory for forks array with size `sizeof(pthread_mutex_t)` times `run_data.philo_nb`
  SET forks array to `run_data.forks`
  WHILE i is less than `run_data.philo_nb`:
    IF unable to initialize mutex at index i in forks array
      RETURN false
    END IF
    i = i + 1
  END WHILE
  RETURN true
END FUNCTION
```
To learn to use the GNU mutex library, you can find amazing resources on the web.  
https://docs.oracle.com/cd/E19455-01/806-5257/sync-12/index.html

#### Managing the time.

gettimeofday() is a function provided by the POSIX standard library, which can be used to retrieve the current time in seconds and microseconds. In this project, we use it to keep track of the time elapsed between different events, or to log the time when certain actions were performed.

The gettimeofday() function takes two parameters, tv and tz. tv is a struct of type timeval which will be filled with the current time, and tz is a struct of type timezone which you can use to retrieve the time zone information, although it is generally set to NULL because it is deprecated and we don't need it anyway.

Getting the hang of the function is a little bit weird in the beginning, here's an example to get you started:
```
FUNCTION get_time(time):
  DECLARE struct timeval tv
  IF gettimeofday with arguments &tv, NULL returns -1
    CALL generic_err with argument "gettimeofday"
    RETURN
  END IF
  SET time's millisecs to (tv.tv_sec * MILLISECONDS_IN_A_SECOND) + (tv.tv_usec / MICROSECONDS_IN_A_MILLISECOND)
  SET time's microsecs to (tv.tv_sec * MICROSECONDS_IN_A_SECOND) + (tv.tv_usec)
END FUNCTION
```

#### Building an accurate sleep function

usleep() is a system call that suspends the execution of the calling thread for a specified number of microseconds. However, the actual amount of time that the thread will be suspended can vary depending on various factors, such as the operating system scheduler, system load, and other processes running on the system. This can result in the thread being resumed much later than the specified number of microseconds, leading to inaccurate timing.

To achieve more precise timing, it is common to use a combination of gettimeofday and a busy-wait loop. gettimeofday returns the current time in seconds and microseconds, which can be used to determine the elapsed time between two points in time. The busy-wait loop continuously checks the current time using gettimeofday and compares it to the desired end time. When the desired time has passed, the loop can be exited and the next task can be performed. This approach ensures that the correct amount of time has elapsed, even if the usleep function is imprecise.

It's important to note that busy-waiting can consume a lot of CPU resources and is not an ideal solution for timing-sensitive applications. In order to lessen the usage of system resources we have to make the wait interval as long as possible, while still ensuring that the condition is met in a reasonable amount of time. The longer the wait interval, the less frequently the system will be polled.

Here's an example of a modified sleep function:
```
FUNCTION mod_sleep(time_to_sleep: LONG):
    DECLARE current_time: t_time
    DECLARE start: t_time

    CALL now(start)
    WHILE true:
        CALL usleep(SECRET_NUMBER)
        CALL now(current_time)
        IF current_time.millisecs - start.millisecs >= time_to_sleep
            BREAK
    END WHILE
END FUNCTION
```

### General Tips

**Managing death, print, time and meals count**  
Depending on your implementation, you might want to use different mutexes to perform actions that are unrelated to each others. Here are some ideas: A mutex for all the death mechanism of your program. A mutex for the meals counters. A mutex for the global meal values (if all philo ate for example). A mutex for the time values. And/or a mutex to print the logs. This will allow for greater parallelization than using one mutex for everything.

**Lessening CPU usage**  
Depending on your implementation, you might want to use one busy-waiting loop to monitor the state of all your philos each milliseconds. The 200 410 200 200 test requires you to be careful of CPU usage.

**Special case of odd numbers**  
Depending on your implementation, you might want to use some mechanism to ensure that philos don't steal the forks of philos that have not yet eaten. The 3 550 200 80 test can highlight this specific behavior.
The solution that I found:
```
static void	think(t_philo *philo)
{
	log_msg(philo, "is thinking");
	if (r()->philo_nb % 2 != 0)
		usleep((r()->time_to_eat) * MICROSECONDS_IN_A_MILLISECOND);
}
```

**Helgrind error: lock order "0x4AAB040 before 0x4AAB068" violated**  
Here's an amazing graph from librity that will let you figure out what to fix:  
<img src="https://github.com/librity/ft_philosophers/blob/master/.github/potential_deadlock.png" width="600px" height="300px">
<img src="https://github.com/librity/ft_philosophers/blob/master/.github/impossible_deadlock.png" width="600px" height="300px">

### Testers
You might consider using my [Thales Tester](https://github.com/Rz-Rz/thales_tester) in order to test your program. Please be aware that it will not work if you have customized your output with colors. 
