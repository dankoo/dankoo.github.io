/*****************************************************************
 *
 * NAME:        Daniel Koo
 *
 * HOMEWORK:    Project 1
 *
 * CLASS:       ICS 212
 *
 * INSTRUCTOR:  Ravi Narayan
 *
 * DATE:        March 12, 2016
 *
 * FILE:        proj1.c
 *
 * DESCRIPTION: This is the main for the UIfunction for bank 
 *              database.
 *
 *****************************************************************/
#include <stdio.h>
#include <string.h>
#include "record.h"
#include "functions.h"

/* Global Variables*/
int debugmode = 0;

int main(int argc, char *argv[])
{
    /* Local Variables*/
    int num = 0;
    int accountno;
    char name[25];
    char address[80];
    int yearofbirth;
    struct record *start =  NULL;
    char *filename = "records.txt";
    
    /* Debug Mode*/
    char strdebug[] = "debug";

    if (argc == 2)
    {
        if (strcmp(argv[1], strdebug) == 0)
        {
            debugmode = 1;
        }
        else
        {
            if (argc >= 3)
            {
                printf("\nUsage: proj1 [-debug] \n\n");
            }
            printf("\nUsage: proj1 [-debug] \n\n");
        }
    }
    
    readfile(&start, filename);
    
    while (1)
    {
        printf("\nWelcome to your Bank Database!\n\n");
        printf("1) Add a new record\n");
        printf("2) Modify a record\n");
        printf("3) Print a record\n");
        printf("4) Print all records\n");
        printf("5) Delete a record\n");
        printf("6) Quit\n\n");
        
        scanf("%d",&num);
        
        /* Add Record*/
        if (num == 1)
        {
            printf("Enter your 6 digit Account Number:\n");
            scanf("%d", &accountno);
            
            printf("Enter your Name:\n");
            scanf("%s", name);
            
            
            
            printf("Enter your Address:\n");
            printf("When finished, press enter twice\n");
            getfield(address, sizeof(address),stdin);
            
            printf("Enter your Year of Birth:\n");
            scanf("%d", &yearofbirth);
            
            addRecord(&start, accountno, name, address, yearofbirth);
        }
        /* Modify Record*/
        if (num == 2)
        {
            printf("Enter Account Number of the record to modify:\n");
            scanf("%d", &accountno);
            
            printf("Enter new Address:\n");
            printf("When finished, press enter twice\n");
            getfield(address, sizeof(address), stdin);
            
            
            modifyRecord(start, accountno, address);
        }
        /* Print Record*/
        if (num == 3)
        {
            printf("Enter Account Number of the record to print:\n");
            scanf("%d", &accountno);
            
            printRecord(start, accountno);
        }
        /* Print All Records*/
        if (num == 4)
        {
            printAllRecords(start);
        }
        /*Delete Record*/
        if (num == 5)
        {
            printf("Enter Account Number of record to delete:\n");
            scanf("%d", &accountno);
            
            deleteRecord(&start, accountno);
        }
        /*Quit*/
        if (num == 6)
        {
            writefile(start, filename);
            cleanup(&start);
            
            printf("Shoots!~\n\n");
            return 0;
        }
        if (num > 6)
        {
            printf("Please enter a number from 1 - 6...");
        }
    }
}
