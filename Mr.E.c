#include <stdio.h>

static int global_int = 10;

typedef struct student_s{
	char[30] name;
	int age;
	double gpa;
	char[10] netid;
	char[30] password;
	
} student_t;

typedef struct professor_s{
	char[30] name;
	char[30] password;
} professor_t;

static professor_t = {"test","test"};

//function to update gpa
int gpa_calc(int a, int b){
	int c;
	c = a + b;
	return c;
}

// function to add new user


int loginProfessor(){
	

}

void logout(){
	exit(0);
}

int main(){
	printf("Welcome to Compass 3G, the next generation course management system\n");
	int command = 0;
	while(1){
		while ((command < 1) && (command > 5){
			printf("What would you like to do today (1-5)?\n"
					"1: Login as Professor\n"
					"2: Login as Student\n"
					"3: Logout\n"
					);
			scanf("%d", &command);
		}
		switch(command){
		case 1:
			loginProfessor();
			break;
		case 2: 
			loginStudent();
			break;
		case 3:
			logout();
		}
	}



	int num = 100;
	int i;
	char grades[] = ['A','C','C','B','D'];	// grade, GPA
	student_t student;
	...
	int sum = calc(global_int, num);
	student.name = "Ben Bitdiddle";
	student.age = 19;
	student.gpa = 2.5;
	student.netid = "bdiddy1";
	
	for(i = 0; i < 5; i++){
		
	
	}
	
	
}
