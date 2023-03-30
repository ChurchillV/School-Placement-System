#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

//Global Variables and Function declarations
int English, Maths, Science, Social, RME, BDT, GH_lang, French, ICT;
int English_grade, Maths_grade, Science_grade, Social_grade, RME_grade, BDT_grade, GH_lang_grade, French_grade, ICT_grade;

struct student {
    char name[50];
    char index_number[8];
    int subject_results[9];
    int total_score;
};
struct student students[1000];
int num_students = 0;

//The student file
FILE* fp; 

int get_grade(int score, char name[]);
int grade_calc(int score);
int two_best(int[]);
int calculate_aggregate();
void save_student_data(char name[], int index, int aggregate, char school[]);
void update_student_file(char name[], int index, int results[]);
void show_student_data();

int main() {

    //Clear screen on startup
    main_menu:
    system("cls");
    printf("\n\n##### WELCOME TO GROUP 14'S SCHOOL PLACEMENT SYSTEM #####\n\n");
    printf("Press any key to continue\n\n");
    getch();

    printf("\nOptions:\n\n1 - Register New\n2 - Check Placement\n3 - Exit\n");
    int option;
    scanf("%d", &option);

    //New Student Registration Section begins
    if (option == 1) {
        registration:
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

        char gender;
        gender_section:
        printf("\nGender: M/F\t");
        fflush(stdin);
        scanf("%c", &gender);        
        if (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f') {
            printf("\nInvalid option. Please try again.\n");
            goto gender_section;
        }

        char school[255];
        printf("\nChoice of School: ");
        fflush(stdin);
        gets(school);

        int results[9];

        score_section:
        printf("\nEnter Results: \n");
        
        English = get_grade(English, "ENGLISH");
        English_grade = grade_calc(English);

        Maths = get_grade(Maths, "MATHS");
        Maths_grade = grade_calc(Maths);

        Science = get_grade(Science, "SCIENCE");
        Science_grade = grade_calc(Science);

        Social = get_grade(Social, "SOCIAL STUDIES");
        Social_grade = grade_calc(Social);

        RME = get_grade(RME, "RME");
        RME_grade = grade_calc(RME);

        BDT = get_grade(BDT, "BDT");
        BDT_grade = grade_calc(BDT);

        GH_lang = get_grade(GH_lang, "GH. LANGUAGE");
        GH_lang_grade = grade_calc(GH_lang);

        French = get_grade(French, "FRENCH");
        French_grade = grade_calc(French);

        ICT = get_grade(ICT, "ICT");
        ICT_grade = grade_calc(ICT);

        verify:
        char option;
        printf("\n\n### CONFIRMATION ###\n\nAre you sure you want to submit your results?\n\n1.Yes, submit results\n\n2.No (Re-enter results)\n\nOption: ");
        scanf("%c", &option);
        switch (option)
        {
        case '1':
            break;

        case '2':
            printf("Re-enter your results. \n");
            goto score_section;
            break;
        
        default:
            printf("Invalid option. Please try again\n");
            goto verify;
            break;
        }

        system("cls");
        printf("\n\nProcessing data...");
        Sleep(300);

        system("cls");
        printf("\n\n####GRADING AND SCHOOL PLACEMENT####");
        printf("\nENGLSIH:\t%d\nMATHS:\t\t%d\nSCIENCE:\t%d\nSOCIAL STUDIES:\t%d\nRME:\t\t%d\nBDT:\t\t%d\nGH. LANGUAGE:\t%d\nFRENCH:\t\t%d\nICT:\t\t%d", English_grade,Maths_grade,Science_grade,Social_grade,RME_grade,BDT_grade,GH_lang_grade,French_grade,ICT_grade);
        int aggregate = calculate_aggregate();
        if (aggregate > 9){
            printf("\nAggregate:\t%d", aggregate);
        }
        else {
            printf("\nAggregate:\t0%d", aggregate);
        }

        save_student_data(name, index_no,aggregate, school);
        printf("\nRegister another student?\n1 - Yes\n2 - No\n\tOption: ");
        fflush(stdin);
        scanf("%c", &option);
        switch (option)
            {
            case '1':
                goto registration;
                break;

            case '2':
                choice:
                printf("\n1 - Go to main menu\n2 - Exit\n\n\tOption: ");
                fflush(stdin);
                scanf("%c", &option);
                switch (option)
                    {
                    case '1':
                        goto main_menu;
                        break;

                    case '2':
                        goto close;
                        break;

                    default:
                        printf("Invalid option. Please try again\n");
                        goto choice;
                        break;
                    }

                break;
            
            default:
                printf("Invalid option. Please try again\n");
                break;
            }
    }
    //New Student Registration Section Ends


    //Placement Checking Section Begins
    else if(option == 2) {
        show_student_data();
        choose:
        printf("\n##### STUDENT DETAILS READ SUCCESSFULLY #####\n");
        printf("\n1 - Go to main menu\n2 - Exit\n\n\tOption: ");
        fflush(stdin);
        scanf("%c", &option);
        switch (option)
            {
            case '1':
                goto main_menu;
                break;

            case '2':
                goto close;
                break;
                
            default:
                printf("Invalid option. Please try again\n");
                goto choose;
                break;
            }
    }
    //Placement Checking Section Ends


    else if(option == 3) {
        close:
        printf("\nThank you for using the Group 14 Placement Application.");
    }
    return 0;
}

//Function definitions

//Function to check for errors when entering scores
int get_grade(int score, char name[]) {
    char c;
    while(1) {
        printf("\n%s: ", name);
        if (scanf("%d%c", &score, &c) != 2 || c != '\n') {
            printf("Invalid score. Please enter a number.\n");
            fflush(stdin);
        }
        else if (score > 100) {
            printf("Enter a score between 1-100\n");
        }
        else {break;}
    }
    
    return score;
}

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

//Function to update student file
void update_student_file(char name[], int index, int results[]) {
    fp = fopen("students.txt", "a");
}

//Function to check list of students & details
void show_student_data() {
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s", students[num_students].name, students[num_students].index_number) != EOF) {
        for (int i = 0; i < 9; i++) {
            fscanf(fp, "%d", &students[num_students].subject_results[i]);
            students[num_students].total_score += students[num_students].subject_results[i];
        }
        num_students++;
    }

    fclose(fp);

    printf("NAME\t|\tINDEX NO\t|\tRAW SCORE\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s\t|\t%s  \t|\t%d\n", students[i].name, students[i].index_number, students[i].total_score);
    }

}


//Function to count the number of lines(students) in the student file
// int count_students(FILE *file) {
//     int count = 0;
//     char ch;

//     while ((ch = fgetc(file)) != EOF) {
//         if (ch == '\n') {
//             count++;
//         }
//     }

//     return count;
// }