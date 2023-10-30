#include <stdio.h>
#include <menu.h>
#include <structure.h>
#include <redblack.c>
#define SIZE_NAME 10

int No_Of_Tasks=0;
rb_tree* TaskTree;
task* TaskList;

//Reads the file and returns array of tasks
task* readFile(){       //also updates the value of global variable No_of_Tasks
    int n;
    FILE* fptr;
    fptr=fopen("input.txt",'r');
    fscanf(fptr,"%d",&n);
    task* process=(task*)malloc(n*sizeof(task));
    for(int i=0;i<n;i++){
        char name[15];
        float time;
        int priority;
        fscanf(fptr,"%s %f %d",&(process[i].name),&process[i].burst_time,&process[i].nice_value);
    }
    return process;
}




//takes input from the user for a new process and enter the process into the existing tree
void addNewProcess(){
    int n;
	printf("Enter the number of tasks to be entered: ");
	scanf(" %d",&n);
    No_Of_Tasks +=n;
	TaskList= (task**)realloc(TaskList, No_Of_Tasks*sizeof(task*));

	for(int i=No_Of_Tasks-n-1;i<No_Of_Tasks;++i){
		printf("Enter the name of the task: ");
		fgets(TaskList[i].name, SIZE_NAME, stdin);
		printf("Enter the Burst time of %s: ",TaskList[i].name);
		scanf(" %d", TaskList[i].burst_time);
		printf("Enter the nice value of %s", TaskList[i].name);
		scanf(" %d",TaskList[i].nice_value);
	}

    for(int i =No_Of_Tasks-n-1;i<No_Of_Tasks;++i){
        int preference = TaskList[i].nice_value + TaskList[i].burst_time;//change this logic *********************************
        create_node(preference, TaskList+i);
    }   
	
}



//takes task name of input from the user and deletes the process from the Tasktree. Uses TaskList and the defined expression for initial preference to find the task
void deleteProcess(){
    char delName[15];
    int same;
    printf("Enter the name of the process to be deleted: ");
    fgets(delName, SIZE_NAME, stdin);
    for(int i=0;i<No_Of_Tasks;++i){
        same = strcmp(TaskList[i].name, delName);
        if(same == 0) break;
    }
    if(same == 0){
        search(TaskTree->root, delName);
    }else{
        printf("The entered string is not a valid process.\n");
    }
}

//takes input from the user that for how many nanoseconds processes should run and then prints the burstTime left for each process. Each nanosecond is divided into Quantas equal to number of processes.
void runProcesses(){
    int x;
    printf("Enter for how many nanoseconds processes should run : ");
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        
    }
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
    TaskTree=create_tree();
    TaskList = readFile();
    
    for(int i=0;i<No_Of_Tasks;i++){
        int initial_preference = TaskList[i].nice_value + TaskList[i].burst_time; //Defining an expression
        rb_node* node=create_node(initial_preference,TaskList+i);
        insert(TaskTree,node);
    }

    int n;
    do{
        afterReadingFile();
        scanf("%d",&n);
        run(n);
    }while(n!=5);

}