#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define ARGS 3
void    *ft_memset(char *c,int x,int y);

void	test_ft_memset(int id)
{
	int diff = 0;
    char input[100];
    char comment[100];
    char memset_test[100];
    char memset_control[100];
    int i1 = 0;
    int i2 = 0;
    char *ctrl = NULL;
    char *ret = NULL;
    switch (id)
    {
    case 0:
        strcpy(input,"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        strcpy(comment,"Check Basic Functionality");        
        strcpy(memset_test,input);
        strcpy(memset_control,input);
        i1 = 89;
        i2 = 30;

        ctrl = (char *)memset(memset_control,i1,i2);//standard check, nothing special
        ret = (char *)ft_memset(memset_test,i1,i2);
        if(strcmp(ctrl,ret) != 0){
            //number of args, testid, ... args ... , expected return, actual return, comment
        	printf("1,%d\n%s\n%d\n%d\n%s\n%s\n%s\n",ARGS,input,i1,i2,ctrl,ret,comment);
	    	diff = 1;}
        if(diff==0)
		    printf("0");
    break;
    case 1:
        strcpy(input,"XX\nXX\bXX\vX");
        strcpy(comment,"Check Special Characters");        
        strcpy(memset_test,input);
        strcpy(memset_control,input);
        i1 = 89;
        i2 = 10;

        ctrl = (char *)memset(memset_control,i1,i2);
        ret = (char *)ft_memset(memset_test,i1,i2);
        if(strcmp(ctrl,ret) != 0){
            //number of args, testid, ... args ... , expected return, actual return, comment
        	printf("%d\n%s\n%d\n%d\n%s\n%s\n%s\n",ARGS,input,i1,i2,ctrl,ret,comment);
	    	diff = 1;}
        if(diff==0)
		    printf("OK");
    break;
    case 2:
        strcpy(input,"XXXXX\0XXXX");
        strcpy(comment,"Check \\0 Character in input");        
        strcpy(memset_test,input);
        strcpy(memset_control,input);
        i1 = 89;
        i2 = 10;

        ctrl = (char *)memset(memset_control,i1,i2);
        ret = (char *)ft_memset(memset_test,i1,i2);
        if(strcmp(ctrl,ret) != 0){
            //number of args, testid, ... args ... , expected return, actual return, comment
        	printf("%d\n%s\n%d\n%d\n%s\n%s\n%s\n",ARGS,input,i1,i2,ctrl,ret,comment);
	    	diff = 1;}
        if(diff==0)
		    printf("OK");
    break;
    default:
        printf("SWITCH ERR\n");
    break;
    }
    return;
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
			test_ft_memset(atoi(av[1]));
    }
    return (0);
}