#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "evaluate.c"
#include "test.c"
#include "check.c"

/*char* concat(char* s1, char* s2){
	char* result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}
/*
*
*/
int numOfLines(char* filename)
{
    FILE *fileptr;
    int count_lines = 0;
    char chr;

    fileptr = fopen(filename, "r");
    chr = getc(fileptr);
    while (chr != EOF){
        if (chr == '\n'){
            count_lines = count_lines + 1;
        }
        chr = getc(fileptr);
    }
    fclose(fileptr);
    return count_lines+1;
}
/*
*
*/
long int fileSize(char* filename)
{
        FILE* fp = fopen(filename, "r");
        fseek(fp, 0L, SEEK_END);
        long int res = ftell(fp);
        fclose(fp);
        return res;
}
/*
*
*/
char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}/*
*
*/
void parseLine(char* line){
	validLine(line);
	char* rest = line;
	char* varName = strtok_r(rest, "=", &rest);
	varName = trimwhitespace(varName);
	validVar(varName);
	char* exp = strtok_r(rest, "=", &rest);
	float val = calculate(concat(exp,"*1"));
	put(varName,val);
}
void parseFile(char* filename){
    char content[fileSize(filename)];
    FILE *fptr = fopen(filename, "r");
    char ch;
    int n = 0;
	int lines = numOfLines(filename);
    ch = fgetc(fptr);

    while (ch != EOF)
    {
        content[n] = ch;
        n++;
        ch = fgetc(fptr);
    }
    fclose(fptr);
    char* line = strtok(content, "\n");;
    while(--lines) {
		parseLine(line);
        line = strtok(NULL, "\n");

   }

}
/*
*
*/
void main(int argc,char** argv){
	if(argc<2){printf("[!] Missing file name\nexample usage : ./main src.txt\n");}
	else{
	char* filename = argv[1];
	parseFile(filename);
	printf("Sorted by variable name using inorder traversal\n");
	inorder(context);
	BSTtoArray(context);
	printf("-----------------------\n");
	sortByVal();
	}
}
