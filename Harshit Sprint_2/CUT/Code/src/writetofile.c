#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#define Max 100
#define MAX 256
void writetofile()
{
	FILE *fw;
	char file[100] = "/home/harsh/sprint_2/data/";
	char sl[256],tl[256];
	printf("please enter your source language: ");
	fgets(sl,255,stdin);	
        sl[strlen(sl)-1]='\0';	
	printf("please enter your target language: ");
	fgets(tl,255,stdin);
	tl[strlen(tl)-1]='\0';
	strcat(file,sl);
	strcat(file,"_");
	strcat(file,tl);
	strcat(file,".txt");
	fw = fopen(file, "a"); //opening file in append mode
	if (fw == NULL)
        	return;
	int ct=1;
	int flag=1;
	char w[Max];
   	while(flag)
   	{	
		switch(ct)
		{
		case 1:		printf("Enter your word\n");//make
				fgets(w,Max,stdin);
				w[strlen(w)-1]='\0';	
					fputs(w, fw);
					fputs(":", fw);//make:
					break;
		case 2:		printf("Enter your meaning\n");
				fgets(w,Max,stdin);
				w[strlen(w)-1]='\0';	
					fputs(w, fw); 
					break;
		case 3: fputs("\n",fw);
			break;
   	        }
		ct++;
		if(ct==4)
			{
			int i;
			printf(" press 0 for continue or  1 for exit: ");
			fgets(w,Max,stdin);
				w[strlen(w)-1]='\0';
				if(strcmp(w,"1")==0)
			{
					flag=0;
					break;
			}
			else
			{
			ct=1;
				}
			}

		}
		fclose(fw);
		return;
}
