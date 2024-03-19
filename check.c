#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validVar(char* vname){
	int len = strlen(vname);
	int i=0;
        for(i;i<len;i++){
		char ch = vname[i];
		if(i==0 && !((ch<=90 && ch>=65) || (ch<=122 && ch>=97) || ch == '_')){printf("Syntax error in variable naming scheme '%s'\n",vname);exit(0);}
		else if(i>0 && !((ch<=90 && ch>=65) || (ch<=122 && ch>=97) || ch== '_' || (ch<=57 && ch>=48))){printf("Syntax error in variable naming scheme '%s'\n",vname);exit(0);}
	}
}

void validLine(char* line){
        int len = strlen(line);
        int i=0;
	int equals = 0;
        for(i;i<len;i++){
		if(line[i]=='='){equals++;}
        }
	if(equals>1){printf("Syntax error in  '%s'\nMultible equal signs encountered\n",line);exit(0);}
}
