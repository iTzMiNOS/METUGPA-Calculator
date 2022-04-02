#include <stdio.h>

int main ()
{
    int courseCount; //the number of times we should loop for inputs
    double totalGrade = 0;
    int totalCred = 0;
    int tempCred; //will change value each time we loop for inputs
    int tempGrade; //will change value each time we loop for inputs
    char tempLGrade[2]; //will change value each time we loop for inputs
    double tempCoefficient; //will change value each time we loop for inputs
    char choice; //user will choose between letter
    printf("Which system do you prefer for inputs? (for Letter grades type L/l and for grade out of 100 type G/g)\n");
    scanf("%c",&choice);
    if(choice - 32 <= 65){ // converting the choice to lowercase if it is not already
        choice += 32;
    }
    if(choice == 'g') {
        printf("How many courses we want to calculate?\n");
        scanf("%d", &courseCount);
        for (int i = 0; i < courseCount; i++) {
            printf("Credit of course number %d\n", i + 1);
            scanf("%d", &tempCred);
            printf("Grade out of 100?\n");
            scanf("%d", &tempGrade);
            if (tempGrade >= 90 && tempGrade <= 100) {
                tempCoefficient = 4;
            } else if (tempGrade >= 85 && tempGrade <= 89) {
                tempCoefficient = 3.5;
            } else if (tempGrade >= 80 && tempGrade <= 84) {
                tempCoefficient = 3;
            } else if (tempGrade >= 75 && tempGrade <= 79) {
                tempCoefficient = 2.5;
            } else if (tempGrade >= 70 && tempGrade <= 74) {
                tempCoefficient = 2;
            } else if (tempGrade >= 65 && tempGrade <= 69) {
                tempCoefficient = 1.5;
            } else if (tempGrade >= 60 && tempGrade <= 64) {
                tempCoefficient = 1;
            } else if (tempGrade >= 50 && tempGrade <= 59) {
                tempCoefficient = 0.5;
            } else if (tempGrade >= 0 && tempGrade <= 49) {
                tempCoefficient = 0;
            }
            totalGrade += (tempCoefficient * tempCred);
            totalCred += tempCred;
        }
    }else if(choice == 'l'){
        printf("How many courses we want to calculate?\n");
        scanf("%d", &courseCount);
        for (int i = 0; i < courseCount; i++) {
            printf("Credit of course number %d\n", i + 1);
            scanf("%d", &tempCred);
            printf("Letter grade? (AA,...,FF)\n");
            scanf("%s", &tempLGrade);
            int p = tempLGrade[0]*1000 + tempLGrade[1]; //converting string to ascii code so we can use switch
            switch(p){
                case 65065: // in a number XXXXXX each XXX indicates ascii for a letter, in this case 065065 is our number for AA
                    tempCoefficient = 4;
                    break;
                case 66065:
                    tempCoefficient = 3.5;
                    break;
                case 66066:
                    tempCoefficient = 3;
                    break;
                case 67066:
                    tempCoefficient = 2.5;
                    break;
                case 67067:
                    tempCoefficient = 2;
                    break;
                case 68067:
                    tempCoefficient = 1.5;
                    break;
                case 68068:
                    tempCoefficient = 1;
                    break;
                case 69068:
                    tempCoefficient = 0.5;
                    break;
                case 69069:
                    tempCoefficient = 0;
                    break;
                default:
                    printf("Wrong input");
            }
            totalGrade += (tempCoefficient * tempCred);
            totalCred += tempCred;
        }
    }
    double final = (totalGrade / totalCred);
    printf("Your calculated GPA is: %0.02lf", final); // %0.02lf rounds our answer to 2 digits after the dot
}