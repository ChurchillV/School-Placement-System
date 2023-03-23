#include <stdio.h>
#include <stdlib.h>
// function declarations
char read_school_data();
char read_student_data();
void register_student(void);
int calculate_aggregate();

int main()
{
    // welcome message of the application
    int option;
    menu: 
    printf("WELCOME TO THE SCHOOL PLACEMENT SYSTEM!\n");
    printf("Select a an option\n1. Register Student\n2. Check Placement\n3. Done\n");
    scanf("%d", &option);
    
    // if (option == 1)
    // {
    //     // read_school_data;
    // }
    
    switch (option)
    {
    case 1:
        // register new student
    register_student(); 
        break;
    case 2: 
    // check placement by entering details
    printf("Check Placement\n"); 
    read_school_data();
        break;
    
    case 3:
    // end of application
    printf("Thank you!!");
        break;
    }
    
    int end_option;
    printf("Would you like to start process?\n1. YES\n2. NO\n");
    scanf("%d", &end_option);

    // switch statement to begin or end process
    switch (end_option)
    {
    case 1:
        goto menu;
        break;
    case 2:
        printf("Thank you for using school placement system!!");
        break;
    }
    
    // read_student_data();
    // read_school_data();

    return 0;
}
// function to read file with data of students
char read_school_data(){
    FILE *schooldata = fopen("C:\\Users\\hp\\Desktop\\schoolfile.txt", "r");
    char schools[1000];

    while(fgets(schools, 1000, schooldata) != NULL)
    {
        // printf("%s", schools);
    }
        printf("Choice of school: ");
        scanf("%s",&schools);
        gets(schools);

    
    fclose(schooldata);
}

// function to read data of choice of schools
char read_student_data(){
    FILE *studentdata = fopen("C:\\Users\\hp\\Desktop\\studentfile.txt", "r");
    char students[1000];

    while(fgets(students, 1000, studentdata) != NULL )
    {
        printf("%s", students);
    }
    
    fclose(studentdata);
}

// function to calculate aggregate of subjects
int calculate_aggregate(){
    // register_student();
    int aggregate ;
    int english, mathematics, social_studies, science, RME, BDT, french, languages, ICT;
    aggregate = english + mathematics + social_studies + science + ICT + BDT;
    printf("Aggregate is:  %f\n", aggregate);
    return aggregate;
}

// function to registere student into the database and calculate aggregate
void register_student(void){
    char fullname[50];
    long long indexno;
    char gender[5];
    int english, mathematics, social_studies, science, RME, BDT, french, languages, ICT;
    printf("##### New Student Registration #####\n");
    printf("\tPLEASE ENTER YOUR NAME.\nFull Name: ");
    
    FILE *results = fopen("C:\\Users\\hp\\Desktop\\resultfile.txt", "a");
    scanf("%s", &fullname);
    fprintf(results, "\n\n%s", fullname);

    gender:
    printf("Please enter the sex allocation <<M>> or <<F>>\n");
    scanf("%s",&gender);
    fprintf(results, "\nGender= %s",gender);
    
    


    printf("Index Number: ");
    scanf("%d", &indexno);
    fprintf(results, "\nIndex Number= %d", indexno);

    printf("\nPLEASE ENTER YOUR RESULTS IN GRADES.\n\n");

    
    printf("ENGLISH: ");
    scanf("%d", &english);
    fprintf(results, "\nEnglish= %d", english);

    printf("\nMATHEMATICS: ");
    scanf("%d", &mathematics);
    fprintf(results, "\nMathematics= %d", mathematics);

    printf("\nSOCIAL STUDIES: ");
    scanf("%d", &social_studies);
    fprintf(results, "\nSocial Studies= %d", social_studies);

    printf("\nSCIENCE: ");
    scanf("%d", &science);
    fprintf(results, "\nScience= %d", science);

    printf("\nRME: ");
    scanf("%d", &RME);
    fprintf(results, "\nRME= %d", RME);

    printf("\nBDT: ");
    scanf("%d", &BDT);
    fprintf(results, "\nBDT= %d", BDT);

    printf("\nFRENCH: ");
    scanf("%d", &french);
    fprintf(results, "\nFrench= %d", french);

    printf("\nLANGUAGES: ");
    scanf("%d", &languages);
    fprintf(results, "\nLanguages= %d", languages);

    printf("\nICT: ");
    scanf("%d", &ICT);
    fprintf(results, "\nICT= %d", ICT);

    calculate_aggregate();
    fclose(results);
}

