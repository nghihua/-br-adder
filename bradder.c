#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main()
{
    // Declare file pointers
    FILE * fOriginal;
    FILE * fTemp;

    //Declare char array to hold file path
    char path[100];
    
    //Declare buffer to hold text lines
    char buffer[BUFFER_SIZE];

    //Ask for user input
    printf("Enter path of source file: ");
    scanf("%s", path);


    //Open all required files
    fOriginal  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    //fopen() return NULL if unable to open file in given mode
    if (fOriginal == NULL || fTemp == NULL)
    {
        // Unable to open file hence exit
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after adding <br>
     */
    while ((fgets(buffer, BUFFER_SIZE, fOriginal)) != NULL)
    {
        //Puts original file content onto new file
        fputs(buffer, fTemp);
        //Adding <br> after every new line character
        fputs("<br>", fTemp);
    }


    //Close all files to release resource
    fclose(fOriginal);
    fclose(fTemp);


    //Delete original source file
    remove(path);

    //Rename temp file as original file
    rename("replace.tmp", path);

    printf("\nSuccessful.");

    return 0;
}
