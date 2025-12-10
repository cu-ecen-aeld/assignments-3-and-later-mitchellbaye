#include <writer.h>

int main(int argc, char *argv[]){
	if (argc != 3) {
		printf("Error: Wrong number of arguments.\n");
		syslog(LOG_ERR, "Wrong number of arguments.");
	}

	FILE *filePointer;

	filePointer = fopen(argv[1], "w");

	if (filePointer == NULL) {
		syslog(LOG_ERR, "Error opening file for writing");
		return 1;
	}

	fprintf(filePointer, "Writing %s to %s", argv[1], argv[2]);
	fclose(filePointer);


	return 0;
}
