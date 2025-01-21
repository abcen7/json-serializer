#include "stdio.h"
#include "json_validators.h"
#include "stdbool.h"

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