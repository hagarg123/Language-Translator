/*
*It will ask file name -> word
*open Original file in read mode -> Temp file in write mode...
*Traversing line by line in original file -> copy the original data with skiping the word line in temp file
*remove the original file -> rename the temp file->original file
*/

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

int find_lno(char *file)
{
	FILE*fptr1;
	fptr1=fopen(file,"r");
	int lno=0;
	if (fptr1 == NULL)
		return 0;
	char w[MAX];
	printf("Enter your word");
	fgets(w,MAX,stdin);
	w[strlen(w)-1]='\0';

	char str[MAX];
	while(1)
	{
	if(fgets(str,MAX,fptr1)==NULL) // feof returns non zero value if it points to end of file
		return 0;	
	str[strlen(str)-1]='\0';

		char *token=strtok(str,":");
		if(strcmp(token,w)==0)
		{
			return lno;
		}
		lno++;	
	}
	
}
void delete()
{
        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;
		char fname[MAX];
        char str[MAX], temp[] = "temp.txt";
	char file[100] = "/home/harsh/sprint_2/data/";
		printf("\n\n Delete a specific line from a file :\n");
		printf("-----------------------------------------\n"); 
		printf(" Input the file name to be opened : ");
		fgets(fname,MAX,stdin);
		fname[strlen(fname)-1]='\0';	
		strcat(file,fname);
        fptr1 = fopen(file, "r");
        if (!fptr1) 
		{
                printf(" File not found or unable to open the input file!!\n");
                return ;
        }
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if (!fptr2) 
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return ;
        }
        printf(" Input the line you want to remove : ");
      	lno=find_lno(file);
		lno++;
	printf("\n%d",lno);	
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1)) 
            {
                ctr++;
                /* skip the line at given line number */
                if (ctr != lno) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(file);  		// remove the original file 
        rename(temp, file); 	// rename the temporary file to original name
/*------ Read the file ----------------*/
   fptr1=fopen(file,"r"); 
            ch=fgetc(fptr1); 
          printf(" Now the content of the file %s is : \n",fname); 
          while(ch!=EOF) 
            { 
                printf("%c",ch); 
                 ch=fgetc(fptr1); 
            }
        fclose(fptr1);
/*------- End of reading ---------------*/
        return ;

}

