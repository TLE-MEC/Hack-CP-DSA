#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    //deeclaring variables
    char *s,i;
    //dynamic alloacation of variable s
    s = malloc(1024 * sizeof(char));
    //input s
    scanf("%[^\n]", s);
    //resizing memory of s
    s = realloc(s, strlen(s) + 1);
    //logic to print the tokens of the sentence.
    for (char *c = s; *c != NULL; c++) 
    {
    if (*c == ' ') 
    {
        *c = '\n';
    }
    }
    //output s
    printf("%s", s);
    return 0;
}
