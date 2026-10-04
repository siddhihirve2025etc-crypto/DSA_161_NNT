#include <stdio.h>
struct student
{
    int roll_no;
    char name[20];
    float marks;
};
void insert(struct student s[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);
        printf("Enter roll no: ");
        scanf("%d", &s[i].roll_no);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
}
void display(struct student s[], int n)
{
    int i;
    printf("\n------------------------------------------------\n");
    printf("Roll No\t\tName\t\tMarks\n");
    printf("------------------------------------------------\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%s\t\t%.1f\n",
               s[i].roll_no,
               s[i].name,
               s[i].marks);
    }
    printf("------------------------------------------------\n");
}
void search(struct student s[], int n)
{
    int roll, i, found = 0;
    printf("\nEnter roll number to search: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++)
    {
        if(s[i].roll_no == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll No: %d\n", s[i].roll_no);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.1f\n", s[i].marks);

            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        printf("\nStudent not found!\n");
    }
}
void sort(struct student s[], int n)
{
    int i, j;
    struct student temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j].roll_no > s[j + 1].roll_no)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("\nStudents sorted successfully!\n");
    display(s, n);
}
void modify(struct student s[], int n)
{
    int roll, i, found = 0;
    printf("\nEnter roll number to modify: ");
    scanf("%d", &roll);
    for(i = 0; i < n; i++)
    {
        if(s[i].roll_no == roll)
        {
            printf("\nStudent Found!\n");
            printf("Enter new name: ");
            scanf("%s", s[i].name);
            printf("Enter new marks: ");
            scanf("%f", &s[i].marks);
            printf("\nStudent details modified successfully!\n");
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        printf("\nStudent not found!\n");
    }
}
int main()
{
    struct student s[5];
    int choice;
    insert(s, 5);
    do
    {
        printf("\n========== STUDENT MENU ==========\n");
        printf("1. Display All Students\n");
        printf("2. Search Student\n");
        printf("3. Sort Students\n");
        printf("4. Modify Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                display(s, 5);
                break;
            case 2:
                search(s, 5);
                break;
            case 3:
                sort(s, 5);
                break;
            case 4:
                modify(s, 5);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}

