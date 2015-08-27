#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void sighup_handler(){
	int pid = getpid();

	signal(SIGHUP, SIG_IGN);
	printf("\n\n From signal handler with PID = %d I have received a SIGHUP signal \n", pid);
}

void sigint_handler(){
	int pid = getpid();
	
	signal(SIGINT, SIG_IGN);
	printf("From signal handler with PID = %d I have received a SIGINT signal \n", pid);
}

void sigquit_handler(){
	int pid = getpid();

	printf("From signal handler with PID = %d I have received the SIGQUIT signal \n\n\n", pid);
}

main(){

	int pid0;
	int pid = getpid();

	/* Setup signal handler */
	printf("\nPARENT: Setting up SIGHUP handler with pid = %d \n\n", pid);
	signal(SIGHUP, sighup_handler);

	printf("\nPARENT: Setting up SIGINT handler with pid = %d \n\n", pid);
	signal(SIGINT, sigint_handler);

	printf("\nPARENT: Setting up SIGQUIT handler with pid = %d \n\n", pid);
	signal(SIGQUIT, sigquit_handler);

	if ((pid0 = fork())<0){
		perror("fork");
		exit(1);
	}

	if (pid0 == 0){
		pid = getpid();
		printf("\n CHILD process invoked with PID = %d \n\n", pid);
		
		printf("\nCHILD: Setting up SIGHUP handler with pid = %d \n\n", pid);
		signal(SIGHUP, sighup_handler);

		printf("\nCHILD: Setting up SIGINT handler with pid = %d \n\n", pid);
		signal(SIGINT, sigint_handler);

		printf("\nCHILD: Setting up SIGQUIT handler with pid = %d \n\n", pid);
                signal(SIGQUIT, sigquit_handler);

		for(;;);
	}
	else{
		pid = getpid();

		printf("\nPARENT: Sending SIGHUP Parent pid = %d \n\n", pid);
		kill(pid, SIGHUP);
		sleep(3);

		printf("\nPARENT: Sending SIGINT Parent pid = %d \n\n", pid);
                kill(pid, SIGINT);
                sleep(3);

		printf("\nPARENT: Sending SIGQUIT Parent pid = %d \n\n", pid);
                kill(pid, SIGQUIT);
                sleep(3);
	}
}
