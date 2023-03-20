#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

//Global Variables and Function declarations
int English, Maths, Science, Social, RME, BDT, GH_lang, French, ICT;
int English_grade, Maths_grade, Science_grade, Social_grade, RME_grade, BDT_grade, GH_lang_grade, French_grade, ICT_grade;
int grade_calc(int score);
int two_best(int[]);
int calculate_aggregate();
void save_student_data(char name[], int index, int aggregate, char school[]);

int main() {
    
    printf("\n\n##### WELCOME TO GROUP 14'S SCHOOL PLACEMENT SYSTEM #####\n\n");
    printf("Press any key to continue\n\n");
    getch();

    printf("\nOptions:\n\n1.Register New\n2.Check Placement\n3.Exit\n");
    int option;
    scanf("%d", &option);

    //New Student Registration Section begins
    if (option == 1) {
        system("cls");
        printf("##### New Student Registration #####\n\n");
        printf("\nRegister a New Student");
        printf("\n\nName: ");
        fflush(stdin);
        char name[255];
        gets(name);

        int index_no;
        printf("\nIndex Number: ");
        scanf("%d", &index_no);

        gender_section:
        char gender;
        printf("\nGender: M/F\t");
        fflush(stdin);
        scanf("%c", &gender);        
        if (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f') {
            printf("\nInvalid option. Please try again.\n");
            goto gender_section;
        }

        char school[255];
        printf("Choice of School: ");
        fflush(stdin);
        gets(school);

        int results[9];
        score_section:

        printf("\nEnter Results: \n");
        int English, Maths, Science, Social, RME, BDT, GH_lang, French, ICT;
        printf("\nEnglish: ");
        scanf("%d", &English);
        if (English > 100) {
            printf("Invalid score. Please try again.");
            goto score_section;
        }
        English_grade = grade_calc(English);

        printf("\nMaths: ");
        scanf("%d", &Maths);
        if (Maths > 100) {
            printf("Invalid score. Please try again.");
            goto score_section;
        }
        Maths_grade = grade_calc(Maths);

        printf("\nScience: ");
        scanf("%d", &Science);
        if (Science > 100) {
            printf("Invalid score. Please try again.");
            goto score_section;
        }
        Science_grade = grade_calc(Science);

        printf("\nSocial Studies: ");
        scanf("%d", &Social);
        if (Social > 100) {
            printf("Invalid score. Please try again.");
            goto score_section;
        }
        Social_grade = grade_calc(Social);
        
        printf("\nRME: ");
        scanf("%d", &RME);
        if (RME > 100) {
            printf("Invalid score. Please try again.");
            goto score_section;
        }
        RME_grade = grade_calc(RME);

        printf("\nBDT: ");
        scanf("%d", &BDT);
         if (BDT > 100) {
            printf("Invalid score. Please try again.");
            goto score_section;
        }
        BDT_grade = grade_calc(BDT);

        printf("\nGH_lang: ");
        scanf("%d", &GH_lang);
        if (GH_lang > 100) {
            printf("Invalid score. Please try again.");
            goto score_section;
        }
        GH_lang_grade = grade_calc(GH_lang);

        printf("\nFrench: ");
        scanf("%d", &French);
        if (French > 100) {
            printf("Invalid score. Please try again.");
            goto score_section;
        }
        French_grade = grade_calc(French);

        printf("\nICT: ");
        scanf("%d", &ICT);
        if (ICT > 100) {
            printf("Invalid score. Please try again.");
            goto score_section;
        }
        ICT_grade = grade_calc(ICT);

        system("cls");
        printf("\n\nProcessing data...");
        Sleep(300);

        system("cls");
        printf("\n\n####GRADING AND SCHOOL PLACEMENT####");
        printf("\nEnglish: \t\n%d\t", English_grade);
        printf("\nMaths: \t\n%d\t", Maths_grade);
        printf("\nScience: \t\n%d\t", Science_grade);
        printf("\nSocial Studies: \t\n%d\t", Social_grade);
        printf("\nRME: \t\n%d\t", RME_grade);
        printf("\nBDT: \t\n%d\t", BDT_grade);
        printf("\nGhanaian Language: \t\n%d\t", GH_lang_grade);
        printf("\nFrench: \t\n%d\t", French_grade);
        printf("\nICT: \t\n%d\t", ICT_grade);
        int aggregate = calculate_aggregate();
        if (aggregate > 9){
            printf("\nAggregate: %d", aggregate);
        }
        else {
            printf("\nAggregate: 0%d", aggregate);
        }

        save_student_data(name, index_no,aggregate, school);
        
    }
    //New Student Registration Section Ends


    //Placement Checking Section Begins
    else if(option == 2) {
        printf("Congrats!! You were admitted");
    }
    //Placement Checking Section Ends


    else if(option == 3) {
        printf("\nThank you for using the Group 14 Placement Application.");
    }
    return 0;
}

//Function definitions

//Function for assigning grades
int grade_calc(int score) {
    int grade;
    if (score > 80) {
        grade = 1;
    }
    else if (score >= 70 && score <= 79) {
        grade = 2;
    }
    else if (score >= 50 && score <= 69) {
        grade = 3;
    }
    else if (score >= 40 && score <= 59) {
        grade = 4;
    }

    else {
        grade = 5;
    }

    return grade;
}

//Function for calculating the two best electives
int two_best(int array[]){
    int highest1 = array[0];
    int highest2 = array[0];
    for (int i = 1; i < 5; i++) {
        if (array[i] < highest1) {
            highest1 = array[i];
            highest2 = highest1;
        }

        else if (array[i] < highest2) {
            highest2 = array[i];
        }
    }
    return highest1 + highest2;
}

//Function for calculating the aggragate
int calculate_aggregate() {
    int core_aggregate = English_grade + Maths_grade + Science_grade + Social_grade;
    int elective_grades[6] = {RME_grade, BDT_grade, GH_lang_grade, French_grade, ICT_grade};
    int aggregate = core_aggregate + two_best(elective_grades);
    return aggregate;
}


//Function to save student data into a file
void save_student_data(char name[], int index, int aggregate, char school[]) {
    //Create File and name it with the index number
    char file_name[50];
    sprintf(file_name, "%d.txt", index);
    FILE *file_ptr = fopen(file_name, "w");

    //Write to the file
    fprintf(file_ptr, "Name: %s\n", name);
    fprintf(file_ptr, "Index number: %d\n", index);
    fprintf(file_ptr, "Aggregate: %d\n", aggregate);
    fprintf(file_ptr, "School: %s\n", school);

    //Close file
    fclose(file_ptr);

    printf("\n\nPlacement Details saved successfully");
}