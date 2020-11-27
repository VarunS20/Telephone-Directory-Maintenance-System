/*
Telephone Directory Maintenance System
*/

/* Inlcuding the Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dir.h>
#include <string.h>
#include <conio.h>
#ifndef __cplusplus
typedef unsigned char bool;
static const bool False = 0;
static const bool True = 1;
#endif

/* Defining the custom  datatype using the Structures..*/
//Employee Structure
typedef struct Employee
{
    char EmployeeName[25];
    int EmployeeID;
    char DepartmentName[15];
    int DepartCode;
    char Location[5];
} employee;

// Department Structure...
typedef struct Department
{
    char deptName[15];
    int deptNum;
} department;

// Telephone Directory Structure
typedef struct TelephoneDirectory
{
    char employeeName[25];
    int employeeId;
    char departmentName[15];
    int departmentId;
    char location[5];
    int TelephoneNumber;
} telephone;

// Function Prototyping
int DepartmentCode();
void Heading();
void MainMenu();
void DepartMaintenance();
void displayDepartments();
void addDepartment();
void choiceSelcted(int);
void addDepartmentHeading();
void printEmployeedetails();
int DepartmentCode();
void AddEmployee();
int EmployeeCode();
void TelephoneDirectory();
void AddTelephoneNumber();
int TelePhoneNumber(int DeptId);
int CreateTelePhoneNumber(int DeptId);
void NameEnquiry();
void NumberEnquiry();
void TelehoneEnquiryMainMenu();
int main();
int mainMenu();

// Function Defination

