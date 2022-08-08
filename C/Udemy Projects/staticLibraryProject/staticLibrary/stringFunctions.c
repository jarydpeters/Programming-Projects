int numOfCharInString(char* inputStr, char searchedChar)
{
    int numOfCharFound = 0;

    while(*inputStr++)
    {
        if(*inputStr == searchedChar)
        {
            numOfCharFound++;
        }
    }
    return numOfCharFound;
}

void remNonAlphaChar(char* inputStr)
{
    int i = 0;
    int j = 0;

    for(i = 0; inputStr[i] != '\0'; ++i)
    {
        while (!((inputStr[i] >= 'a' && inputStr[i] <= 'z') || (inputStr[i] >= 'A' && inputStr[i] <= 'Z') || inputStr[i] == '\0'))
        {
            for(j = i; inputStr[j] != '\0'; ++j)
            {
                inputStr[j] = inputStr[j+1];
            }
            inputStr[j] = '\0';
        }
    }
    //inputStr contains final return value
}

int lenOfStr(char* inputStr)
{
    int lenOfStr = 0;

    while(*inputStr++)
    {
        lenOfStr++;
    }

    return lenOfStr;
}

void strConcat(char* inputStr1, char* inputStr2)
{
    int inputStr1Index = 0;
    int inputStr2Index = 0;

    //increment inputStr1Index to end and store last index value
    for(inputStr1Index = 0; inputStr1[inputStr1Index] != '\0'; ++inputStr1Index);

    //step through both strings, starting at end of inputStr1 and beginning of inputStr2
    for(inputStr2Index = 0; inputStr2[inputStr2Index] != '\0'; ++inputStr1Index, ++inputStr2Index)
    {
        inputStr1[inputStr1Index] = inputStr2[inputStr2Index];
    }
    
    inputStr1[inputStr1Index] = '\0';

    //inputStr1 contains final return value
}

void strCopy(char* inputStr, char* destStr)
{
    while(*destStr++ = *inputStr++);
    //destStr contains final return value
}

void subString(char* inputStr, int startIndex, int endIndex, char* destStr)
{
    int i = 0;

    //start and end indices are included in result
    for(i = 0; i < (endIndex - startIndex + 1); i++)
    {
        destStr[i] = inputStr[(startIndex - 1) + i];
    }

    destStr[i] = '\0';
    
    //destStr contains final return value
}