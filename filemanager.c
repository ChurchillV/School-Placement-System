#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

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
void save_student_data(char name[], char index[], int aggregate, char gender);
char* choose_school(char grade, char gender);

int main() {
    //Clear screen on startup
    main_menu:
    system("cls");
    printf("\n\n##### WELCOME TO GROUP 14'S SCHOOL PLACEMENT SYSTEM #####\n\n");
    printf("Press any key to continue\n\n");
    getch();

    printf("\n##### MAIN MENU #####\n");
    printf("\n1 - REGISTER NEW STUDENT\n2 - PLACEMENT CHECKER\n3 - EXIT\n");
    int option;
    printf("\n\t### WHERE ARE YOU GOING? ");
    scanf("%d", &option);

    //New Student Registration Section begins
    if (option == 1) {
        registration:
        system("cls");
        printf("##### New Student Registration #####\n\n");
        Sleep(300);
        printf("\n\nName: ");
        fflush(stdin);
        char name[255];
        gets(name);

       char index_no[8];
        do{
        Sleep(300);
        printf("\nIndex Number: ");
        scanf("%7s", &index_no);
        if (strlen(index_no) != 7){
            printf("\nInvalid index number!\nRe - enter your index number.\n");
        }
        }
        while (strlen(index_no) != 7);

        char gender;
        gender_section:
        Sleep(300);
        printf("\nGender: M/F\t");
        fflush(stdin);
        scanf("%c", &gender);        
        if (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f') {
            printf("\nInvalid option. Please try again.\n");
            goto gender_section;
        }

        int results[9];

        score_section:
        printf("\nEnter Results: \n");
        Sleep(300);
        English = get_grade(English, "ENGLISH");
        English_grade = grade_calc(English);
        Sleep(300);
        Maths = get_grade(Maths, "MATHS");
        Maths_grade = grade_calc(Maths);
        Sleep(300);
        Science = get_grade(Science, "SCIENCE");
        Science_grade = grade_calc(Science);
        Sleep(300);
        Social = get_grade(Social, "SOCIAL STUDIES");
        Social_grade = grade_calc(Social);
        Sleep(300);
        RME = get_grade(RME, "RME");
        RME_grade = grade_calc(RME);
        Sleep(300);
        BDT = get_grade(BDT, "BDT");
        BDT_grade = grade_calc(BDT);
        Sleep(300);
        GH_lang = get_grade(GH_lang, "GH. LANGUAGE");
        GH_lang_grade = grade_calc(GH_lang);
        Sleep(300);
        French = get_grade(French, "FRENCH");
        French_grade = grade_calc(French);
        Sleep(300);
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
        printf("\n\n#### STUDENT GRADING ####");
        printf("\nENGLSIH:\t%d\nMATHS:\t\t%d\nSCIENCE:\t%d\nSOCIAL STUDIES:\t%d\nRME:\t\t%d\nBDT:\t\t%d\nGH. LANGUAGE:\t%d\nFRENCH:\t\t%d\nICT:\t\t%d", English_grade,Maths_grade,Science_grade,Social_grade,RME_grade,BDT_grade,GH_lang_grade,French_grade,ICT_grade);
        int aggregate = calculate_aggregate();
        if (aggregate > 9){
            printf("\nAggregate:\t%d", aggregate);
        }
        else {
            printf("\nAggregate:\t0%d", aggregate);
        }

        save_student_data(name, index_no, aggregate, gender);
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
                printf("\n##### WHERE WOULD YOU LIKE TO GO? #####\n");
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
        system("cls");
        printf("##### SCHOOL PLACEMENT PROGRAMME #####\n\n");
        int index_number;
        placement_check:
        printf("Enter student index number: ");
        scanf("%d", &index_number);
        Sleep(300);
        printf("\nSearching for Student details...\n");

        FILE *file = fopen("students.txt", "r");
        if (!file) {
            printf("Could not open file.");
            return 1;
        }

        char line[100];
        while (fgets(line, sizeof(line), file)) {
            int read_index;
            char name[50], gender, last_name[50];
            int scores[9];
            int aggregate;
            sscanf(line, "%s %s %d %d %d %d %d %d %d %d %d %d %d %c", name, last_name, &read_index, &scores[0], &scores[1], &scores[2], &scores[3], &scores[4], &scores[5], &scores[6], &scores[7], &scores[8], &aggregate, &gender);

            if (read_index == index_number) {
                int total_score = 0;
                for (int i = 0; i < 9; i++) {
                    total_score += scores[i];
                }
                //fclose(file);

                FILE *cutoffs_file = fopen("cutoffs.txt", "r");
                if (!cutoffs_file) {
                    printf("Could not open file cutoffs.txt.\n");
                    fclose(file);
                    return 1;
                }
                char grade;
                int lower_bound, upper_bound;
                while (fscanf(cutoffs_file, "%c %d %d\n", &grade, &lower_bound, &upper_bound) != EOF) {
                    if (aggregate >= lower_bound && aggregate <= upper_bound) {
                        Sleep(300);
                        system("cls");
                        printf("NAME\t|\tINDEX NO\t|\tAGGREGATE\t|\tSCHOOL\n");
                        printf("---------------------------------------------------------------------------\n");
                        printf("%s\t|\t%d  \t|\t   %d  \t\t|\t%s\n", name, index_number, aggregate, choose_school(grade, gender));
                        break;
                    }
                }
                fclose(cutoffs_file);

                char filename[50];
                sprintf(filename, "%d.txt", index_number);
                FILE *output_file = fopen(filename, "w");
                fprintf(output_file, "Name: %s\nIndex number: %d\nSchool: %s\nAggregate: %d\nTotal score: %d", name, index_number, choose_school(grade,gender), aggregate, total_score);
                fclose(output_file);
            }
        }
        choose:
        fflush(stdin);
        printf("\n##### STUDENT PLACEMENT SUCCESSFUL #####\n");
        printf("\n1 - Place another student\n2 - Go to main menu\n3 - Exit\n\n\tOption: ");
        scanf("%c", &option);
        switch (option)
            {
            case '1':
                goto placement_check;
                break;

            case '2':
                goto main_menu;
                break;
                
            case '3':
                goto close;
                break;

            default:
                printf("Invalid option. Please try again\n");
                goto choose;
                break;
            }

        choisir:
        fflush(stdin);
        option_menu:
        printf("\n##### WHERE WOULD YOU LIKE TO GO? #####\n");
        printf("\n1 - Go to main menu\n2 - Exit\n\n\tOption: ");
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
                goto choisir;
                break;
            }
    }
    //Placement Checking Section Ends


    else if(option == 3) {
        //Programme Ends
        close:
        Sleep(300);
        printf("\nThank you for using the Group 14 Placement Application.");
    }

    else {
        printf("\nPlease enter a valid option.");
        goto main_menu;
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
void save_student_data(char name[], char index[], int aggregate, char gender) {
    //Create File and name it with the index number
    char file_name[50];
    FILE *file_ptr = fopen("students.txt", "a");

    //Write to the file
    fprintf(file_ptr, "\n%s %s %d %d %d %d %d %d %d %d %d  %d %c", name, index, English, Maths, Science, Social, RME, BDT, GH_lang, French, ICT, aggregate, gender);

    //Close file
    fclose(file_ptr);

    printf("\n\n##### PLACEMENT DETAILS SAVED SUCCESSFULLY #####");
}

//Placement Algorithm
char* choose_school(char grade, char gender) {
    char filename[50];
    if (grade == 'A' || grade == 'a') {
        if (gender == 'M' || gender == 'm') {
            strcpy(filename, "A-Schools-Boys.txt");
        } else {
            strcpy(filename, "A-Schools-Girls.txt");
        }
    } else if (grade == 'B' || grade == 'b') {
        strcpy(filename, "B-Schools.txt");
    } else {
        strcpy(filename, "C-Schools.txt");
    }

    FILE *school_file = fopen(filename, "r");
    if (!school_file) {
        printf("Could not open file %s.\n", filename);
        return NULL;
    }

    char schools[10][50];
    int i = 0;
    char line[50];
    while (fgets(line, sizeof(line), school_file)) {
        strcpy(schools[i], line);
        i++;
    }
    fclose(school_file);
    srand(time(NULL));
    int school_index = rand() % i;
    char* school = (char*) malloc(sizeof(char) * strlen(schools[school_index]));
    strcpy(school, schools[school_index]);
    return school;
}