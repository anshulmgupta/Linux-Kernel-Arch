#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

//Global declaration
int process_init_data = 30;
int process_noinit_data;

char Globalbuffer[100];

void process_prints(void){
    /* 
    * Function to print virtual address of program
    */
    //Local variable declaration
    int process_local_data = 1;
    char Localbuffer[100];
    
    //Data virtual address of program segments
    printf("\nPid of the process is = %d",getpid());
    printf("\n\n");
    printf("\nAddress which fall into:");
    printf("\n\n");
    printf("\n 1) Data Segment = %p", &process_init_data);
    printf("\n 2) BSS Segment = %p", &process_noinit_data);
    printf("\n 3) Code Segment = %p", &process_prints);
    printf("\n 4) Stack Segment = %p", &process_local_data);
    printf("\n 5) Global Buffer = %p", &Globalbuffer);
    printf("\n 6) Local Buffer = %p", &Localbuffer);
    printf("\n\n");

    //Hold the process
    while(1);

}

int main(){
    /*
    * Main method  
    */
    process_prints();
    return 0;
}
