int addRecord (struct record **, int, char [ ],char [ ],int);
int printRecord (struct record *, int);
int modifyRecord (struct record *, int, char [ ]);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
void writefile(struct record *, char []);
void cleanup(struct record **);
char *getfield(char *, int, FILE *);
