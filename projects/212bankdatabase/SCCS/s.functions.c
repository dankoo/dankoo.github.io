h24196
s 00517/00000/00000
d D 1.1 16/03/15 23:40:37 danieldk 1 0
c date and time created 16/03/15 23:40:37 by danieldk
e
u
U
f e 0
t
T
I 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "functions.h"

extern int debugmode;

/*****************************************************************
 *
 * Function name: addRecord
 *
 * DESCRIPTION: Adds a new record to the database
 *
 * Parameters:  start (struct record **): pointer to the address of start
 *
 *              uaccountno (int): contains the account number
 *
 *              uname (char[]): contains the name field
 *
 *              uaddress (char[]): contains the address field
 *
 *              uyearofbirth (int): contains the yearofbirth field
 *
 * Return values:  int: returns 0
 *
 *****************************************************************/
int addRecord (struct record **start, int uaccountno, char uname[ ], char uaddress[ ], int uyearofbirth)
{
    struct record *temp;
    struct record *temp2;
    struct record *temp3;
    struct record *newRecord = NULL;

    
    if (debugmode == 1)
    {
        printf("\n\nDEBUGMODE\n");
        printf("**Add Record**");
        printf("%p\n%d\n%s\n%s\n%d\n Arguments passed: ", *start, uaccountno, uname, uaddress, uyearofbirth);
    }
    
    newRecord = (struct record *) malloc(sizeof(struct record));
    
    newRecord->accountno = uaccountno;
    strcpy(newRecord->name, uname);
    strcpy(newRecord->address, uaddress);
    newRecord->yearofbirth = uyearofbirth;
    newRecord->next = NULL;
    
    if(*start==NULL)
    {
        *start = newRecord;
    }
    
    else
    {
        temp = *start;
        temp2 = *start;
        temp3 = *start;
        while ((temp2->next != NULL) && (temp2->accountno < uaccountno))
        {
            temp = temp2;
            temp2 = temp2->next;
        }
        if ((temp2 == temp3) && (temp2->accountno > uaccountno))
        {
            *start = newRecord;
            newRecord->next = temp;
        }
        else if (temp2->accountno > uaccountno)
        {
            temp3 = temp2;
            temp2 = temp;
            temp2->next = newRecord;
            newRecord->next = temp3;
        }
        else if(temp2->next ==NULL)
        {
            temp2->next = newRecord;
        }
        else
        {
            temp2 = temp2->next;
            temp3 = temp2;
            temp2 = temp;
            temp2->next = newRecord;
            newRecord->next = temp3;
        }
    }
    return 0;
}

/*****************************************************************
 *
 * Function name: printRecord
 *
 * DESCRIPTION: Print information about a record using the name as
 *              the key
 *
 * Parameters:  start (struct record *): pointer to start
 *
 *              uaccountno (int): contains the account number
 *
 * Return values: int: returns 0
 *
 *****************************************************************/
int printRecord (struct record *start, int uaccountno)
{
    struct record *temp = start;
    int count = 0;
    
    if (debugmode == 1)
    {
        printf("\n\nDEBUGMODE\n");
        printf("**Print Record**");
        printf("%s\n%p\n%d\n", "\nArguments passed: ", start, uaccountno);
    }
    
    if (temp == NULL)
    {
        printf("No Records to Print\n\n");
        return 0;
    }

    if (temp->accountno != uaccountno)
    {
        printf("\nRecord does not exist\n\n");
        return 0;
    }
    
    while (temp != NULL)
    {
        if (temp->accountno == uaccountno)
        {
            count++;
            printf("Record %d:\n", count);
	    printf("Account Number: %d\n", temp->accountno);
            printf("Name: %s\n", temp->name);
            printf("Address: %s\n", temp->address);
            printf("Year of Birth: %d\n", temp->yearofbirth);
	}
	temp = temp->next;
    }
    return 0;
}

