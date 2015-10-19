#include <stdio.h>
#include <string.h>

typedef struct student_s{
	char name[30];
	int credit_hours;
	int grade_points;
	double gpa;
	char netid[10];
	char password[30];
	
} student_t;

typedef struct professor_s{
	char name[30];
	char netid[10];
	int passwordhash;
} professor_t;

static int professor_authd = 0;
static int student_authd = 0;
static professor_t professor= {"test","test1", 1};
static student_t student;

// create a simple hash function for dynamic analysis portion
char passwordhash(char* password){
	return 1;
}

int loginProfessor(){
	char netid[10];
	char password[30];
	int hash;
	printf("Please enter your netid: ");
	fgets(netid, sizeof(netid), stdin);
	printf("\nPlease enter your password ");
	fgets(password, sizeof(password), stdin);
	hash = passwordhash(password);
	if (!strcmp(professor.netid, netid) && !strcmp(professor.passwordhash, hash)){
		professor_authd = 1;
		student_authd = 0;
	}
	else{
		printf("Incorrect username and/or password\n");
	}
	return 0;
}

int loginStudent(){
	char netid[10];
	char password[30];
	int hash;
	printf("Please enter your netid: ");
	fgets(netid, sizeof(netid), stdin);
	printf("\nPlease enter your password ");
	fgets(password, sizeof(password), stdin);
	if (!strcmp(student.netid, netid) && !strcmp(student.password, password)){
		professor_authd = 0;
		student_authd = 1;
	}
	else{
		printf("Incorrect username and/or password\n");
	}
	return 0;
}

void logout(){
	professor_authd = 0;
	student_authd = 0;
}

int enterGrades(){
	int credit_hours;
	int grade_points;
	if(professor_authd == 0){
		printf("You must be logged in as a professor to change grades!\n");
		return 0;
	}
	printf("Please enter the credit hours for the course (0-4): ");
	scanf("%d", &credit_hours);
	printf("Please enter the grade points for the student (0-4): ");
	scanf("%d", &grade_points);
	student.credit_hours += credit_hours;
	student.grade_points += grade_points;
	return 0;
}

int viewGPA(){
	double GPA;
	if (student_authd == 0){
		printf("You must be logged in as a student to view your GPA!\n");	
		return 0;
	}
	GPA = student.grade_points / student.credit_hours;
	student.gpa = GPA;
	printf("Hello %s, you GPA is %lf\n", student.name, student.gpa);	
}

int main(){

	strcpy(student.name,"Ben Bitdiddle");
	student.credit_hours = 100;
	student.grade_points = 250;
	student.gpa = 2.5;
	strcpy(student.netid, "bdiddy1");
	strcpy(student.password, "password123456");
	printf("Welcome to Compass 3G, the next generation course management system\n");
	int command = 0;
	while(1){
		while ((command < 1) && (command > 5)){
			printf("What would you like to do today (1-5)?\n"
					"1: Login as Professor\n"
					"2: Login as Student\n"
					"3: Logout\n"
					"4: Enter in Grades\n"
					"5: View GPA\n"
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
			break;
		case 4:
			enterGrades();
			break;
		case 5:
			viewGPA();
			break;
		}
	}

	
}
