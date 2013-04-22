const char *str = "hello";

void *malloc(int);
char *strcpy(char *, const char *);
int printf(const char *, ...);
int exit(int);
int strlen(const char *);

int main()
{   /* C language program */
    /* allocate space to hold a copy of str */
    char* s = malloc(strlen(str)+1); 
    strcpy(s, str);           /* copy s to str */
    printf("%s, world\n", s); /* print s followed by ", world\n" */
    exit(0);              /* exit program and return 0 to the OS */
}

