#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int sNum;
    char Name[100];
    short midTerm,Final;
    float Average;
}Student;

int main(int argc, char const *argv[])
{
    int schoolNumber,temp;
    Student myStudents[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter your school number: ");
        scanf("%d",&myStudents[i].sNum);
        printf("Enter your name: ");
        scanf("%s",&myStudents[i].Name);
        ERROR:
        printf("Enter your midterm grade: ");
        scanf("%hd",&myStudents[i].midTerm);
        if (myStudents[i].midTerm>100||myStudents[i].midTerm<0)
        {
            printf("You have entered incorrectly. Grades cannot be entered greater than 100 or less than 0.\n");
            goto ERROR;
        }
        ERROR2:
        printf("Enter your final grade: ");
        scanf("%hd",&myStudents[i].Final);
        if (myStudents[i].Final>100||myStudents[i].Final<0)
        {
            printf("You have entered incorrectly. Grades cannot be entered greater than 100 or less than 0.\n");
            goto ERROR2;
        }
        
        myStudents[i].Average = (float)myStudents[i].midTerm*(float)(0.4) + (float)myStudents[i].Final*(float)(0.6);
    }
    
    printf("Enter the school number of the student you want to check: ");
    scanf("%d",&schoolNumber);

    for (int i = 0; i < 5; i++)
    {
        if (schoolNumber==myStudents[i].sNum)
        {
            temp = i;
        }
        
    }
    
    printf("Name: %s\nSchool Number: %d\nVize: %hd\nFinal: %hd\nAverage: %.2f\n",myStudents[temp].Name,myStudents[temp].sNum,myStudents[temp].midTerm,myStudents[temp].Final,myStudents[temp].Average);
    return 0;
}
