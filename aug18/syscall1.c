#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
int main() {
	DIR *d;
	struct dirent *dtr;

	d = opendir(".");
	while (dtr = readdir(d)) 
		printf("%s\n", dtr->d_name);
	closedir(d);
	return 0;
}
