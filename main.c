#include <stdio.h>


int len (const char *str) {
	int length = 0;
	while (1) {
		if (str[length] == '\0' || length > 1024) {
			break;
		}
		length++;
	}
	return length;
}
// 0  = true, 1 = false
int startsWith(const char *pre, const char *str) {
	if (pre == NULL || str == NULL) {
		return 1;
	}
        for (int i = 0; i < len(pre) ; i++) {
		if (pre[i] != str[i]) {
			return 1;
		}
	}	
	return 0;
}

char[] getProperty(const char *filePath, const char *queryString) {
	FILE *fptr;

	// Get CPU name
	fptr = fopen("/proc/cpuinfo", "r");
	
	if (fptr == NULL) {
		printf("Unable to query CPU info \n");
		return 1;
	}

	char myString[100];
	char desired[100];
	while (fgets(myString, 100, fptr)) {	
		if (startsWith(queryString, myString) == 0) {
			int length = len(myString);
			int flag = 0;
			int idx = 0;
			for (int i = 0; i < length; i++) {
				if (flag == 1) {
					desired[idx] = myString[i];
					idx++;
				}

				if (myString[i] == ':') {
					flag = 1;
				}
			}
			break;
		}
	}

	return desired;
}

int main() {
	FILE *fptr;

	// Get CPU name
	fptr = fopen("/proc/cpuinfo", "r");
	
	if (fptr == NULL) {
		printf("Unable to query CPU info \n");
		return 1;
	}

	char myString[100];
	char cpuName[100];
	while (fgets(myString, 100, fptr)) {	
		if (startsWith("model name", myString) == 0) {
			int length = len(myString);
			int flag = 0;
			int idx = 0;
			for (int i = 0; i < length; i++) {
				if (flag == 1) {
					cpuName[idx] = myString[i];
					idx++;
				}

				if (myString[i] == ':') {
					flag = 1;
				}
			}
			break;
		}
	}

	printf("%s", cpuName);

	fclose(fptr);


	return 0;
}
