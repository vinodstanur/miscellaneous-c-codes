#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include<malloc.h>

#define MAX_PATH_LENGTH 1000
recursive_print(char *name)
{
	struct dirent *p;
	DIR *dir;
	char name_buf[MAX_PATH_LENGTH] = {0}, name_buf_temp[MAX_PATH_LENGTH] = {0};
	strcpy(name_buf,name);
	strcat(name_buf,"/");
	if((dir = opendir(name_buf)) == NULL) {
		fprintf(stderr, "cant open %s\n", name_buf);
		return;
	}
	while((p = readdir(dir)) != NULL) {
		if((strcmp(p->d_name,".")) && (strcmp(p->d_name,".."))) {
			printf("\n%s%s",name_buf, p->d_name);
			if(p->d_type == 4) {
				printf("<--[FOLDER]");
				strcpy(name_buf_temp, name_buf);
				recursive_print(strcat(name_buf_temp, p->d_name));
			}
		}	
	}
}

void main(int argc, char *argv[])
{
	char  *name = malloc(200);
	if(argc > 1)
		name = argv[1];
	else
		name = ".";
	recursive_print(name);
}
