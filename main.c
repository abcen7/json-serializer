/*
	@copyright Copyright (c) 2025 K. Sermyagin
	@author K. Sermyagin
	@version 1.0.0
	@name JSON Serializer based on C
*/


#include "stdio.h"
#include "stdbool.h"
#include "string.h"

bool validate_json_file(const char* content) {
	for (int i = 0; content[i] != '\0'; i++) {
		printf("%c", content[i]);
	}
	return true;	
}

int main() {
	char filename[100];
	char content[1024 * 10];
	char buffer[1024];
	FILE *file_in;
	content[0] = '\0';

  printf("Enter the filename: ");
	scanf("%s", filename);
	printf("The filename is %s\n", filename);

	file_in = fopen(filename, "r");

	if (!file_in) {
		perror("Error with opening the file");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), file_in)) {
		strncat(content, buffer, sizeof(content) - strlen(content) - 1);
	}

	fclose(file_in);

	validate_json_file(content);

	return 0;
};