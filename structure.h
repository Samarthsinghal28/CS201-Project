#include <stdio.h>
#include <stdlib.h>
#define SIZE_NAME 10

typedef struct task{
	char name[SIZE_NAME];
	int burst_time;
	int vruntime;
	int nice_value;
}task;

task * input(){
	int n;
	printf("Enter the number of tasks: ");
	scanf(" %d",&n);
	task **arr= (task**)malloc(sizeof(task*));

	for(int i=0;i<n;++i){
		printf("Enter the name of the task: ");
		fgets(arr[i]->name, SIZE_NAME, stdin);
		printf("Enter the Burst time of %s: ",arr[i]->name);
		scanf(" %d", arr[i]->burst_time);
		printf("Enter the Virtual Runtime of %s", arr[i]->name);
		scanf(" %d", arr[i]->vruntime);
		printf("Enter the nice value of %s", arr[i]->name);
		scanf(" %d",arr[i]->nice_value);
	}	
}