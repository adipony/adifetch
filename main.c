#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0  = true, 1 = false
int startsWith(const char *pre, const char *str) {
	if (pre == NULL || str == NULL) {
		return 1;
	}
        for (int i = 0; i < strlen(pre) ; i++) {
		if (pre[i] != str[i]) {
			return 1;
		}
	}	
	return 0;
}

char *getProperty(const char *filePath, const char *queryString) {
	FILE *fptr;

	// Get CPU name
	fptr = fopen("/proc/cpuinfo", "r");
	
	if (fptr == NULL) {
		printf("Unable to get property \n");
		return NULL;
	}

	char myString[100];
	char *desired;
	int idx = 0;
	while (fgets(myString, 100, fptr)) {	
		if (startsWith(queryString, myString) == 1) {
			continue;
		}
		desired = (char *)malloc(strlen(myString));
		break;
		
	}
	int flag = 0;
	for (int i = 0; i < strlen(myString); i++) {
		if (flag == 1) {
			desired[idx] = myString[i];
			idx++;
		} 
		if (myString[i] == ':') {
			flag = 1;
		}
	}

	
	
	fclose(fptr);

	return (char *)desired;
}

int main() {

	char *cpuName = getProperty("/proc/cpuinfo", "model name");
	printf("CPU:%s", cpuName);
	free(cpuName);



	


	return 0;
}
