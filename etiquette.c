/*
 * General EEE 11 Etiquette (written in C, fancode)
 * Adapted from Sir Rowel Atienza
 * Disclaimer: The author claims no warranty with this program.
 * 						 Or even association. You're on your own now.
 */

#include <stdio.h>
#include <string.h>

#define LIMIT 333

typedef enum { no, yes } boolean;
typedef enum { man, woman } adultPerson;

void eee11GeneralEtiquette (boolean didSomeoneDie, boolean isInPalengke, adultPerson gender, boolean inSoftMode, int *safeModeLimit);
adultPerson genderSensitivity (boolean isFirstTry);
boolean willIBeCrying (boolean didSomeoneDie);
boolean willIBeBargaining (boolean isInPalengke);
adultPerson iShouldBeWhat (adultPerson gender);

int main (int argc, char const *argv[]) {
	boolean didSomeoneDie, isInPalengke, inSoftMode;
  int safeModeLimit = LIMIT;

  if (argc == 2 && strncmp(*(argv+1), "--hardcore", 10) == 0) {
    printf("======\nGeneral etiquette in EEE 11:\n======\n\nWARN: Running in hardcore mode.\nWARN: When you have this fully internalized, press Ctrl+C.\n\n");
    inSoftMode = no;
  } else {
    printf("======\nGeneral etiquette in EEE 11:\n======\n\nINFO: Running in soft mode. \nINFO: Soft limit of %d recursions has been set.\n\n", safeModeLimit);
    inSoftMode = yes;
  }

	adultPerson gender = genderSensitivity(yes);
	eee11GeneralEtiquette(didSomeoneDie, isInPalengke, gender, inSoftMode, &safeModeLimit);

	if (inSoftMode) {
		printf("\nINFO: Soft limit reached. To enable true recursion, run with the '--hardcore' argument.\nWARN: May wreck PC. When you have this fully internalized, press Ctrl+C.\n\n");
	}
	return 0;
}

void eee11GeneralEtiquette (boolean didSomeoneDie, boolean isInPalengke, adultPerson gender, boolean inSoftMode, int *safeModeLimit) {
	didSomeoneDie = no;
	isInPalengke = no;

	willIBeCrying(didSomeoneDie);
	willIBeBargaining(isInPalengke);
	iShouldBeWhat(gender);

	printf("4. Read No. 1 to 4 - this is an example of recursion\n");

  if (!inSoftMode || (inSoftMode && (*safeModeLimit)--)) {
    eee11GeneralEtiquette(didSomeoneDie, isInPalengke, gender, inSoftMode, safeModeLimit);
  }
}

adultPerson genderSensitivity (boolean isFirstTry) {
	char choice;

	if (!isFirstTry) {
		getchar();
		printf("\nCATCH: variable 'gender' of type 'adultPerson' set as 'dichotomy'.\nCATCH: comment 'For now. Please try again.'\n");
	}

	printf("Gender Identity {Options: (m)ale or (f)emale}: ");
	choice = getchar();

	return choice != 'm' ? choice != 'f' ? genderSensitivity(no) : woman : man;
}

boolean willIBeCrying (boolean didSomeoneDie) {
	if (!didSomeoneDie) printf("1. No crying - no one died\n");
	return didSomeoneDie;
}

boolean willIBeBargaining (boolean isInPalengke) {
	if (!isInPalengke) printf("2. No bargaining - this is not palengke\n");
	return isInPalengke;
}

adultPerson iShouldBeWhat (adultPerson gender) {
	printf("3. Be a %s - learn from past mistakes and move on\n", gender == man ? "man" : "woman");
	return gender;
}