/*
 * Function Defination for the Telephone Section
*/
void TelehoneEnquiryMainMenu()
{
    for (;;)
    {
        FILE *fp = fopen("DataBase/Telephone.txt", "a");
        fclose(fp);
        int choice;
        printf("\n\t\t\t\t\t\t\t======================================");
        printf("\n\t\t\t\t\t\t\tTelephone Number Enquiry \n");
        printf("\t\t\t\t\t\t\t======================================\n");
        printf("\t\t\t\t\t\t\t1.Enquiry  on Employee Name\n\t\t\t\t\t\t\t2.Enquiry on Telephone Number\n\t\t\t\t\t\t\t3.Goto Main Menu\n");
        printf("\t\t\t\t\t\t\tEnter Your Choice :");
        scanf("%d", &choice);
        system("CLS");
        switch (choice)
        {
        case 1:
            NameEnquiry();
            break;
        case 2:
            NumberEnquiry();
            break;
        case 3:
            system("CLS");
            mainMenu();
            break;
        default:
            printf("\n\t\t\t\t\t\t\tPlease Enter a valid choice..");
            break;
        }
    }
}
void NumberEnquiry() // Number Enquiry
{
    telephone Telephone;
    bool isExists = False;
    int length, i = 0;
    int input = 0;
    system("CLS");
    printf("\t\t\t\t\t\t\t======================================");
    printf("\n\t\t\t\t\t\t\tTelephone Directory Maintenance Menu\n");
    printf("\t\t\t\t\t\t\t======================================\n");
    printf("\t\t\t\t\t\t\tTelephone Number Enquiry\n");
    printf("\t\t\t\t\t\t\tEnter  Telephone Number: ");
    scanf("%d", &input);
    FILE *fp = fopen("DataBase/Telephone.txt", "r");
    if (fp == NULL)
    {
        printf("Error in opening the DataBase...");
        return;
    }
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    if (length == 0)
    {
        printf("\n\t\t\t\t\t\t\tNo Entries in the Directory ..");
        return;
    }
    fclose(fp);
    fp = fopen("DataBase/Telephone.txt", "r");
    printf("=========================================================================================================================================================================\n");
    printf("\tEMPLOYEE NAME\t\tEMPLOYEE ID\t\tEMPLOYEE DEPARTMENT\t\tEMPLOYEE DEPARTMENT CODE\t\tEMPLOYEE LOCATION\tTELEPHONE NUMBER\n");
    printf("=========================================================================================================================================================================\n");
    while (!(feof(fp)))
    {
        fscanf(fp, "%s %d %s %d %s %d", Telephone.employeeName, &Telephone.employeeId, Telephone.departmentName, &Telephone.departmentId, Telephone.location, &Telephone.TelephoneNumber);
        if (input == Telephone.TelephoneNumber)
        {
            isExists = True;
            printf("\t%-15s\t\t%-4d\t\t\t%-15s\t\t\t\t%-4d\t\t\t\t%-15s\t\t\t%-3d\n", Telephone.employeeName, Telephone.employeeId, Telephone.departmentName, Telephone.departmentId, Telephone.location, Telephone.TelephoneNumber);
            break;
        }
    }
    if (isExists == False)
    {
        printf("The Employee ' %d ' doesnt have a Telephone Number\nHence kindly create a telephone number\n", input);
    }
    printf("=========================================================================================================================================================================\n");
    fclose(fp);
    printf("\n Press Any Key to Continue..... ");
    getch();
    system("CLS");
}
void NameEnquiry() // Name Enquiry
{
    telephone Telephone;
    bool isExists = False;
    int length, i = 0, linesCount = 0;
    char input[25], ch;
    system("CLS");
    printf("\n\t\t\t\t\t\t\t======================================");
    printf("\n\t\t\t\t\t\t\tTelephone Directory Maintenance Menu\n");
    printf("\t\t\t\t\t\t\t======================================\n");
    printf("\t\t\t\t\t\t\tTelephone Number Enquiry by Name\n");
    printf("\t\t\t\t\t\t\tEnter  Employee Name: ");
    scanf("%s", input);
    // Converting the CharacterCases to lower Case
    for (i = 0; i <= strlen(input); i++)
    {
        if (input[i] >= 65 && input[i] <= 90)
            input[i] = input[i] + 32;
    }
    FILE *fp = fopen("DataBase/Telephone.txt", "r");
    if (fp == NULL)
    {
        printf("\t\t\t\t\t\t\tError in opening the DataBase...");
        return;
    }
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    if (length == 0)
    {
        printf("\t\t\t\t\t\t\tNo Entries in the Directory ..");
        fclose(fp);
        return;
    }
    fclose(fp);
    // Counting the Number of lines..
    fp = fopen("DataBase/Telephone.txt", "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            linesCount++;
    }
    fclose(fp);
    fp = fopen("DataBase/Telephone.txt", "r");
    printf("=========================================================================================================================================================================\n");
    printf("\tEMPLOYEE NAME\t\tEMPLOYEE ID\t\tEMPLOYEE DEPARTMENT\t\tEMPLOYEE DEPARTMENT CODE\t\tEMPLOYEE LOCATION\tTELEPHONE NUMBER\n");
    printf("=========================================================================================================================================================================\n");
    // Printing the Details.
    while (!(feof(fp)) && linesCount > 0)
    {
        fscanf(fp, "%s %d %s %d %s %d", Telephone.employeeName, &Telephone.employeeId, Telephone.departmentName, &Telephone.departmentId, Telephone.location, &Telephone.TelephoneNumber);
        if (!(strcmp(input, Telephone.employeeName)))
        {
            isExists = True;
            printf("\n\t%-15s\t\t%-4d\t\t\t%-15s\t\t\t\t%-4d\t\t\t\t%-15s\t\t\t%-3d\n\n", Telephone.employeeName, Telephone.employeeId, Telephone.departmentName, Telephone.departmentId, Telephone.location, Telephone.TelephoneNumber);
        }
        linesCount--;
    }
    if (isExists == False)
    {
        printf("The Employee ' %s ' doesnt have a Telephone Number\nHence kindly create a telephone number\n", input);
    }
    printf("\n=========================================================================================================================================================================\n");
    fclose(fp);
    printf("\n Press Any Key to Continue..... ");
    getch();
    system("CLS");
}

// Function for Telephone Maintenance System

