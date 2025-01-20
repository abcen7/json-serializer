/*
	@copyright Copyright (c) 2025 K. Sermyagin
	@author K. Sermyagin
	@version 1.0.0
	@name JSON Serializer based on C
*/


#include "stdio.h"
#include "stdbool.h"
#include "string.h"

// TODO: logger.h
void print_error(const char *message) {
	printf("Error >> %s\n", message);
}

// TODO: Move methods out to json_validators.h
bool validate_paired_structure(const char *content, char open, char close) {
	printf("Validating structure for symbols %c %c \n", open, close);
	long counter = 0; 
	for (int i = 0; content[i] != '\0'; i++) {
		if (content[i] == open) {
			++counter;
		} else if (content[i] == close) {
			--counter;
			if (counter < 0) {
				return false;
			}
		}
	}
	return counter == 0;
}

void print_json_file(const char* content) {
	for (int i = 0; content[i] != '\0'; i++) {
		printf("%c", content[i]);
	}
}

bool validate_json(const char* content) {
	// Implement validation logic here
  // Return true if JSON is valid, false otherwise
	char structure_symbols[2][2] = {
		{'{', '}'}, // JSON Object data structure
		{'[', ']'}  // JSON Array data structure
	};
	// Calculating count of rows in 2d array
	int rows = sizeof(structure_symbols) / sizeof(structure_symbols[0]);
	for (int i = 0; i < rows; ++i) {
		const char open = structure_symbols[i][0];
		const char close = structure_symbols[i][1];
		if (!validate_paired_structure(
				content, 
				open, 
				close
			)
		) {
			printf("Based validation: ❌, %c, %c\n", open, close);
			return false;
		}
	}
	printf("Based validation: ✅\n");
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

	if (!validate_json(content)) {
		print_error("Invalid JSON");
		return 1;
	}

	return 0;
};