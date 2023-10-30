#include <stdio.h>
#include <stdlib.h>

typedef struct task{
	char name[15];
	float burst_time;
	float vruntime;
	int nice_value;
}task;
