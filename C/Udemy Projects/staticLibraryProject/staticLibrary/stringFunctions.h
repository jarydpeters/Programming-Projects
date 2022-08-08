/*
inputStr     - string to search within
searchedChar - chosen character to find within intputStr

return (int) - number of times character was found within inputStr
*/
int numOfCharInString(char* inputStr, char searchedChar);

/*
inputStr - string to cull characters from

return (void)
*/
void remNonAlphaChar(char* inputStr);

/*
inputStr - string to be assessed for length

return (int) - length of string
*/
int lenOfStr(char* inputStr);

/*
inputStr1 - string to be concatenated TO
inputStr2 - string to concatenate onto inputStr1

return (void)
*/
void strConcat(char* inputStr1, char* inputStr2);

/*
inputStr - string to copy FROM
destStr  - string to copy TO

return (void)
*/
void strCopy(char* inputStr, char* destStr);

/*
inputStr   - string to be parsed into substring
startIndex - STARTING index within inputStr for substring
endIndex   - ENDING index within inputStr for substring
destString - string in which resultant substring is stored

return (void)
*/
void subString(char* inputStr, int startIndex, int endIndex, char* destStr);