/*****************************************************************
 *
 * Function name: modifyRecord
 *
 * DESCRIPTION: Modify a record in the database using the name
 *              as key
 *
 * Parameters:  start (struct record *): pointer to start
 *
 *              uaccountno (int): contains the account number
 *
 *              uaddress (char[]): contains the address field
 *
 * Return values:  int: returns 0
 *
 *****************************************************************/
int modifyRecord (struct record *start, int uaccountno, char uaddress[ ])
{
    struct record *temp = start;
    int count = 0;
    
    if (debugmode == 1)
    {
        printf("\n\nDEBUGMODE\n");
        printf("**Modify Record**");
        printf("%s\n%p\n%d\n%s\n", "\nArguments passed: ", start, uaccountno, uaddress);
    }
    
    if (start == NULL)
    {
        printf("\nEmpty List\n\n");
        return 0;
    }
    if (start != NULL)
    {
        temp = start;
        if (temp->next == NULL)
        {
            if (temp->accountno == uaccountno)
            {
                strcpy(temp->address, uaddress);
                count++;
            }
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
            
            if (temp->accountno == uaccountno)
            {
                strcpy(temp->address, uaddress);
                count++;
            }
        }
        
        if (count == 0)
        {
            printf("\nRecords not found\n");
        }
        else
        {
            printf("\nRecords modified\n");
        }
    }
    return 0;
}

/*****************************************************************
 *
 * Function name: printAllRecords
 *
 * DESCRIPTION: Print all information in the database
 *
 * Parameters:  start (struct record *): pointer to start
 *
 * Return values: 0 : void
 *
 *****************************************************************/
void printAllRecords(struct record *start)
{
    struct record *temp = start;
    int count = 0;
    
    if (debugmode == 1)
    {
        printf("\n\nDEBUGMODE\n");
        printf("**Print All Records**");
        printf("%s\n%p\n", "\nArguments passed: ", start);
    }
    if (temp == NULL)
    {
        printf("No Records to Print\n\n");
    }
    while (temp != NULL)
    {
        count++;
        printf("\n");
        printf("Record %d:\n", count);
        printf("Account Number: %d\n", temp->accountno);
        printf("Name: %s\n", temp->name);
        printf("Address: %s\n", temp->address);
        printf("Year of Birth: %d\n", temp->yearofbirth);
        temp = temp->next;
    }
}

/*****************************************************************
 *
 * Function name: deleteRecord
 *
 * DESCRIPTION: Delete an existing record from the database using
 *              the name as a key
 *
 * Parameters:  start (struct record **): pointer to the address of start
 *
 *              uaccountno (int): contains the account number
 *
 * Return values:  int: returns 0
 *
 *****************************************************************/
int deleteRecord(struct record **start, int uaccountno)
{
    struct record *temp= *start;
    
    if (debugmode == 1)
    {
        printf("**Delete Record**");
        printf("\n\nDEBUGMODE\n Name: %d\n", uaccountno);
        printf("%s\n%p\n%d\n", "\nArguments passed:", &start, uaccountno);
    }
    
    while (temp != NULL)
    {
        if(temp->accountno == uaccountno)
        {
            if (temp == *start)
            {
                *start = temp->next;
                free(temp);
                temp = *start;
            }
            else
            {
                struct record * temp2 = *start;
                while (temp2->next != temp)
                {
                    temp2 = temp2->next;
                }
                temp2->next = temp->next;
                free(temp);
                temp = temp2;
            }
        }
        else
        {
            temp = temp->next;
        }
    }
    printf("Record Deleted...\n\n");
    return 0;
}

/*****************************************************************
 *
 * Function name: readfile
 *
 * DESCRIPTION: Reads the records from the .txt file and adds it to
 *              the heap
 *
 * Parameters:  start (struct record **): pointer to the address of start
 *
 *              char filename[]: name of file
 *
 * Return values:  int: returns 0
 *
 *****************************************************************/