void TelephoneDirectory()
{
    for (;;)
    {
        FILE *fp = fopen("DataBase/Telephone.txt", "a");
        fclose(fp);
        int choice;
        printf("\n\n\t\t\t\t\t\t\t======================================");
        printf("\n\t\t\t\t\t\t\tTelephone Directory Maintenance Menu\n");
        printf("\t\t\t\t\t\t\t======================================\n");
        // Choice Selection
        printf("\n\n\t\t\t\t\t\t\t 1. Add Telephone Number");
        printf("\n\n\t\t\t\t\t\t\t 2. Goto Main Menu");
        printf("\n\n\t\t\t\t\t\t\t Enter  your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("CLS");
            AddTelephoneNumber();
            break;
        case 2:
            system("CLS");
            mainMenu();
            break;

        default:
            printf("\t\t\t\t\t\t\tEnter a valid choice\n");
            break;
        }
    }
}
// Function to generate the Telephone Number
int TelePhoneNumber(int DeptId)
{
    bool deptExists = 0;
    int temp = 001, telenumber = 0, tempdept = 0;
    FILE *fptr = fopen("DataBase/Telephone.txt", "r");
    while (!(feof(fptr)))
    {
        fscanf(fptr, "%*s %*d %*s %d %*s %d", &tempdept, &telenumber);
        if (DeptId == tempdept)
        {
            deptExists = 1;
            if (temp < telenumber % 1000)
            {
                temp = telenumber % 1000;
            }
        }
    }
    if (deptExists)
    {
        return temp + 1;
    }
    else
    {
        return temp;
    }
}
// Creating the Appropriate Telephone number by Concatinating the DepartmentCode and Telephone Number
int CreateTelePhoneNumber(int DeptId)
{
    int number = TelePhoneNumber(DeptId);
    char s1[20], s2[3];
    sprintf(s1, "%d", DeptId);
    sprintf(s2, "%d", number);
    if (number >= 0 && number <= 9)
    {
        strcat(s1, "00");
        strcat(s1, s2);
    }
    else if (number >= 10 && number <= 99)
    {
        strcat(s1, "0");
        strcat(s1, s2);
    }
    else
    {
        strcat(s1, s2);
    }
    number = atoi(s1);
    return number;
}
// Function to add the telephone number to the directory
void AddTelephoneNumber()
{
    bool isExists = 0;
    int input, length, linesCount = 0;
    telephone Telephone;
    printf("\n\t\t\t\t\t\t\t================================\n");
    printf("\t\t\t\t\t\t\t\tAdd Telephone Number");
    printf("\n\t\t\t\t\t\t\t================================\n");
    printf("\t\t\t\t\t\t\tEnter  Employee ID: ");
    scanf("%d", &input);
    FILE *fp = fopen("DataBase/Telephone.txt", "r");
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fclose(fp);
    fp = fopen("DataBase/Telephone.txt", "r");
    if (fp != NULL && length != 0)
    {
        while (!(feof(fp)))
        {
            fscanf(fp, "%s %d %s %d %s %d", Telephone.employeeName, &Telephone.employeeId, Telephone.departmentName, &Telephone.departmentId, Telephone.location, &Telephone.TelephoneNumber);
            if (input == Telephone.employeeId)
            {
                printf("\n\t\t\t\t\t\t\tEmployee ID is %d\n", Telephone.employeeId);
                printf("\t\t\t\t\t\t\tLocation : %s\n", Telephone.location);
                printf("\t\t\t\t\t\t\tDepartment Code : %d\n", Telephone.departmentId);
                printf("\t\t\t\t\t\t\tTelephone Number Allocated : %d", Telephone.TelephoneNumber);
                printf("\n\n Press Any key to Continue....");
                getch();
                system("CLS");
                isExists = 1;
                return;
            }
        }
        fclose(fp);
    }
    fp = fopen("DataBase/Employee.txt", "r");

    if (fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\tError in opening the Employee DataBase\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    if (length == 0)
    {
        printf("\t\t\t\t\t\t\tNo Employees in the Department have been added..");
        return;
    }
    else
    {
        fclose(fp);
        fp = fopen("DataBase/Employee.txt", "r");
        while (!(feof(fp)))
        {
            fscanf(fp, "%s %d %s %d %s ", Telephone.employeeName, &Telephone.employeeId, Telephone.departmentName, &Telephone.departmentId, Telephone.location);
            if (input == Telephone.employeeId && isExists == 0)
            {
                printf("\n\t\t\t\t\t\t\tEmployee ID is%d\n", Telephone.employeeId);
                printf("\t\t\t\t\t\t\tLocation : %s\n", Telephone.location);
                printf("\t\t\t\t\t\t\tDepartment Code : %d\n", Telephone.departmentId);
                Telephone.TelephoneNumber = CreateTelePhoneNumber(Telephone.departmentId);
                printf("\t\t\t\t\t\t\tTelephone Number Allocated is %d", Telephone.TelephoneNumber);
                FILE *f = fopen("DataBase/Telephone.txt", "a");
                fprintf(f, "%s %d %s %d %s %d\n", Telephone.employeeName, Telephone.employeeId, Telephone.departmentName, Telephone.departmentId, Telephone.location, Telephone.TelephoneNumber);
                fclose(f);
                printf("\n\n Press Any key to Continue....");
                getch();
                system("CLS");
                isExists = 1;
                return;
            }
        }

        if (isExists == 0)
        {
            printf("\t\t\t\t\t\t\tPlease Enter a valid Employee ID...");
            return;
        }
    }
}

/*
 * Function for Department Maintenance
*/
void DepartMaintenance()
{
    for (;;)
    {
        int DataFolder;                               // Folder name
        DataFolder = mkdir("DataBase");               // Creating the Folder For storing the DataBase files
        FILE *fptr = fopen("DataBase/Data.txt", "a"); // Creating the File
        fclose(fptr);
        int choice; // variable to store the choice of the  user
        printf("\n\n\t\t\t\t\t\t\t\t Telephone Directory Maintenance System\n\t\t\t\t\t\t\t\t ======================================\n\n");
        printf("\t\t\t\t\t\t\t\t\t Department Maintenance Menu\n\t\t\t\t\t\t\t\t\t ===========================\n\n");
        MainMenu();           // Function Call
        scanf("%d", &choice); // Reading the choice
        system("CLS");
        choiceSelcted(choice);
    }
}
// Function to navigate to the selected choice
void choiceSelcted(int choice)
{
    switch (choice)
    {
    case 1:
        addDepartment();
        break;
    case 2:
        system("CLS");
        displayDepartments();
        break;
    case 3:
        mainMenu();
        break;
    default:
        printf("Enter a Valid Choice");
        break;
    }
}
// Function to display the Header
void Heading()
{
    printf("\n\n\t\t\t\t\t\t\t\t Telephone Directory Maintenance System\n\t\t\t\t\t\t\t\t ======================================\n\n");

    printf("\t\t\t\t\t\t\t\t\t\t Main Menu\n\t\t\t\t\t\t\t\t\t ===========================\n\n");
}

// Function for displaying the header for the Add departments choice
void addDepartmentHeading()
{
    printf("\n\n\t\t\t\t\t\t\t\t ===============================");
    printf("\n\t\t\t\t\t\t\t\t\t Add a Department\n\t\t\t\t\t\t\t\t ===============================\n\n");
}

// Function to Display the  main Menu
void MainMenu()
{
    printf("\t\t\t\t\t\t\t\t\t 1. Add Department\n\n");
    printf("\t\t\t\t\t\t\t\t\t 2. Print Department Details\n\n");
    printf("\t\t\t\t\t\t\t\t\t 3. Goto Main Menu\n\n");
    printf("\n\t\t\t\t\t\t\t\t Enter  Your  Choice :");
}
void addDepartment()
{
    department tempDept;
    char tempdept[15];
    int i = 0, count;
    printf("\t\t\t\t\t\t\t\tEnter the department Name : ");
    scanf("%s", tempdept);

    // Checking for the number of characters in the departname
    while (tempdept[i] != '\0')
    {
        count++;
        i++;
    }
    if (count >= 15) // If the characters exceeds 15 , it is not accepted
    {
        printf("Department Name is Too Long.....");
        return;
    }

    // Converting the case of the characters in the string to lowercase
    for (i = 0; i <= strlen(tempdept); i++)
    {
        if (tempdept[i] >= 65 && tempdept[i] <= 90)
            tempdept[i] = tempdept[i] + 32;
    }
    strcpy(tempDept.deptName, tempdept);
    FILE *fp = fopen("DataBase/Data.txt", "r");
    char temp[15];
    int eOf, code;

    // Checking for the existance of the department
    while (!(eOf = (feof(fp))))
    {
        fscanf(fp, "%s %d", temp, &code);
        if (!strcmp(temp, tempDept.deptName))
        {
            printf("\t\t\t\t\t\t\t\tDepartment Code : %d\n", code);
            return;
        }
    }
    fclose(fp);

    // Adding the new department if it does'nt exists
    fp = fopen("DataBase/Data.txt", "a");
    tempDept.deptNum = DepartmentCode();
    printf("\t\t\t\t\t\t\t\tDepartment Code:%d\n", tempDept.deptNum);
    fprintf(fp, "%s %d\n", tempDept.deptName, tempDept.deptNum);
    fclose(fp);
    return;
}

// Printing all the departments
void displayDepartments()
{
    FILE *f;
    char deptname[15], ch;
    int deptcode, linesCount = 0;
    f = fopen("DataBase/Data.txt", "r");
    if (f == NULL)
    {
        printf("Error in opening the file..");
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    int length = ftell(f);
    if (length == 0)
    {
        printf("No Entries in the Directory");
        fclose(f);
        return;
    }
    printf("\n\n\t\t\t\t\t\t\t =============================================");
    printf("\n\t\t\t\t\t\t\t\tAll the Existing Departments are \n");
    printf("\t\t\t\t\t\t\t =============================================\n");
    f = fopen("DataBase/Data.txt", "r");
    // Counting the number of lines in the file
    while ((ch = fgetc(f)) != EOF)
    {
        if (ch == '\n')
            linesCount++;
    }
    fclose(f);
    f = fopen("DataBase/Data.txt", "r");

    // printing all the departments
    printf("\t\t\t\t\t\t\t=========================================\n");
    printf("\t\t\t\t\t\t\tDEPARTMENT\t\tDEPARTMENT CODE\n");
    printf("\t\t\t\t\t\t\t=========================================\n");
    while (!(feof(f)) && linesCount > 0)
    {
        fscanf(f, "%s %d", deptname, &deptcode);
        printf("\t\t\t\t\t\t\t%-15s |\t %-4d \n", deptname, deptcode);
        linesCount--;
    }
    printf("\t\t\t\t\t\t\t=========================================\n");
    fclose(f);
    printf("\n Press Any Key to Continue..... ");
    getch();
    system("CLS");
}
// Department Code generation
int DepartmentCode()
{
    int length = 0;
    char ch;
    int linesCount = 0, line = 0, linenumber = 0;
    FILE *fp = fopen("DataBase/Data.txt", "r");
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    if (length == 0)
    {
        return 1000;
    }
    fp = fopen("DataBase/Data.txt", "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            linesCount++;
    }
    int codes[linesCount];
    int lastline = linesCount;
    fclose(fp);
    fp = fopen("DataBase/Data.txt", "r");
    while (!(feof(fp)) && linesCount > 0)
    {
        fscanf(fp, "%*s %d", &line);
        codes[linenumber] = line;
        linesCount--;
        linenumber++;
    }
    fclose(fp);
    return codes[lastline - 1] + 1;
}

/*
 *  Functions for Employee Maintenance
*/
void printEmployeedetails()
{
    system("CLS");
    employee Employee;
    char ch;
    int linesCount;
    FILE *fp = fopen("DataBase/Employee.txt", "r");
    if (fp == NULL)
    {
        printf("Error in opening the file..");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    if (length == 0)
    {
        printf("No Entries in the Directory");
        fclose(fp);
        return;
    }
    fp = fopen("DataBase/Employee.txt", "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            linesCount++;
    }
    fclose(fp);
    // printing all the departments.
    printf("================================================================================================================================================================\n");
    printf(" EMPLOYEE NAME\t\t\t\tEMPLOYEE ID\t\tEMPLOYEE DEPARTMENT\t\t\tEMPLOYEE DEPARTMENT CODE\t\tEMPLOYEE LOCATION \n");
    printf("================================================================================================================================================================\n");
    fp = fopen("DataBase/Employee.txt", "r");
    while (!(feof(fp)) && linesCount > 0)
    {
        fscanf(fp, "%s %d %s %d %s", Employee.EmployeeName, &Employee.EmployeeID, Employee.DepartmentName, &Employee.DepartCode, Employee.Location);
        printf(" %-25s\t|\t %-4d\t\t|\t\t %-15s\t|\t\t %-4d\t\t\t|\t\t %-13s \n", Employee.EmployeeName, Employee.EmployeeID, Employee.DepartmentName, Employee.DepartCode, Employee.Location);
        linesCount--;
    }
    printf("================================================================================================================================================================\n");
    fclose(fp);
    printf("\n Press Any Key to Continue..... ");
    getch();
    system("CLS");
    // return;
}
// Adding the employee to the Directory
void AddEmployee()
{
    employee Employee;
    char EmployeeName[25], departmentName[15], location[5];
    int count = 0, i = 0, length = 0, code = 0;
    system("CLS");
    printf("=============");
    printf("\nAdd Employee\n");
    printf("=============\n\n");
    printf("Enter Employee Name : ");
    scanf("%s", EmployeeName);
    // Checking for the number of characters in the departname
    while (EmployeeName[i] != '\0')
    {
        count++;
        i++;
    }
    if (count > 25) // If the characters exceeds 15 , it is not accepted
    {
        printf("\nEmployee Name is too long , it Should be less than 25 character long\n");
        printf("");
        getch();
        system("CLS");
        return;
    }
    // Converting the case of the characters in the string to lowercase
    for (i = 0; i <= strlen(EmployeeName); i++)
    {
        if (EmployeeName[i] >= 65 && EmployeeName[i] <= 90)
            EmployeeName[i] = EmployeeName[i] + 32;
    }
    strcpy(Employee.EmployeeName, EmployeeName);
    Employee.EmployeeID = EmployeeCode();
    // Department Code checking and storing corresponding name of the department
    char ch, deptnames[15];
    int linesCount = 0, line = 0, linenumber = 0, Code = 0, name, found = 0;
    FILE *fp = fopen("DataBase/Data.txt", "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            linesCount++;
    }
    int lastline = linesCount;
    fclose(fp);
    displayDepartments();
    printf("Enter the department Code: ");
    scanf("%d", &Code);
    fp = fopen("DataBase/Data.txt", "r");
    while (!(feof(fp)) && linesCount > 0)
    {
        fscanf(fp, "%s %d", deptnames, &name);

        if (name == Code)
        {

            strcpy(Employee.DepartmentName, deptnames);
            Employee.DepartCode = name;
            found = 1;
        }

        linesCount--;
        linenumber++;
    }
    fclose(fp);
    if (found == 0)
    {
        printf("Department code doesnt exists , Enter a valid Department Code");
        return;
    }
    fclose(fp);
    printf("Enter the location : ");
    scanf("%s", Employee.Location);
    strcpy(location, Employee.Location);
    count = 0, i = 0;
    while (location[i] != '\0')
    {
        count++;
        i++;
    }
    if (count > 5) // If the characters exceeds 15 , it is not accepted
    {
        printf("\nLocation is too long , it Should be less than 5 character long\n");
        printf("");
        getch();
        system("CLS");
        return;
    }
    fp = fopen("DataBase/Employee.txt", "a");
    fprintf(fp, "%s %d %s %d %s \n", Employee.EmployeeName, Employee.EmployeeID, Employee.DepartmentName, Employee.DepartCode, Employee.Location);
    fclose(fp);
    system("CLS");
    return;
}
int EmployeeCode()
{
    int length = 0, tempID = 0, temp = 0;
    FILE *f = fopen("DataBase/Employee.txt", "r");
    if (f == NULL)
    {
        printf("\t\t\t\t\t\t\t\t\tError in opening the Directory ... Try again");
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    if (length == 0)
    {
        return 1000;
    }
    fclose(f);
    f = fopen("DataBase/Employee.txt", "r");
    while (!(feof(f)))
    {
        fscanf(f, "%*s %d %*s %*d %*s", &tempID);
        if (temp < tempID)
        {
            temp = tempID;
        }
    }
    fclose(f);
    return temp + 1;
}

// Employee main menu.
void EmployeeMenu()
{
    for (;;)
    {
        int DataFolder;                                   // Folder name
        DataFolder = mkdir("DataBase");                   // Creating the Folder For storing the DataBase files
        FILE *fptr = fopen("DataBase/Employee.txt", "a"); // Creating the File
        fclose(fptr);
        int Choice;
        printf("\n\t\t\t\t\t\t\t\t\t==========================");
        printf("\n\t\t\t\t\t\t\t\t\tEmployee Maintenance Menu\n");
        printf("\t\t\t\t\t\t\t\t\t==========================");
        printf("\n\n\t\t\t\t\t\t\t\t\t1. Add Employee\n\n\t\t\t\t\t\t\t\t\t2.Print Employee Deatlis\n\n\t\t\t\t\t\t\t\t\t3.Goto Main Menu\n\n");
        printf("\n\t\t\t\t\t\t\t\tEnter the Choice : ");
        scanf("%d", &Choice);
        switch (Choice)
        {
        case 1:
            AddEmployee();
            break;

        case 2:
            printEmployeedetails();
            break;
        case 3:
            system("CLS");
            mainMenu();
            break;
        default:
            printf("Invalid Choice , Enter a valid Choice");
            break;
        }
    }
}

/*
 * Main Menu Function
*/
int mainMenu()
{
    int choice = 0;
    for (;;)
    {
        Heading();
        printf("\n\t\t\t\t\t\t\t\t\t1. Department Maintenance\n\t\t\t\t\t\t\t\t\t2. Employee Maintenance\n\t\t\t\t\t\t\t\t\t3. Telephone Directory Maintenance\n\t\t\t\t\t\t\t\t\t4. Telephone Enquiry\n\t\t\t\t\t\t\t\t\t5. Exit");
        printf("\n\n\t\t\t\t\t\t\t\tEnter the Choice : ");
        scanf("%d", &choice);
        system("CLS");
        switch (choice)
        {
        case 1:
            system("CLS");
            DepartMaintenance();
            break;
        case 2:
            system("CLS");
            EmployeeMenu();
            break;
        case 3:
            TelephoneDirectory();
            break;
        case 4:
            TelehoneEnquiryMainMenu();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\t\t\tEnter a Valid Choice..");
            system("CLS");
            break;
        }
    }
}
/*
 * Main Function          
*/
int main()
{
    int length = 0, linesCount = 0, employeeId = 0, input = 0;
    bool isExists = False;
    char ch;
    system("CLS");
    for (;;)
    {
        printf("\n\nTelephone Directory Maintenance System\n======================================\n");
        printf("\t=====\n\tLogin\n\t=====\n");
        printf("\nEnter the User ID ");
        scanf("%d", &input);
        FILE *fp = fopen("DataBase/Employee.txt", "r");
        if (fp == NULL)
        {
            mainMenu();
            return 0;
        }
        fseek(fp, 0, SEEK_END);
        length = ftell(fp);
        if (length == 0)
        {
            mainMenu();
            return 0;
        }
        fclose(fp);
        fp = fopen("DataBase/Employee.txt", "r");
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == '\n')
                linesCount++;
        }
        fclose(fp);
        fp = fopen("DataBase/Employee.txt", "r");
        while (!(feof(fp)) && linesCount > 0)
        {
            fscanf(fp, "%*s %d %*s %*d %*s", &employeeId);
            if (input == employeeId)
            {
                system("CLS");
                mainMenu();
                isExists = True;
                return 0;
            }
            linesCount--;
        }
        fclose(fp);
        if (isExists == False)
        {
            char opinion;
            printf("Invalid credentials , Press 'Y' to continue and 'N' to Stop");
            // scanf("%c", &opinion);
            opinion = getch();
            opinion = tolower(opinion);
            if (opinion == 'y')
            {
                system("CLS");
                continue;
            }
            else if (opinion = 'n')
            {
                break;
            }
            else
            {
                printf("Ivalid entry");
                exit(0);
            }
        }
    }
    return 0;
}
