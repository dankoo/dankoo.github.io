h41709
s 00009/00000/00000
d D 1.1 16/03/15 23:51:50 danieldk 1 0
c date and time created 16/03/15 23:51:50 by danieldk
e
u
U
f e 0
t
T
I 1
int addRecord (struct record **, int, char [ ],char [ ],int);
int printRecord (struct record *, int);
int modifyRecord (struct record *, int, char [ ]);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
void writefile(struct record *, char []);
void cleanup(struct record **);
char *getfield(char *, int, FILE *);
E 1
