#include <stdio.h>
#include <menu.h>
#include <structure.h>
#include <redblack.c>
int No_Of_Tasks=0;
//Reads the file and returns array of tasks
task* readFile(){       //also updates the value of global variable No_of_Tasks

}


//takes input from the user for a new process and enter the process into the existing tree
void addNewProcess(){

}

//takes task name of input from the user and deletes the process from the Tasktree. Uses TaskList and the defined expression for initial preference to find the task
void deleteProcess(){

}

//takes input from the user that for how many nanoseconds processes should run and then prints the burstTime left for each process. Each nanosecond is divided into Quantas equal to number of processes.
void runProcesses(){

}

//takes task name of input from the user and deletes the process from the Tasktree. And insert it again with different Nice_value
void changePriority(){

}


void run(int n){
    switch(n){
        case 1: addNewProcess();
                break;
        case 2: deleteProcess();
                break;
        case 3: runProcesses();
                break;
        case 4: changePriorty();
                break;
    }

}

void main(){
    char* file_name=start();
    
    task** TaskList=readFile();
    rb_tree* TaskTree=create_tree();

    for(int i=0;i<No_Of_Tasks;i++){
        int initial_preference = TaskList[i]->nice_value + TaskList[i]->burst_time; //Defining an expression
        rb_node* node=create_node(initial_preference);
        insert(TaskTree,node);
    }

    int n;

    do{
        afterReadingFile();
        scanf("%d",&n);
        run(n);
    }while(n!=5);

}