#include <stdio.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>

#define READ_COUNTER_ADDR 0x40050000

int32_t *read_counter = (int32_t *) READ_COUNTER_ADDR;
int main(void)
{
       int fd = open("/etc/hosts", O_RDONLY);
      char buf[16] = { 0, };
      
       
	printf("This is a test program for QEMU counter device\n");
	printf("See http://github.com/krasin/qemu-counter for more details\n\n");
	printf("Let's check if the Read Counter device presented\n");
	for (int i = 0; i < 10; i++) {
		printf("The device has been accessed for %"PRId32" times!\n", *read_counter);
	}
     
	int32_t now = *read_counter;
	if (now == 0) {
		printf("ERROR - No Read Counter detected\n");
	}
	else if (now == 11) {
		printf("OK - Read Counter works as intended\n");
	}
	else {
		printf("ERROR - Something is wrong with Read Counter\n");
	}

      /* test semihost call: open, read, close */ 
       FILE *read_file;    //read file from host
       read_file=fopen("/etc/host","r"); 
       char str[50];
       char ch;
       int i=0;
        if(read_file!=NULL){            //print the content of the file
             while((ch=getc(read_file))!=EOF){
                   printf("%c",ch);
               }
               printf("\n");
               fclose(read_file);    //The End of Reading


               printf("input string:");    //input string
               fgets(str,50,stdin);   
               

               i=0;
               FILE *write_file;      //add a string to host
               write_file=fopen("/etc/host","a");
               //putc('\n',write_file);
               while(str[i]!='\0'){
                    putc(str[i],write_file);
                    i++;
               }              
               fclose(write_file);                                                                          
          }
        else
              printf("failed");
	return 0;
}
