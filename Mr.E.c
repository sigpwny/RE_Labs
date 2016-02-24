#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

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
	char encryptedpassword[30];
} professor_t;

static int professor_authd = 0;
static int student_authd = 0;
static professor_t* professor;
static student_t student;

// base 64 decoder
#define WHITESPACE 64
#define EQUALS     65
#define INVALID    66

static const unsigned char d[] = {
    66,66,66,66,66,66,66,66,66,66,64,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,62,66,66,66,63,52,53,
    54,55,56,57,58,59,60,61,66,66,66,65,66,66,66, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,66,66,66,66,66,66,26,27,28,
    29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66
};

int base64decode (char *in, size_t inLen, unsigned char *out, size_t *outLen) { 
    char *end = in + inLen;
    char iter = 0;
    size_t buf = 0, len = 0;
    
    while (in < end) {
        unsigned char c = d[*in++];
        
        switch (c) {
        case WHITESPACE: continue;   /* skip whitespace */
        case INVALID:    return 1;   /* invalid input, return error */
        case EQUALS:                 /* pad character, end of data */
            in = end;
            continue;
        default:
            buf = buf << 6 | c;
            iter++; // increment the number of iteration
            /* If the buffer is full, split it into bytes */
            if (iter == 4) {
                if ((len += 3) > *outLen) return 1; /* buffer overflow */
                *(out++) = (buf >> 16) & 255;
                *(out++) = (buf >> 8) & 255;
                *(out++) = buf & 255;
                buf = 0; iter = 0;

            }   
        }
    }
   
    if (iter == 3) {
        if ((len += 2) > *outLen) return 1; /* buffer overflow */
        *(out++) = (buf >> 10) & 255;
        *(out++) = (buf >> 2) & 255;
    }
    else if (iter == 2) {
        if (++len > *outLen) return 1; /* buffer overflow */
        *(out++) = (buf >> 4) & 255;
    }

    *outLen = len; /* modify to reflect the actual output size */
    return 0;
}

int fibonacci(int value){
	if (value <= 1)
		return value;
	return fibonacci(value - 1) + fibonacci(value - 2);
}

// Sums up N(1-16) random fibonacci numbers
int challengeresponse(){
	srand(time(NULL));
	int loopcount = random() % 16;
	int response;
	int sum = 0;
	printf("Challenge values: %d ", loopcount);
	int fibonacciseed[16] = {0}; 
	int i;
	for (i = 0; i < loopcount; i++){
		fibonacciseed[i] = random() %32;
		printf("%d ", fibonacciseed[i]);
	}
	printf("\nPlease enter your response value: ");
	scanf("%d", &response);
	for (i = 0; i < loopcount; i++){
		sum += fibonacci(fibonacciseed[i]);
	}
	if (response == sum){
		return 1;
	}
	else return 0;
}

int loginProfessor(){
	if (student_authd == 1){
		printf("Please logout of student account first.\n");
		return -1;
	}
	else if(professor_authd == 1){
		printf("You are already logged in!\n");
		return -1;
	}
	char netid[10];
	char password[30];
	char professorpassword[30];
	int length;
	int hash;
	printf("Please enter your netid: ");
	scanf("%s", netid);
	printf("Please enter your password: ");
	scanf("%s", password);
	base64decode(professor->encryptedpassword, strlen(professor->encryptedpassword), professorpassword, &length);
	professorpassword[length] = '\0';
	if (!strcmp(professor->netid, netid) && !strcmp(professorpassword, password)){
		if (challengeresponse()){
			professor_authd = 1;
			student_authd = 0;
			printf("Succcessfully logged in as a professor.\n");
		}
		else{
			printf("Failed challenge response\n");	
		}
	}
	else{
		printf("Incorrect username and/or password\n");
	}
	return 0;
}

int loginStudent(){
	if (professor_authd == 1){
		printf("Please logout of professor account first.\n");
		return -1;
	}
	else if(student_authd == 1){
		printf("You are already logged in!\n");
		return -1;
	}
	char netid[10];
	char password[30];
	int hash;
	printf("Please enter your netid: ");
	scanf("%s", netid);
	printf("Please enter your password: ");
	scanf("%s", password);
	if (!strcmp(student.netid, netid) && !strcmp(student.password, password)){
		professor_authd = 0;
		student_authd = 1;
		printf("Successfully logged in as student.\n");
	}
	else{
		printf("Incorrect username and/or password\n");
	}
	return 0;
}

void logout(){
	professor_authd = 0;
	student_authd = 0;
	printf("Logout complete.\n");
}

int enterGrades(){
	int credit_hours;
	int grade_points;
	if(professor_authd == 0){
		printf("You must be logged in as a professor to change grades!\n");
		return -1;
	}
	printf("Please enter the credit hours for the course (0-4): ");
	scanf("%d", &credit_hours);
	printf("Please enter the grade points for the student (0-4): ");
	scanf("%d", &grade_points);
	student.credit_hours += credit_hours;
	student.grade_points += credit_hours*grade_points;
	return 0;
}

int viewGPA(){
	double GPA;
	if (student_authd == 0){
		printf("You must be logged in as a student to view your GPA!\n");	
		return -1;
	}
	GPA = (double)student.grade_points / (double)student.credit_hours;
	student.gpa = GPA;
	printf("Hello %s, you GPA is %.2lf\n", student.name, student.gpa);
	return 0;	
}

int main(){
	professor = malloc(sizeof(professor_t));
	strcpy(professor->name, " John Bardeen"); 
	strcpy(professor->netid, "jbardeen");
	strcpy(professor->encryptedpassword, "ZWNlbWFzdGVycmFjZQ==");	// base 64 encoded "ecemasterace"
	strcpy(student.name,"Ben Bitdiddle");
	student.credit_hours = 100;
	student.grade_points = 150;
	student.gpa = 1.5;
	strcpy(student.netid, "bdiddy1");
	strcpy(student.password, "password123456");
	printf("Welcome to Compass 3G, the next generation course management system\n");
	char command = '0';
	while(1){
		printf("What would you like to do today (1-6)?\n"
					"1: Login as Professor\n"
					"2: Login as Student\n"
					"3: Logout\n"
					"4: Enter in Grades\n"
					"5: View GPA\n"
					"6: Quit\n"
					);
		while ((command < '1') || (command > '6')){
			scanf("%c", &command);
			// eat the newline and any chars after the first input;
			//scanf("%*c");
		}
		switch(command){
		case '1':
			loginProfessor();
			break;
		case '2': 
			loginStudent();
			break;
		case '3':
			logout();
			break;
		case '4':
			enterGrades();
			break;
		case '5':
			viewGPA();
			break;
		case '6':
			exit(1);
		}
		command = '0'; // resets command so it won't infinite loop
	}

	
}
