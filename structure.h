#include <stdio.h>
#include <stdlib.h>

typedef struct task{
	char name[15];
	int burst_time;
	int vruntime;
	int nice_value;
}task;
