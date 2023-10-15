#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "math.h"

int main(){
	void *handle;
	double (*add)(double, double), 
	(*subtract)(double, double),
	(*multiply)(double, double),
	(*divide)(double, double);
	char *error;
	
	handle = dlopen("./lib/libshare.so", RTLD_LAZY);
	
	if(!handle){
		fputs(dlerror(), stderr);
		exit(1);
	}
	
	char* str = (char*)malloc(10*sizeof(char));
	double a,b;
	
	printf("what do you want? ");
	scanf (" %s",str);
	
	printf("press Two numbers = ");
	scanf("%lf %lf",&a,&b);
	
	if(strcmp(str, "add")== 0){
		add = dlsym(handle, "add");
		if((error = dlerror()) != NULL){
			fprintf(stderr, "%s",error);
			exit(1);
			}
			printf("add = %lf\n", (*add)(a,b));
	}
	
	else if(strcmp(str, "subtract")== 0){
		subtract = dlsym(handle, "subtract");
		if((error = dlerror()) != NULL){
			fprintf(stderr, "%s",error);
			exit(1);
			}
			printf("subtract = %lf\n", (*subtract)(a,b));
	}
	
	else if(strcmp(str, "multiply")== 0){
		multiply = dlsym(handle, "multiply");
		if((error = dlerror()) != NULL){
			fprintf(stderr, "%s",error);
			exit(1);
			}
			printf("multiply = %lf\n", (*multiply)(a,b));
	}

	else if(strcmp(str, "divide")== 0){
		divide = dlsym(handle, "divide");
		if((error = dlerror()) != NULL){
			fprintf(stderr, "%s",error);
			exit(1);
			}
			printf("divide = %lf\n", (*divide)(a,b));
	
	}
	dlclose(handle);
	free(str);
	}
