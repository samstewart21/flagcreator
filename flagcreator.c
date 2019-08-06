/* Flag Creator v0.2
   Author: Sam Stewart 
   8/5/2019 
*/
#include<stdio.h>
#include <stdlib.h>

//Function to calculate the height 
int flagheight (int width)
{
   int height;
   
   height=width*2/3;
   
   return height;
}


int main (void)
{
   int i,j,width,height,gnu;
   FILE *outputfile;
   unsigned char a=205, b=42,c=62,d=255,e=67,f=111,g=77; 

   printf("Flag Creator v0.2\n");
   printf("\n");
   printf("This program is licensed under the GNU General Public License v3.0");
   printf("\n");
   printf("Flag Creator Copyright (C) 2019 Sam Stewart\n");
   printf("This program comes with ABSOLUTELY NO WARRANTY.\n");
   printf("This is free software, and you are welcome to redistribute it under certain conditions.\n");
   printf("The full GNU license can be found in the license.txt file.\n");
   printf("\n \n");
   
   

   //Opens file
   outputfile=fopen("hungaryflag.ppm","w");
   
   //Asks user to enter width 

   fprintf(stderr,"Enter the width of the flag (up to 1000 pixels): ");
   fscanf(stdin,"%i",&width);
   if(width>1000)
     {
        while(width>1000)
            {
              fprintf(stderr,"Please enter a number less than 1000: ");
               fscanf(stdin,"%i",&width);
            }
     }
   

   
   //Calls flagwidth function and passes the width
   height=flagheight(width);
    
   //Prints image data to file

   fprintf(outputfile,"P6\n");
   fprintf(outputfile,"# Hungarian Flag\n");
   fprintf(outputfile,"%i %i\n",width,height);
   fprintf(outputfile,"255\n");

   
   //Loops to create flag 
   
   //Loop to create red pixels
   for(i=0;i<height/3;i++)
      {
         for(j=0;j<width;j++)
            {
               fprintf(outputfile,"%c%c%c",a,b,c);
            }
      }


   //Loop to create white pixels 
   for(i=0;i<height/3;i++)
      {
         for(j=0;j<width;j++)
           {
              fprintf(outputfile,"%c%c%c",d,d,d);
           }
      }

   //Loop to create green pixels
   for(i=0;i<height/3;i++)
      {
         for(j=0;j<width;j++)
            {
               fprintf(outputfile,"%c%c%c",e,f,g);
            }
   
      }

   
        

   fclose(outputfile);
   
   //Prints file name to screen 
   fprintf(stderr,"hungaryflag.ppm has been created. To view the image open the .ppm file with GIMP.\n");
   
   return 0;
}

