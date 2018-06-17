#include<cstdio>
#include<iostream>
#include<cstring>
#include<direct.h>
#include<io.h>
#include <stdlib.h> 
using namespace std;
bool createDir(const char*c){
	if(access(c,0)==-1&&mkdir(c)!=0){
		printf("Dir create error\ncan't create it...\n");
		return false;
	}
	return true;
}
int main(int argc, char** argv){
	string dirName;
	printf("INPUT Direction Name:\n");
	cin>>dirName;
	if(!createDir(dirName.c_str()))
		return 0;
	FILE*main=fopen((dirName+"/main.cpp").c_str(),"w");
	fprintf(main,"#include<algorithm>\n#include<cstdio>\n#include<cmath>\nusing namespace std;\nint main(){\n	freopen(\"in.txt\",\"r\",stdin);\n	freopen(\"out.txt\",\"w\",stdout);\n	return 0;\n}");
	fclose(main);
	fclose(fopen((dirName+"/in.txt").c_str(),"w"));
	fclose(fopen((dirName+"/out.txt").c_str(),"w"));
	printf("Success");
	return 0;
}
