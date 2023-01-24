#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <stdio.h>
#include <errno.h>
#include <semaphore.h>


// main.c
// just test a semaphore using sem open.
int main(int argc, char *argv[])
{
	sem_t *sem = sem_open("test", O_CREAT, 0000, 1);
	if (sem_wait(sem) == -1) {
		perror("sem_wait");
		return 1;
	}
	if (sem_post(sem) == -1) {
		perror("sem_post");
		return 1;
	}
	if (sem_close(sem) == -1) {
		perror("sem_close");
		return 1;
	}
	if (sem_unlink("test") == -1) {
		perror("sem_unlink");
		return 1;
	}
	return 0;
}