int readfile(struct record **start, char filename[])
{
    FILE *rdata;
    long savedOffset;
    int  accountnoz;
    char namez[25];
    char addressz[80];
    int  yearofbirthz;    
    
    /* Open file*/
    rdata = fopen(filename, "r");
    
    if (debugmode == 1)
    {
        printf("\n\nDEBUGMODE\n");
        printf("**Read File**");
        printf("%s\n%p\n%s\n", "\nArguments passed: ", &start, filename);
    }
    
    savedOffset = ftell(rdata);
    fseek(rdata, 0, SEEK_END);
    
    if (ftell(rdata) == 0)
    {
        printf("File is empty...\n\n");
        return 1;
    }
    
    fseek(rdata, savedOffset, SEEK_SET);
    
    while(1)
    {
        fscanf(rdata, "%d\n", &accountnoz);
                
        fgets(namez, 25, rdata);
        namez[strcspn(namez, "\0")] = 0;
                
        getfield(addressz, 80, rdata);
                
        fscanf(rdata, "%d\n", &yearofbirthz);
                
        addRecord(start, accountnoz, namez, addressz, yearofbirthz);
        
        if(feof(rdata))
        {
            printf("Reading Complete...\n\n");
            fclose(rdata);
            return 0;
        }
    }
}

/*****************************************************************
 *
 * Function name: writefile
 *
 * DESCRIPTION: Writes records to a .txt file
 *
 * Parameters:  start (struct record *): pointer to start
 *
 *              char filename[]: name of file
 *
 * Return values: int : 0
 *
 *****************************************************************/
void writefile(struct record *start, char filename[])
{
    struct record *temp = start;
    FILE *wdata = fopen(filename, "w");
    
    if (debugmode == 1)
    {
        printf("\n\nDEBUGMODE\n");
        printf("**Write File**");
        printf("%s\n%p\n%s\n", "\nArguments passed: ", start, filename);
    }
    
    if (wdata == NULL)
    {
        printf("Error opening file\n");
    }
    else
    {
        if (temp == NULL)
        {
            printf("File is empty\n");
            return;
        }
        while (temp != NULL)
        {
            fprintf(wdata, "%d", temp->accountno);
            fprintf(wdata, "%s", temp->name);
            fprintf(wdata, "%s\n", temp->address);
            fprintf(wdata, "%d\n", temp->yearofbirth);
            temp = temp->next;
        }
        fclose(wdata);
    }
}

/*****************************************************************
 *
 * Function name: cleanup
 *
 * DESCRIPTION: Deletes all records on the heap
 *
 * Parameters:	start (struct **): pointer to the address of start
 *
 *
 * Return values: 0 : void 
 *
 *****************************************************************/
void cleanup(struct record **start)
{
    struct record * temp = *start;
    struct record * temp2 = *start;
    
    if (debugmode == 1)
    {
        printf("\n\nDEBUGMODE\n");
        printf("**Clean Up**");
        printf("%s\n%p\n", "\nArguments passed: ", &start);
    }
    while(temp != NULL)
    {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    *start = NULL;
}

/*****************************************************************
 *
 * Function name: getfield
 *
 * DESCRIPTION:    Allows the user to enter multi-line input
 *                 for the address
 *
 * Parameters: address(char *) : pointer to the character array
 *
 *             num(int) : contains the number of characters
 *
 *             steam(FILE *) : pointer to a FILE object that
 *             identifies the stream where characters are read from
 *
 * Return values:   NULL : if the index == 0
 *                  address : the input if the index != 0
 *
 *****************************************************************/
char *getfield(char * address, int num, FILE * stream)
{
    char FromStream;
    int index = 0;
    
    if(num < 1)
    {
        return NULL;
    }
    else if(num==1)
    {
        *address = '\0';
        return address;
    }
    
    FromStream = fgetc(stream);
    
    while(FromStream != EOF)
    {
        address[index] = FromStream;
        index++;
        
        if(index == num - 1)
        {
            break;
        }
        else if(FromStream == '\n')
        {
            char next = fgetc(stream);
            
            if(next == '\n')
            {
                break;
            }
            else
            {
                ungetc(next, stream);
            }
        }
        FromStream = fgetc(stream);
    }
    address[index] = '\0';
    return index==0 ? NULL : address;
}
E 1
