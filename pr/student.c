#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char* name;
	int middleTest_score;
	int finalTest_score;
}node;

char* student_nametable; // save student name table
node* nodetable; // save node table
node* root = NULL; // root node

int compare(const void *cp1, const void *cp2) {
return strcmp(((node *)cp1)->name, ((node*)cp2)->name);
}

void print_node(const void *, VISIT, int);

int main() {
	int student_count;
	printf("How many student? ");
	scanf("%d" ,&student_count);
	
	student_nametable = (char *) malloc(sizeof(char) * student_count);
	nodetable = (node *) malloc(sizeof(node) * student_count);
	
	char *studentptr = student_nametable;
	node *nodeptr = nodetable;
	node **ret;
	int i = 0;
	
	for(int i=0; i<student_count; i++){
		printf("Please enter student information! : \n");
		scanf("%s %d %d", studentptr, &nodeptr->middleTest_score, &nodeptr->finalTest_score);
		
		nodeptr->name = studentptr;
		
		// Add Tree
		ret = (node**) tsearch ((void *) nodeptr, (void **) &root, compare);
		printf("\"%s\"", (*ret)->name);
		
		if(*ret == nodeptr)
			printf("has been added to the tree.\n");
		else
			printf("already exists in the tree.\n");
			
		studentptr += strlen(studentptr) + 1;
		nodeptr++;
	}
	
	twalk((void*) root, print_node);
	
	free(student_nametable);
	free(nodetable);
}

void print_node(const void *nodeptr, VISIT order, int level) {
	if( order == preorder || order == leaf ) {
		printf("student_name = %-10s, middleTest_score = %d, finalTest_score = %d\n",(*(node **)nodeptr)->name,
		(*(node**)nodeptr)->middleTest_score,
		(*(node**)nodeptr)->finalTest_score);
	}
}
