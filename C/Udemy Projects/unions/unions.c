#include <stdio.h>

union student{
    char  letterGrade;
    int   roundedGrade;
    float exactGrade;
}record1, record2;

int main(void)
{   
    //record1 values will be improperly retrieved as only exactGrade is stored by the time of printout
    record1.letterGrade  = 'A';
    record1.roundedGrade = 94;
    record1.exactGrade   = 93.75;
    printf("\nStudent 1's record:\n");
    printf("Letter Grade:  %c\n", record1.letterGrade);
    printf("Rounded Grade: %i\n", record1.roundedGrade);
    printf("Exact Grade:   %f\n", record1.exactGrade);

    //record 2 values will be properly retrieved as they are all retrieved before the next value is stored
    printf("\nStudent 2's record:\n");
    record2.letterGrade  = 'B';
    printf("Letter Grade:  %c\n", record2.letterGrade);
    record2.roundedGrade = 86;
    printf("Rounded Grade: %i\n", record2.roundedGrade);
    record2.exactGrade   = 85.625;
    printf("Exact Grade:   %f\n", record2.exactGrade);

    return 0;
}