/* forkchild.c — Process creation with fork() and exec() */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// if the child process > 0 mean: the child process was created successfully
// if the child process == 0 mean: we are in the child process
// if the child process < 0 mean: fork failed

int main() {
    // signed integer that can be positive or negative
    pid_t pid;

    printf("Parent process (PID: %d) — creating child...\n", getpid());

    // create a child process using fork() which return 0
    pid = fork();

    if (pid < 0) {
        /* Fork failed */
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        /* ---- CHILD PROCESS ---- */
        printf("Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());

        /*
         * Sleep for 30 seconds so you have time to observe
         * the parent-child process tree in another terminal
         * using ps, top, or htop (see step 5 below).
         */
        printf("Child: sleeping 30s — observe the process tree now!\n");
        sleep(30);

        printf("Child: now executing 'ls -la'...\n");

        /* Replace this process with "ls -la" */
        execlp("ls", "ls", "-la", NULL);

        /* If execlp returns, it means it failed */
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else {
        /* ---- PARENT PROCESS ---- */
        int status;
        printf("Parent: waiting for child (PID: %d) to finish...\n", pid);

        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Parent: child exited with status %d\n", WEXITSTATUS(status));
        }
        printf("Parent: done.\n");
    }

    return 0;
}
