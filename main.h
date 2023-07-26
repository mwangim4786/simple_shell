#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *get_location(char *argv_zero);
void exec(char **argv);
void perform_exit(char **argv);
void perform_env(char **argv, char **envp);


#endif
