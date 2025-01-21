/*
	@copyright Copyright (c) 2025 K. Sermyagin
	@author K. Sermyagin
	@version 1.0.0
	@name JSON Serializer based on C
*/


#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "json_validators.h"
#include "main.h"

// TODO: logger.h
void print_error(const char *message) {
	printf("Error >> %s\n", message);
}


void print_json_file(const char* content) {
	for (int i = 0; content[i] != '\0'; i++) {
		printf("%c", content[i]);
	}
}

void serialize(const char* content) {
	// TODO: try to serialize objects in JSON
	printf("---------------- Serialize process ----------------\n\n");
	int counter = 0;
	for (int i = 0; content[i] != '\0'; i++) {
		// serialize objects
		if (content[i] == OBJECT_START) {
			counter++;
			printf("%d object found\n", counter);
			for (int j = i; content[j] != OBJECT_END; ++j) {
				printf("%c", content[j]);
			}
			printf("%c", OBJECT_END);
			printf("\n");
		}
	}
}

bool main_validator(const char* content) {
	// Basic structure validation
	if (!validate_json(content)) {
		return false;
	}
	// TODO: validate all data structures in json

	return true;
}

int main() {
	/*
		TODO: Define default filename
		if it doesn't exist, ask the user for it
	*/
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
		print_error("Error with opening the file");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), file_in)) {
		strncat(content, buffer, sizeof(content) - strlen(content) - 1);
	}

	fclose(file_in);

	print_json_file(content);

	if (!main_validator(content)) {
		print_error("Invalid JSON");
		return 1;
	}

	serialize(content);

	return 0;
};