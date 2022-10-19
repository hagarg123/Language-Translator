/*
*Take the data from server recv() from client..
*word -> source language -> Target language..
*open the sl_tl.txt file in read mode..
*traverse the whole file word meaning ->return the output to server ->send() to client...
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
char*translate(char*word,char *sl,char *tl)
{
	char str[1024];
    	char file[100]="/home/harsh/sprint_2/data/";
    	strcat(file,sl);
    	strcat(file,"_");
	tl[strlen(tl)-1]='\0';
    	strcat(file,tl);
    	strcat(file,".txt");
	printf("file opening:%s",file);
	FILE *fw=fopen(file, "r");
	if(fw==NULL)
	{
		strcpy(word,"language not found");
		return word;
	}
	while(1)
	{
	char*fword,*meaning;
	
	if(fgets(str,1024,fw)==NULL)
	{
		break;
	}
	else
	{	
	str[strlen(str)-1]='\0';
	fword=strtok(str,":");
	meaning=strtok(NULL,":");
	}
	if(strcmp(word,fword)==0)
	{
        strcpy(word,meaning);
        return word;
	}

	}
	strcpy(word,"Not found:");
	return word;
}

