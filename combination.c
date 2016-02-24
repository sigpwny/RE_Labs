#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <sys/stat.h>
#include <fcntl.h>

/*
    Explanation: The user must put in the correct combination to win.
    There is an array of function pointers. Each function has a different
    challenge. The right combination will allow you to continue to more
    challenges.

*/



void func0(unsigned long p);
void func1(unsigned long p);
void func2(unsigned long p);
void func3(unsigned long p);
void func4(unsigned long p);
void fail();
void win();

unsigned long func1_helper(unsigned long p);
double func3_helper(unsigned long p);
unsigned long func3_helper_helper(unsigned long p);

// a pointer to a func that has an int param and no return value
typedef void (*funcPtr_t)(unsigned long);

int gpass = 0;

int main(int argc, char *argv[])
{
    // Explain how to start using the program
    if(argc <= 1)
    {
        printf("usage: %s <arg1> <arg2> ...\n",argv[0]);
        exit(-1);
    }

    // setup
    int i;
    funcPtr_t arr[5] = {&func0, &func1, &func2, &func3, &func4};
    int max = atoi(argv[1]);

    // the fun begins!
    for(i=0; i < max; i++)
    {
        if(i >= argc - 1) {
            fail();
        }
        unsigned long val = atoi(argv[i+1]);
        arr[i](val);
    }

    if(isDebuggerPresent() == 0 && gpass == 1)
        win();

    fail();
}

void func0(unsigned long p) {
    if(p > 8)
    {
        fail();
    }
    printf("Good first step.\n");
}

void func1(unsigned long p) {
    unsigned long val = func1_helper(p);
    if(val != 2584)
    {
        fail();
    }
    printf("Another challenge complete.\n");
}

unsigned long func1_helper(unsigned long p) {
    if(p == 0)
        return 0;
    if(p == 1)
        return 1;
    else
        return func1_helper(p-2) + func1_helper(p-1);
}

void func2(unsigned long p) {
    unsigned long val = (2*p*(2*p-1))/2; // will be an int

    if(val == 1983208710)
    {
       printf("You're almost there.\n");
        return;
    }
    else
    {
        fail();
    }
}

void func3(unsigned long p) {
    double val = exp(p);

    if(val != 26489122129.843472) {
        fail();
    }

    gpass = 1;
    printf("You haven't lost yet!\n");
}

void func4(unsigned long p) {
    fail();
}

void fail() {
    printf("You lose!\n");
    exit(-1);

}


void win() {
    printf("You win!\n");
    exit(0);
}


int isDebuggerPresent() {
    char buf[1024];
    int debugger_present = 0;

    int status_fd = open("/proc/self/status",O_RDONLY);
    if(status_fd == -1)
        return 0;

    ssize_t num_read = read(status_fd, buf, sizeof(buf));

    if(num_read > 0)
    {
        static const char tracerPid[] = "TracerPid:";
        char *tracer_pid;

        buf[num_read] = 0;
        tracer_pid = strstr(buf,tracerPid);
        if(tracer_pid)
            debugger_present = !!atoi(tracer_pid + sizeof(tracerPid) - 1);


    }

    return debugger_present;
}
