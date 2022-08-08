#include <stdio.h>
#include "stringFunctions.h"

int main(void)
{
    char testString1[] = "Sphynx of black quartz, judge my vow.";
    char testString2[] = "S!phyn4x of % bla7,ck qu(-artz, jud$ge my vo8w.";
    char testString3[] = "3Sphynx of black quartz, judge my vow.";
    char testString4[] = "4Sphynx of black quartz, judge my vow.";
    char outputString1[] = "";
    char outputString2[] = "";
    char searchedChar;

    int startIndex = 0;
    int endIndex   = 0;

    printf("Removing non-alpha characters from test string 2...\n");
    remNonAlphaChar(testString2);
    printf("Resultant string: %s\n\n", testString2);

    printf("Concatenating test string 3 and test string 4...\n");
    strConcat(testString3, testString4);
    printf("Resultant string: %s\n\n", testString3);

    printf("Input character to be found within test string 1: ");
    scanf("%c", &searchedChar);
    printf("Number of letter '%c' found in test string 1 is: %d\n\n", searchedChar, numOfCharInString(testString1, searchedChar));

    printf("Length of input string: %d\n\n", lenOfStr(testString1));

    printf("Copying input string to output...\n");
    strCopy(testString1, outputString1);
    printf("Output string: %s\n", outputString1);

    printf("Input starting index for substring: ");
    scanf("%d", &startIndex);
    printf("Input ending index for substring: ");
    scanf("%d", &endIndex);
    subString(testString1, startIndex, endIndex, outputString2);
    printf("Substring with chosen indices: %s\n\n", outputString2);

    return 0;
}