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