
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
	int fd = 0;
	char buff[1024];
	char nbuff[1024];
	char mbuff[1024];
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
	server.sin_port =  htons(8080);

	int in = inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
	if(in<0)
	{
		perror("Client Error: IP not initialized succesfully");
		return 0;
	}

	//Connect to given server	
	in = connect(fd, (struct sockaddr *)&server, sizeof(server));
	if(in<0)
	{
		perror("Client Error: Connection Failed.");
		return 0;
	}    	
	int m=1;
	while(m<3)
	{
		
		printf("\nPlease Enter The Word: ");
    		bzero(buff,256);
    		fgets(buff,255,stdin);
		buff[strlen(buff)-1]='\0';
		printf("Please Enter Your Source Language: ");
		fgets(nbuff,255,stdin);	
                nbuff[strlen(nbuff)-1]='\0';	
		printf("Please Enter Your Target Language: ");
		fgets(mbuff,255,stdin);
		strcat(buff,":");
		strcat(buff,nbuff);
		strcat(buff,":");
		strcat(buff,mbuff);
		   // printf("\nSending to SERVER: %s ",buff);
	
		/* Send message to the server */
    		in = send(fd,buff,strlen(buff),0);
		    if (in < 0) 
		    {
			 perror("\nClient Error: Writing to Server");
		    	return 0;
		    }
		    
		/* Now read server response */
		    bzero(buff,256);
		    in = recv(fd,buff,255,0);
		    if (in < 0) 
		    {
			 perror("\nClient Error: Reading from Server");
			return 0;
		    }
		 printf("\n      Meaning: %s\n ",buff);	
		m++;
	}
	close(fd);
	return 0;
}
