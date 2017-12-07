#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 using namespace std;
 void blink(int* times, FILE* IO_direction, FILE* export_file);

 int main()
 {
         system("clear");
	 srand( time(NULL) );
         FILE *export_file = NULL;        //declare pointers
         FILE *IO_direction = NULL;

         int times = 0, maxBlink = 0, number = 0;
         int* tptr = &times;
         char selection, garbege;
         maxBlink = rand() % 20 + 1;

         printf("*******************************************\n");
         printf("*     Welcome to \" Blink! Blink! Game\"    *\n");
         printf("*******************************************\n");


         printf("Please select the mode you want: \n A/) User mode\t B/) Rand mode: ");
         scanf("%s", &selection);
/********************************User mode********************************************/   
         if(selection == 'a' || selection == 'A'){
            system("clear");
            printf("User mode:\n");
            printf("Please input the number you want to blink:/(0 is exit/) ");
            scanf("%d", tptr);
            while(times != 0){
                blink(tptr, IO_direction, export_file);
                printf("Please input the number you want to blink:/(0 is exit/) ");
                scanf("%d", tptr);
            }
         }
/********************************Rand mode********************************************/         
         else if(selection == 'b' || selection == 'B'){
            system("clear");
            printf("Rand mode:\n");
            printf("The max blink number: %d\n", maxBlink);
            number = rand();
            times = number % maxBlink;
            printf("%d", times);
            while(times != 0){
                blink(tptr, IO_direction, export_file);
                number = rand();
                *tptr = number % maxBlink;
                printf("\nEnter any key for next rand: ");
		scanf("%s", &garbege);
		printf("%d", times);
            }
         }
/********************************Wrong mode********************************************/  
         else
            printf("Wrong select, good bye!\n");
 }

 void blink(int* times, FILE* IO_direction, FILE* export_file)
 {
     char str1[] = "low";
     char str2[] = "high";
     char str[] = "60";                       //value to pass to export file

     export_file = fopen ("/sys/class/gpio/export", "w");
     fwrite (str, 1, sizeof(str), export_file);
     fclose (export_file);

     for (int i=0; i< *times; i++){        //blink LED 10 times
         IO_direction = fopen ("/sys/class/gpio/gpio60/direction", "w");
         fwrite (str2, 1, sizeof(str1), IO_direction);   //set the pin to HIGH
         fclose (IO_direction);
         usleep (1000000);

         IO_direction = fopen ("/sys/class/gpio/gpio60/direction", "w");
         fwrite (str1, 1, sizeof(str1), IO_direction);   //set the pin to LOW
         fclose (IO_direction);
         usleep (1000000);}

         export_file = fopen ("/sys/class/gpio/unexport", "w");   //remove the mapping
         fwrite (str, 1, sizeof(str), export_file);
         fclose (export_file);
 }

