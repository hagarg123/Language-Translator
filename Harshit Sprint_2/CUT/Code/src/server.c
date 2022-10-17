#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include "../Header/function.h"
#define Max 100
#define MAX 256
int main()
{	char ct[100];
	printf("1) Login\n2) Run\n");
	fgets(ct,100,stdin);
	ct[strlen(ct)-1]='\0';
	if(strcmp(ct,"1")==0)
{
	char LoginId[100];
        char Password[100];        
        printf("Welcome to the Login_System\n");
        printf("Please Enter your LoginID\n");
        fgets(LoginId,100,stdin);
	LoginId[strlen(LoginId)-1]='\0';
        printf("Please Enter your Password\n");
        fgets(Password,100,stdin);
	Password[strlen(Password)-1]='\0';
        if(strcmp(LoginId,"User")==0)
	{
            if(strcmp(Password,"12345")==0){
	while(1){
                printf("\n1) Add New Language\n2) Add New Word_Meaning\n3) Modify Words\n4) Delete Words\n5) Exit\n");
		char *choice;
		printf("enter your choice\n");
		gets(choice);
		int n=atoi(choice);
		switch(n)
		{
			case 1:	writetofile();
				break;
			case 2:	writetofile();
				break;
			case 3: modify();
				break;
			case 4: delete();
				break;	
			case 5: return 0 ;	
            	}
        	}
					}
        else
	{
            printf("Try Again!!\n");
        }
	}
	
}
	
	int fd = 0;
	char buff[1024];
	char nbuff[1024];
	printf("server start running");
	//Setup Buffer Array
	memset(buff, '0',sizeof(buff));	

	//Create Socket
	fd = socket(AF_INET, SOCK_STREAM, 0);
    	if(fd<0)
	{
		perror("Client Error: Socket not created succesfully");
		return 0;
	}

	//Structure to store details
	struct sockaddr_in server; 
	memset(&server, '0', sizeof(server)); 

	//Initialize	
	server.sin_family = AF_INET;
	server.sin_port = htons(8080); 
        server.sin_addr.s_addr = htonl(INADDR_ANY);
   

	bind(fd, (struct sockaddr*)&server, sizeof(server)); 

	int in,n;
	
	listen(fd, 10);
	in = accept(fd, (struct sockaddr*)NULL, NULL); 
	if(in<0)
	{
		printf("Error in accepting request");
		exit(1);
	}
	while(1)
	{		
			//Clear Zeroes
			bzero(buff,256);
			bzero(nbuff,256);
			n = recv(in, buff, 256,0);
			if(n<0)
			{
			printf("Error in reading");
			exit(1);
			}				
		   
				
				char*word=strtok(buff,":");
				printf("\nWord Recieved From Client : %s",word);
				char*sl=strtok(NULL,":");
				printf("\nSource Language Recieved From Client : %s",sl);
				char*tl=strtok(NULL,":");
				printf("\nTarget Language Recieved From Client : %s",tl);	
				char *nbuff = translate(word,sl,tl);
				//printf("Server Sending: %s",strrev(buff));
				//Send the reversed input
				send(in, nbuff, strlen(nbuff), 0);
		
				bzero(buff,256);
										
	}	
			close(in);
			exit(0);
}

		


