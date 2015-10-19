#include <stdio.h>
#include <string.h>


static int global_int = 10;
static char global_string[50];

typedef struct structure_s{
	char string[10];
	int integer;
} structure_t;


char* function(int var){
	char yes[] = "Yes\n";
	char no[] = "No\n";
	char maybe[] = "Maybe\n";
	
	switch(var){
	case 1:
		return strcpy(global_string, yes);
	case 2: 
		return strcpy(global_string, no);
	case 3:
		return strcpy(global_string, maybe);
	default:
		return NULL;
	}
}

int main(){
	int i;
	int switchvar;
	int stackint = 1;
	char stackstring[] = "Pick a number between 1-3 inclusive:";
	structure_t structure;
	
	printf("%s\n", stackstring);
	for (i = 0; i < 10; i++){
		stackint = 2*stackint; 
	}
	scanf(" %d", &switchvar);
	if (switchvar > 3){
		return 0;
	}
	if (switchvar < 1){
		return 0;
	}
	function(switchvar);
	strcpy(structure.string, global_string);
	structure.integer = stackint;
	printf("structure.string: %sstructure.integer: %d\n", structure.string, structure.integer);
	return 0;
}
