#include <stdio.h>

typedef struct
{
    int sNum;
    char Name[100];
    short midTerm,Final;
    float Average;
}Student;

int main(int argc, char const *argv[])
{
    FILE* veriTabani;
    int s;
    veriTabani = fopen("database.txt","a");
    printf("Öğrenci Sayısını Giriniz: ");
    scanf("%d",&s);
    Student myStudents[s];

    for (int i = 0; i < s; i++)
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
    for (int i = 0; i < s; i++)
    {
        fprintf(veriTabani,"Okul Numarası: %d\n",myStudents[i].sNum);
        fprintf(veriTabani,"İsim: %s\n",myStudents[i].Name);
        fprintf(veriTabani,"Vize Notu: %hd\n",myStudents[i].midTerm);
        fprintf(veriTabani,"Final Notu: %hd\n",myStudents[i].Final);
        fprintf(veriTabani,"Not Ortalaması: %.2f\n\n",myStudents[i].Average);
    }
    fclose(veriTabani);
    return 0;
}
