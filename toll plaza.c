#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX_NUMBERS 10000

struct slip // For Slip Struct
{

    int transaction_id;
    char date[15];
    char time[15];
    int vat_charge;
    int Shift_charge;
    char vehicle_class[100];
    int fee;
    char payment[10];
};

struct collector // For Collector  Struct
{
    char username[20];
    char password[20];
    char name[20];
    int id;
    char gender[10];
    char address[30];
    char phone[15];
    char email[30];
};


void header();
void allheader();
void admin_login();     // for modify Login system.
void collector_login(); // for modify collector login.
int coll_fun();         // for modify collectors function.
int coll_fun1();        // for modify vehicle list.
void slipheader();      // for modify toll slip header design.
int slip();           // for modify toll slip.

int admin_fun(); // for modify admin function.
int adminslip_read();        // for modify admin slip read.
void write_slip(struct slip newslip);
int search_slip(); // for modify search slip.
void delete_slip(); // for modify delete slip.

void input_addcollector(); // for modify add collector.
void display_collector();  // for modify display collector list.
void delete_collector();   // for modify delete collector.
void edit_collector();     // for modify edit collector.

int forgate_password();   // for modify forgate password.
void collector_forgate(); // for modify collector forgate password.
void admin_forgate();     // for modify admin forgate password.

int main()
{
    header();

    int option;
    allheader();
    printf("\n\n\t\t\t\t1.Collectors Login\t\t\t");
    printf("\n\t\t\t\t2.Admin Login\t\t\t\n");
    printf("\t\t\t\t3.Forgate Password\t\t\t");

    printf("\n\t\t\t\t===================\t\t\t\n");

    printf("\t\t\t\tEnter Your Choice:");
    scanf("%d", &option);

    if (option == 1)
    {
        collector_login();
        system("cls");
        coll_fun();
    }

    else if (option == 2)
    {
        system("cls");
        admin_login();

        while (1)
        {
            int options_admin = admin_fun();
            switch (options_admin)
            {
            case 1:
                system("cls");
                adminslip_read();
                break;
            case 2:
                system("cls");
                search_slip();
                break;
            case 3:
                system("cls");
                delete_slip();
                break;
            case 4:
                system("cls");
                display_collector();
                break;
            case 5:
                system("cls");
                input_addcollector();
                break;
            case 6:
                system("cls");
                delete_collector();
                break;
            case 7:
                system("cls");
                edit_collector();
                break;
            case 8:
                printf("\n\n\t\t\t\t-----------------------------\n");
                printf("\t\t\t\tExit Successfuly..");
                printf("\n\n\t\t\t\t");
                system("pause");
                system("cls");
                return main();
                break;
            }
        }
    }

    else if (option == 3)
    {
        system("cls");
        forgate_password();
    }

    else
    {
        printf("\n\t\t\t\t-----------------------------\n");
        printf("\t\t\t\tWrong Choice\n\n");
        printf("\n\n\t\t\t\t");
        system("pause");
        system("cls");
        return main();
    }

    return 0;
}

//=======================End Main Function ====================================//

//=================== Area For struct ================================//



struct collector add_collector()
{
    struct collector new_collector;
    FILE *file;
    file = fopen("collector.txt", "a+");

    allheader();
    printf("\n\t\t\t\t     ADD COLLECTOR DATA\n\n\n");

    printf("\t\t\t\tCollector ID:");
    scanf("%d", &new_collector.id);

    printf("\n\t\t\t\tUser Name:");
    fflush(stdin);
    fgets(new_collector.username, sizeof(new_collector.username), stdin);
    new_collector.username[strlen(new_collector.username) - 1] = '\0'; // fgets takes an extra \n character as input

    printf("\n\t\t\t\tPassword:");
    fflush(stdin);
    fgets(new_collector.password, sizeof(new_collector.password), stdin);
    new_collector.password[strlen(new_collector.password) - 1] = '\0'; // fgets takes an extra \n character as input

    printf("\n\t\t\t\tName:");
    fflush(stdin);
    fgets(new_collector.name, sizeof(new_collector.name), stdin);
    new_collector.name[strlen(new_collector.name) - 1] = '\0'; // fgets takes an extra \n character as input

    printf("\n\t\t\t\tGender:");
    fflush(stdin);
    fgets(new_collector.gender, sizeof(new_collector.gender), stdin);
    new_collector.gender[strlen(new_collector.gender) - 1] = '\0'; // fgets takes an extra \n character as input

    printf("\n\t\t\t\tAddress:");
    fflush(stdin);
    fgets(new_collector.address, sizeof(new_collector.address), stdin); // fgets takes an extra \n character as input
    new_collector.address[strlen(new_collector.address) - 1] = '\0';    // fgets takes an extra \n character as input

    printf("\n\t\t\t\tPhone:");
    fflush(stdin);
    fgets(new_collector.phone, sizeof(new_collector.phone), stdin); // fgets takes an extra \n character as input
    new_collector.phone[strlen(new_collector.phone) - 1] = '\0';    // fgets takes an extra \n character as input

    printf("\n\t\t\t\tEmail:");
    fflush(stdin);
    fgets(new_collector.email, sizeof(new_collector.email), stdin);
    new_collector.email[strlen(new_collector.email) - 1] = '\0'; // fgets takes an extra \n character as input

    printf("\n\n\t\t\t\tCollector Added Successfully\n\n");
    printf("\n\n\t\t\t\t");

    fwrite(&new_collector, sizeof(new_collector), 1, file);
    fclose(file);

    system("pause");
    system("cls");
    return;
} // End Collector Struct

//=================== End Area For struct ================================//

//=================== Start Function For ADMIN Login ================================//

//====================forget user pass struct=======================================//

struct admin_forgate
{
    char newuser[20];
    char newpass[20];
};
//=================================================================================//
void admin_login()
{
    char true_user[20] = {"p"};
    char true_pass[20] = {"p"};

    char user[20];
    char pass[20];

    char forgetuser[20];
    char forgetpass[20];

    FILE *file;
    file = fopen("admin.txt", "r+");
    

    struct admin_forgate new_admin;

    fread(&new_admin, sizeof(new_admin), 1, file);
    strcpy(forgetuser, new_admin.newuser);
    strcpy(forgetpass, new_admin.newpass);

    while (1)
    {
        system("cls");
        allheader();

        printf("\n\t\t\t\tUser & Password For ADMIN\n");
        printf("\t\t\t\tEnter \'0\' & \'0\' for Exit\n");

        printf("\n\n\t\t\t\tUser Name: \t");
        fflush(stdin);
        fgets(user, sizeof(user), stdin);
        user[strlen(user) - 1] = '\0';

        printf("\n\t\t\t\tUser Pass: \t");
        fflush(stdin);
        fgets(pass, sizeof(pass), stdin);
        pass[strlen(pass) - 1] = '\0';

        if (strcmp(user, "0") == 0 && strcmp(pass, "0") == 0)
        {
            printf("\t\t\t\t-----------------------------\n");
            printf("\n\n\t\t\t\tExit Success...");
            printf("\n\n\t\t\t\t");
            fclose(file);
            system("pause");
            system("cls");
            return main();
        }
        else if (strcmp(user, true_user) == 0 && strcmp(pass, true_pass) == 0)
        {
            printf("\t\t\t\t-----------------------------\n");
            printf("\t\t\t\tLogin Success....");
            printf("\n\n\t\t\t\t");
            system("pause");
            break;
        }
        else if (strcmp(user, forgetuser) == 0 && strcmp(pass, forgetpass) == 0)
        {
            printf("\t\t\t\t-----------------------------\n");
            printf("\n\n\t\t\t\tLogin Success....");
            printf("\n\n\t\t\t\t");
            system("pause");
            break;
        }
        else
        {
            printf("\t\t\t\t-----------------------------\n");
            printf("\n\n\t\t\t\tWrong!! User and Password");
            printf("\n\n\t\t\t\t");
            system("pause");
        }
    }

    fclose(file);
}
//=================== End Function For ADMIN Login ================================//

//=================== Start Function For Collector Login ================================//
void collector_login()
{

    int flag = 0;
    do
    {
        char username[20];
        char password[20];

        FILE *file;
        file = fopen("collector.txt", "r+");
        struct collector new_collector;

        system("cls");
        allheader();
        fflush(stdin);
        printf("\n\t\t\t\tUser & Password For Collectors\n");
        printf("\t\t\t\tEnter User & Pass\'0\' for Exit");
        printf("\n\n\t\t\t\tEnter User Name:\t");
        fgets(username, sizeof(username), stdin);
        username[strlen(username) - 1] = '\0'; // fgets takes an extra \n character as input

        printf("\n\t\t\t\tEnter Password:\t\t");
        fgets(password, sizeof(password), stdin);
        password[strlen(password) - 1] = '\0'; // fgets takes an extra \n character as input

        while (fread(&new_collector, sizeof(new_collector), 1, file) == 1)
        {
            if (strcmp(new_collector.username, username) == 0 && strcmp(new_collector.password, password) == 0)
            {
                flag = 1;
                printf("\n\t\t\t\tLogin Success....");
                printf("\n\t\t\t\t");
                system("pause");
                break;
            }
            else if (strcmp(username, "0") == 0 && strcmp(password, "0") == 0)
            {
            printf("\t\t\t\t-----------------------------\n");
                printf("\t\t\t\tExit Success...\n\n");
                printf("\n\n\t\t\t\t");
                system("pause");
                system("cls");
                fclose(file);
                return main();
            }
        }
        if (flag == 0)
        {
            printf("\t\t\t\t-----------------------------\n");
            printf("\t\t\t\tLogin Failed\n\n");
            printf("\n\n\t\t\t\t");
            system("pause");
        }
        fclose(file);
    } while (flag == 0);
}
//=================== End Function For Collector Login =================================//

void allheader()
{
    printf("\t\t\t       -----------------------------           \n");
    printf("\t\t\t          GOLDEN BRIDGE MANAGEMENT             \n");
    printf("\t\t\t       -----------------------------           \n");
}

//=================== Start Function For Header Design ================================//
void header()
{
    time_t t;
    time(&t);

    printf("\n\n\n\t\t\t*************************************************\n");
    printf("\t\t\t*                                               *\n");
    printf("\t\t\t*       -----------------------------           *\n");
    printf("\t\t\t*          GOLDEN BRIDGE MANAGEMENT             *\n");
    printf("\t\t\t*       -----------------------------           *\n");
    printf("\t\t\t*                                               *\n");
    printf("\t\t\t*************************************************\n\n\n");
    printf("\t\t\t--------------------------------------------------          ");
    printf("\n\t\t\tCurrent date and time : %s", ctime(&t));
    printf("\t\t\t--------------------------------------------------           \n");
    printf("\n\n\t\t\t");
    system("pause");
    system("cls");
}
//=================== End Function For Header Design ================================//

//=================== START Function For Collectors FUNCTION MENU ================================//
int coll_fun()
{
    int options_coll;
    do
    {
        allheader();
        printf("\n\n\t\t\t\t1.Creat Toll Slip.\t\t\t");
        printf("\n\t\t\t\t2.Exit\t\t\t");
        printf("\n\t\t\t\t===================\t\t\t");
        printf("\n\t\t\t\tEnter Your Choices:");
        scanf("%d", &options_coll);

        if (options_coll != 1 && options_coll != 2)
        {
            printf("\n\n\t\t\t\t-----------------------------\n");
            printf("\t\t\t\tWrong Choice\n\n");
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
        }
    } while (options_coll != 1 && options_coll != 2);
    switch (options_coll)
    {
    case 1:
    {
        system("cls");
        slip();
    };
    break;

    case 2:
    {
        printf("\n\t\t\t\tExit Success...");
        printf("\n\t\t\t\t");
        system("pause");
        system("cls");
        return main();
    };
    break;
    }
    return options_coll;
}
//=================== END Function For Collectors FUNCTION MENU ================================//

//=================== START Function For Collectors TOLL VEHICLE TYPE MENU ================================//
int coll_fun1()
{
    int option_coll1;
    while (1)
    {
        allheader();
        printf("\n\n\t\t\t\tSelect Vahicle Type\t\t\t");
        printf("\n\t\t\t\t1.Motorcycle                 - Tk100\t\t\t");
        printf("\n\t\t\t\t2.Car/Jeep                   - Tk750\t\t\t");
        printf("\n\t\t\t\t3.Pickup                     - Tk1,200\t\t\t");
        printf("\n\t\t\t\t4.Microbus                   - Tk1,300\t\t\t");
        printf("\n\t\t\t\t5.Minibus                    - Tk1,400\t\t\t");
        printf("\n\t\t\t\t6.Medium bus                 - Tk2,000\t\t\t");
        printf("\n\t\t\t\t7.Big bus                    - Tk2,400\t\t\t");
        printf("\n\t\t\t\t8.Truck (upto 5 tonnes)      - Tk1,600\t\t\t");
        printf("\n\t\t\t\t9.Truck (5-8 tonnes)         - Tk2,100\t\t\t");
        printf("\n\t\t\t\t10.Truck (3 axle)            - Tk5,500\t\t\t");
        printf("\n\t\t\t\t11.Trailer (4 axle)          - Tk6,000\t\t\t");
        printf("\n\t\t\t\t12.Tailer (above 4 axle)     - Tk8,000\t\t\t");
        printf("\n\n\t\t\t\t\t FOR EXIT ENTER \'0\' \t\t\t");

        printf("\n\n\t\t\t\tSelect Here:\t\t\t");
        fflush(stdin);
        scanf("%d", &option_coll1);

        if (option_coll1 == 0)
        {
            printf("\t\t\t\t-----------------------------\n");
            printf("\t\t\t\tExit Success...\n\n");
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
            return coll_fun();
        }
        else if (option_coll1 < 1 || option_coll1 > 12)
        {
            printf("\t\t\t\t-----------------------------\n");
            printf("\t\t\t\tWrong Choice\n\n");
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
        }
        else
        {
            return option_coll1;
        }
    }
}
//=================== END Function For Collectors TOLL VEHICLE TYPE MENU ================================//



struct slip creatslip(int vehicle_class)
{
    struct slip newslip;

    //----------------For Date And Time -------------------------//

    time_t t;
    time(&t);
    strcpy(newslip.date, ctime(&t));
    //----------------For Date And Time -------------------------//


    newslip.transaction_id = rand() % MAX_NUMBERS + 1;

    newslip.vat_charge = 3;
    newslip.Shift_charge = 7;

    switch (vehicle_class)
    {
    case 1:
        strcpy(newslip.vehicle_class, "Motorcycle");
        newslip.fee = 100;
        break;
    case 2:
        strcpy(newslip.vehicle_class, "Car/Jeep");
        newslip.fee = 750;
        break;
    case 3:
        strcpy(newslip.vehicle_class, "Pickup");
        newslip.fee = 1200;
        break;
    case 4:
        strcpy(newslip.vehicle_class, "Microbus");
        newslip.fee = 1300;
        break;
    case 5:
        strcpy(newslip.vehicle_class, "Minibus");
        newslip.fee = 1400;
        break;
    case 6:
        strcpy(newslip.vehicle_class, "Medium bus");
        newslip.fee = 2000;
        break;
    case 7:
        strcpy(newslip.vehicle_class, "Big bus");
        newslip.fee = 2400;
        break;
    case 8:
        strcpy(newslip.vehicle_class, "Truck (upto 5 tonnes)");
        newslip.fee = 1600;
        break;
    case 9:
        strcpy(newslip.vehicle_class, "Truck (5-8 tonnes)");
        newslip.fee = 2100;
        break;
    case 10:
        strcpy(newslip.vehicle_class, "Truck (3 axle)");
        newslip.fee = 5500;
        break;
    case 11:
        strcpy(newslip.vehicle_class, "Trailer (4 axle)");
        newslip.fee = 6000;
        break;
    case 12:
        strcpy(newslip.vehicle_class, "Tailer (above 4 axle)");
        newslip.fee = 8000;
        break;
    }
    newslip.date[strlen(newslip.date) - 1] = '\0'; // fgets takes an extra \n character as input
    strcpy(newslip.payment, "Cash");
    return newslip;
} // End Slip Struct

//=================== START Function For TOLL SLIP HEADER ================================//

void slipheader()
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[11];
    // char time[9];
    strftime(date, sizeof(date), "%Y-%m-%d", t);
    // strftime(time, sizeof(time), "%H:%M:%S", t);
    // printf("Time: %s\n", time);

    printf("\n\n\t\t\t\t    GOLDEN BRIDGE TICKET\t\t\t");
    printf("\n\t\t\t\t      Date: %s\t\t\t", date);
    printf("\n\t\t\t     ---------------------------------- \t\t\t");
}

//=================== END Function For TOLL SLIP HEADER ================================//

//=================== START Function For TOLL SLIP BODY ================================//



//=================== END Function For TOLL SLIP BODY ================================//

//=================== START Function For  TOLL SLIP  ================================//

int slip()
{
    while (1)
    {
       
        struct slip newslip;
        int option = coll_fun1();
        if (option == 0)
        {
            return 0;
        }
        FILE *file = fopen("slip.txt", "a+");
         
        newslip = creatslip(option);
        system("cls");
        slipheader();
        fwrite(&newslip, sizeof(newslip), 1, file);
            printf("\n\n\t\t\t\tTransaction ID: %d\t\t\t", newslip.transaction_id);
            printf("\n\t\t\t\tVehicle Class: %s\t\t\t", newslip.vehicle_class);
            printf("\n\n\t\t\t\tFee:                   %dTK\t\t\t", newslip.fee);
            printf("\n\t\t\t\tShift charge:            %1dTK\t\t\t", newslip.Shift_charge);
            printf("\n\t\t\t\tVAT charge:              %1dTK\t\t\t", newslip.vat_charge);
            printf("\n\t\t\t\tPayment:                 %s\t\t\t", newslip.payment);
            printf("\n\t\t\t    ---------------------------------- \t\t\t");
            printf("\n\t\t\t\tPayable:                 %dTK\t\t\t", newslip.Shift_charge + newslip.vat_charge + newslip.fee);
            printf("\n\n\t\t\t\tThank you, have a nice trip\t\t\t\n");        
            fclose(file);

        printf("\n\n\t\t\t\t");
        system("pause");
        system("cls");
    }
}

//=================== END Function For  TOLL SLIP  ================================//

//=================== START Function For Admin Menu ================================//

int admin_fun()
{

    int options_admin;

    do
    {
        system("cls");
        allheader();
        printf("\n\t\t\t\t1.Toll Slip List.\t\t\t");
        printf("\n\t\t\t\t2.Toll Slip List By Transaction ID.\t\t\t");
        printf("\n\t\t\t\t3.Delete Toll Slip.\t\t\t");
        printf("\n\n\t\t\t\t4.Collector List.\t\t\t");
        printf("\n\t\t\t\t5.Add Collector.\t\t\t");
        printf("\n\t\t\t\t6.Delete Collector.\t\t\t");
        printf("\n\t\t\t\t7.Edit Collector Data.\t\t\t");
        printf("\n\t\t\t\t8.Exit.\t\t\t");

        printf("\n\n\t\t\t\tEnter \'0\' for Exit\t\t\t");
        printf("\n\t\t\t\t============================\t\t\t");
        printf("\n\t\t\t\tEnter Your Choice:         ");

        scanf("%d", &options_admin);

        if ((options_admin < 1 || options_admin > 8) && (options_admin != 0))
        {
            printf("\n\n\t\t\t\t-----------------------------\n");
            printf("\t\t\t\tWrong Choice\n\n");
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
        }
        if (options_admin == 0)
        {
            printf("\n\t\t\t\t-----------------------------\n");
            printf("\t\t\t\tExit Success...\n\n");
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
            return main();
        }

    } while (options_admin < 1 || options_admin > 8); // for modify admin function.
    return options_admin;
}

//=================== END Function For Admin Menu ================================//

//=================== START Function For Admin SLIP READ ================================//

int adminslip_read()
{

    struct slip newslip;
    int i = 1;
    FILE *file = fopen("slip.txt", "r");
   
        allheader();
        while (fread(&newslip, sizeof(newslip), 1, file) == 1)
        {
            slipheader();
            printf("\n\t\t\t\t      TOTAL RECORD DATA");

                    printf("\n\n\t\t\t\tTransaction ID: %d\t\t\t", newslip.transaction_id);
                    printf("\n\t\t\t\tVehicle Class: %s\t\t\t", newslip.vehicle_class);
                    printf("\n\n\t\t\t\tFee:                   %dTK\t\t\t", newslip.fee);
                    printf("\n\t\t\t\tShift charge:            %1dTK\t\t\t", newslip.Shift_charge);
                    printf("\n\t\t\t\tVAT charge:              %1dTK\t\t\t", newslip.vat_charge);
                    printf("\n\t\t\t\tPayment:                 %s\t\t\t", newslip.payment);
                    printf("\n\t\t\t    ---------------------------------- \t\t\t");
                    printf("\n\t\t\t\tPayable:                 %dTK\t\t\t", newslip.Shift_charge + newslip.vat_charge + newslip.fee);
                    printf("\n\n\t\t\t\tThank you, have a nice trip\t\t\t\n");
                    printf("\n\t\t\t\tToTal Ticket: %d\n\n\n", i);
            i++;
        }
    

    fclose(file);

    printf("\n\n\t\t\t\t");
    system("pause");
    system("cls");

    return 0;
}

//=================== START Function For Write SLIP ================================//

void write_slip(struct slip newslip) // Write slip to the file
{
    FILE *file = fopen("slip.txt", "a");
   

    fwrite(&newslip, sizeof(newslip), 1, file);

    fclose(file);
}

//=================== END Function For Admin SLIP READ ================================//

//=================== START Function For Search SLIP ================================//

int search_slip()
{

    allheader();
    FILE *file;
    int transaction_id;
    int flag = 1;
    struct slip newslip;
    file = fopen("slip.txt", "r+");
  
    printf("\t\t\t\t     SEARCH RECORD DATA");

    printf("\n\n\t\t\t\tEnter \'0\' For Exit\t");
    fflush(stdin);
    printf("\n\n\t\t\t\tEnter Transaction ID:\t");
    scanf("%d", &transaction_id);
    if (transaction_id == 0)
    {
        printf("\n\n\t\t\t\t-----------------------------\n");
        printf("\t\t\t\tExit Success...\n\n");
        printf("\n\n\t\t\t\t");
        system("pause");
        system("cls");
        return main();
    }
    int i = 1;
    while (fread(&newslip, sizeof(newslip), 1, file) == 1)
    {
        if (newslip.transaction_id == transaction_id)
        {       system("cls");
            slipheader();
                    printf("\n\t\t\t\t    RECORD DATA BY SEARCH");

                    printf("\n\n\t\t\t\tTransaction ID: %d\t\t\t", newslip.transaction_id);
                    printf("\n\t\t\t\tVehicle Class: %s\t\t\t", newslip.vehicle_class);
                    printf("\n\n\t\t\t\tFee:                   %dTK\t\t\t", newslip.fee);
                    printf("\n\t\t\t\tShift charge:            %1dTK\t\t\t", newslip.Shift_charge);
                    printf("\n\t\t\t\tVAT charge:              %1dTK\t\t\t", newslip.vat_charge);
                    printf("\n\t\t\t\tPayment:                 %s\t\t\t", newslip.payment);
                    printf("\n\t\t\t     ---------------------------------- \t\t\t");
                    printf("\n\t\t\t\tPayable:                 %dTK\t\t\t", newslip.Shift_charge + newslip.vat_charge + newslip.fee);
                    printf("\n\n\t\t\t\tThank you, have a nice trip\t\t\t\n");
                    printf("\n\t\t\t\tToTal Ticket: %d\n", i);
            i++;
            flag = 0;
            fclose(file);
            continue;;
        }
    }

    if (flag == 1)
    {
        printf("\n\t\t\t    ---------------------------------- \t\t\t");
        printf("\n\n\t\t\t\tTransaction ID Not Found.....\n\n");
    }
    getchar();
    fclose(file);

    printf("\n\n\t\t\t\t");
    system("pause");
    system("cls");
}

//=================== END Function For Search SLIP ================================//

//=================== START Function For Delete SLIP ================================//



void delete_slip(){
    system("cls");
    FILE *file;
    struct slip newslip;
    int transaction_id;
    int flag = 0;
    file=fopen("slip.txt","r+");

    allheader();
    printf("\t\t\t\t     DELETE RECORD DATA");
    printf("\n\t\t\t\t     Enter \'0\' For Exit");
    fflush(stdin);
    printf("\n\n\n\t\t\t\tEnter Transaction ID: ");
    scanf("%d", &transaction_id);

    rewind(file);

    while(fread(&newslip,sizeof(newslip),1,file)==1){
        if(newslip.transaction_id==transaction_id){
            flag=1;
            
            system("cls");

            slipheader();
            printf("\n\t\t\t\t RECORD DATA SEARCH FOR %d", transaction_id);

                    printf("\n\n\t\t\t\tTransaction ID: %d\t\t\t", newslip.transaction_id);
                    printf("\n\t\t\t\tVehicle Class: %s\t\t\t", newslip.vehicle_class);
                    printf("\n\n\t\t\t\tFee:                   %dTK\t\t\t", newslip.fee);
                    printf("\n\t\t\t\tShift charge:            %1dTK\t\t\t", newslip.Shift_charge);
                    printf("\n\t\t\t\tVAT charge:              %1dTK\t\t\t", newslip.vat_charge);
                    printf("\n\t\t\t\tPayment:                 %s\t\t\t", newslip.payment);
                    printf("\n\t\t\t     ---------------------------------- \t\t\t");
                    printf("\n\t\t\t\tPayable:                 %dTK\t\t\t", newslip.Shift_charge + newslip.vat_charge + newslip.fee);
                    printf("\n\n\t\t\t\tThank you, have a nice trip\t\t\t");
            flag = 1;
            break;
        }

        else{
            flag=0;
        }
    }

    fclose(file);

    if(flag==1){
        printf("\n\n\t\t\t\tDo you want to delete the slip? y/n: ");
        char confirmation[5];

        fflush(stdin);
        scanf("%s", confirmation);
 
        if((strcmp(confirmation,"y")==0 || strcmp(confirmation,"Y")==0))
        {
            FILE *filew,*filer;
            int i=1;

            filew=fopen("slip.txt","r");
            filer=fopen("temp.txt","w");

            while(fread(&newslip,sizeof(newslip),1,filew)==1){
                if(newslip.transaction_id==transaction_id){
                    i=0;
                    continue;
                }
                else
                    fwrite(&newslip,sizeof(newslip),1,filer);
            }

            fclose(filew);
            fclose(filer);

            // Delete the original file and rename the temporary file
            remove("slip.txt");
            rename("temp.txt", "slip.txt");

            printf("\n\t\t\t     ---------------------------------- \t\t\t");
            printf("\n\t\t\t\tRecord Delete Successful....");
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
        }

        else if(flag==1 && (strcmp(confirmation,"n")==0 || strcmp(confirmation,"N")==0)){
            printf("\n\t\t\t     ---------------------------------- \t\t\t");
            printf("\n\t\t\t\tRecord has not been deleted....");
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
        }
    }
    else if(flag==0){
        printf("\n\t\t\t     ---------------------------------- \t\t\t");
        printf("\n\n\t\t\t\tTransaction ID Not Found.....");
        printf("\n\n\t\t\t\t");
        system("pause");
        system("cls");
    }
}
//=================== END Function For Delete SLIP ================================//

//=================== START Function For Add Collector ================================//

void input_addcollector()
{

    struct collector new_collector;
    new_collector = add_collector();
}
//=================== END Function For Add Collector ================================//

//=================== START Function For Display Collector List ================================//

void display_collector()
{
    FILE *file;
    file = fopen("collector.txt", "r");
  
    struct collector new_collector;
    allheader();
    int i = 1;
    while (fread(&new_collector, sizeof(new_collector), 1, file) == 1)
    {
        printf("\n\t\t\t\t     COLLECTOR LIST DATA%d\n", i++);
        printf("\n\t\t\t\tCollector ID    :       %d", new_collector.id);
        printf("\n\t\t\t\tUser Name       :       %s", new_collector.username);
        printf("\n\t\t\t\tPassword        :       %s", new_collector.password);
        printf("\n\t\t\t\tName            :       %s", strupr(new_collector.name));
        printf("\n\t\t\t\tGender          :       %s", strupr(new_collector.gender));
        printf("\n\t\t\t\tAddress         :       %s", new_collector.address);
        printf("\n\t\t\t\tPhone           :       %s", new_collector.phone);
        printf("\n\t\t\t\tEmail           :       %s\n\n", new_collector.email);
    }
    fclose(file);

    printf("\n\n\t\t\t\t");
    system("pause");
    system("cls");
}

//=================== END Function For Display Collector List ================================//

//=================== START Function For Delete Collector ================================//

void delete_collector()
{
    FILE *filew, *filer;
    int collector_id;
    struct collector new_collector;
    int found = 0;
    char confirm;

    allheader();
    printf("\t\t\t\t     DELETE RECORD DATA");
    printf("\n\n\t\t\t\tEnter \'0\' For Exit\t");
    printf("\n\t\t\t\tEnter Collector ID:");
    scanf("%d", &collector_id);

    if (collector_id == 0)
    {
        printf("\n\t\t\t\tExit Successfully...\n");
        printf("\n\n\t\t\t\t");
        system("pause");
        system("cls");
        return admin_fun();
    }

    filew = fopen("collector.txt", "r");

    while (fread(&new_collector, sizeof(new_collector), 1, filew) == 1)
    {
        if (new_collector.id == collector_id)
        {
            found = 1;
            printf("\n\t\t\t\tID:           %d", new_collector.id);
            printf("\n\t\t\t\tName:         %s", new_collector.name);
            printf("\n\t\t\t\tPhone:        %s", new_collector.phone);
            printf("\n\t\t\t\tEmail:        %s", new_collector.email);
            printf("\n\t\t\t\tAddress:      %s", new_collector.address);
            printf("\n\t\t\t\t-----------------------------\n");
            printf("\n\t\t\t\tDo you want to delete this record? (Y/N): ");
            scanf(" %c", &confirm);
            if (confirm == 'N' || confirm == 'n')
            {
                fclose(filew);
                printf("\n\t\t\t\tRecord Not Deleted.\n");
                printf("\n\n\t\t\t\t");
                system("pause");
                system("cls");
                return;
            }
            break;
        }
    }

    if (!found)
    {
        fclose(filew);
        printf("\n\t\t\t\tCollector ID Not Found\n");
        printf("\n\n\t\t\t\t");
        system("pause");
        system("cls");
    }
    else{
             rewind(filew);
    filer = fopen("temp.txt", "w");

    while (fread(&new_collector, sizeof(new_collector), 1, filew) == 1)
    {
        if (new_collector.id != collector_id)
        {
            fwrite(&new_collector, sizeof(new_collector), 1, filer);
        }
    }

    fclose(filew);
    fclose(filer);

    remove("collector.txt");
    rename("temp.txt", "collector.txt");
    printf("\n\t\t\t\tRecord Delete Success...\n");
    printf("\n\n\t\t\t\t");
    system("pause");
    system("cls");
    }

   
}
//=================== END Function For Delete Collector ================================//

//=================== START Function For Edit Collector ================================//

void edit_collector()
{
    FILE *filew, *filer;
    int collector_id;
    struct collector new_collector;
    int found = 0;
    allheader();
    printf("\t\t\t\t     EDIT RECORD DATA");
    printf("\n\n\t\t\t\tEnter \'0\' For Exit\t");
    printf("\n\n\t\t\t\tEnter Collector ID:");
    scanf("%d", &collector_id);

    filew = fopen("collector.txt", "r");

    filer = fopen("temp.txt", "w");


    while (fread(&new_collector, sizeof(struct collector), 1, filew) == 1)
    {
        if (new_collector.id == collector_id)
        {
            found = 1;
            system("cls");
           allheader();
            printf("\n\t\t\t\tDATA FOUND!.HERE IS PREVIOUS DATA:\n\n");
            printf("\n\n\t\t\t\tUser Name             :%s ",new_collector.username);
            printf("\n\t\t\t\tPassword              :%s ",new_collector.password);
            printf("\n\t\t\t\tPhone                 :%s ",new_collector.phone);
            printf("\n\t\t\t\tEmail                 :%s ",new_collector.email);
            printf("\n\t\t\t\tUser Address          :%s \n\n\n",new_collector.address);


            allheader();
            printf("\n\t\t\t\t     EDIT COLLECTOR DATA\n\n\n");
            printf("\n\t\t\t\tUser Name:");
            fflush(stdin);
            fgets(new_collector.username, sizeof(new_collector.username), stdin);
            new_collector.username[strlen(new_collector.username) - 1] = '\0'; // fgets takes an extra \n character as input

            printf("\n\t\t\t\tPassword:");
            fflush(stdin);
            fgets(new_collector.password, sizeof(new_collector.password), stdin);
            new_collector.password[strlen(new_collector.password) - 1] = '\0'; // fgets takes an extra \n character as input

            printf("\n\t\t\t\tPhone:");
            fflush(stdin);
            fgets(new_collector.phone, sizeof(new_collector.phone), stdin);
            new_collector.phone[strlen(new_collector.phone) - 1] = '\0'; // fgets takes an extra \n character as input

            printf("\n\t\t\t\tEmail:");
            fflush(stdin);
            fgets(new_collector.email, sizeof(new_collector.email), stdin);
            new_collector.email[strlen(new_collector.email) - 1] = '\0'; // fgets takes an extra \n character as input

            printf("\n\t\t\t\tAddress:");
            fflush(stdin);
            fgets(new_collector.address, sizeof(new_collector.address), stdin);
            new_collector.address[strlen(new_collector.address) - 1] = '\0'; // fgets takes an extra \n character as input
        }

        fwrite(&new_collector, sizeof(new_collector), 1, filer);
    }

    fclose(filew);
    fclose(filer);

    if (found)
    {
        remove("collector.txt");
        rename("temp.txt", "collector.txt");
        printf("\n\t\t\t\tRecord Updated\n");
        printf("\n\n\t\t\t\t");
        system("pause");
    }
    else
    {
        remove("temp.txt");
        printf("\n\t\t\t\tCollector ID Not Found\n");
    }
}

//=================== END Function For Edit Collector ================================//

void collector_forgate()
{
    FILE *filew, *filer;
    int collector_id;
    struct collector new_collector;
    int found = 0;
    allheader();
    printf("\t\t\t\t     RESET USER & PASS");
    printf("\n\t\t\t\t     ENTER \'0\' FOR EXIT\n");
    printf("\t\t\t\t-----------------------------\n");
    printf("\n\n\t\t\t\tEnter Collector ID:");
    scanf("%d", &collector_id);

    if (collector_id == 0)
    {
        printf("\n\t\t\t\t-----------------------------\n");
        printf("\t\t\t\tExit Success...\n\n");
        printf("\t\t\t\t");
        system("pause");
        system("cls");
        return main();
    }

    filew = fopen("collector.txt", "r");
    filer = fopen("temp.txt", "w");

    while (fread(&new_collector, sizeof(new_collector), 1, filew) == 1)
    {
        if (new_collector.id == collector_id)
        {
            found = 1;
            system("cls");
            allheader();
            printf("\t\t\t\t     RESET USER & PASS");
            printf("\n\t\t\t\t     ENTER \'0\' FOR EXIT\n");
            printf("\t\t\t\t-----------------------------\n");
            printf("\n\n\n\t\t\t\tID: %d", collector_id);
            printf("\n\t\t\t\tName: %s", new_collector.name);
            printf("\n\t\t\t\t-----------------------------\n");

            fflush(stdin);
            printf("\n\t\t\t\tUser-Name:\t");
            fgets(new_collector.username, sizeof(new_collector.username), stdin);
            new_collector.username[strlen(new_collector.username) - 1] = '\0'; // fgets takes an extra \n character as input

            printf("\n\t\t\t\tPassword:\t");
            fflush(stdin);
            fgets(new_collector.password, sizeof(new_collector.password), stdin);
            new_collector.password[strlen(new_collector.password) - 1] = '\0'; // fgets takes an extra \n character as input

            if(strcmp(new_collector.username,"0")==0 || strcmp(new_collector.password,"0")==0){
                printf("\n\t\t\t\tExit Successfuly...");
                system("pause");
                system("cls");
                fclose(filew);
                fclose(filer);
                return main();
            }
        }
        fwrite(&new_collector, sizeof(new_collector), 1, filer);
    }

    fclose(filew);
    fclose(filer);

    if (found)
    {
        remove("collector.txt");
        rename("temp.txt", "collector.txt");
        printf("\n\t\t\t\tRecord Updated\n");
    }
    else
    {
        remove("temp.txt");
        printf("\n\t\t\t\t-----------------------------\n");
        printf("\n\t\t\t\tCollector ID Not Found\n");
        printf("\n\n\t\t\t\t");
        system("pause");
        system("cls");
        return collector_forgate();
    }
}

void admin_forgate()
{
    FILE *file;
    file = fopen("admin.txt", "w+");

    struct admin_forgate new_admin;
    allheader();
    printf("\t\t\t\t     RESET USER & PASS");
    printf("\n\t\t\t\t     ENTER \'0\' FOR EXIT\n");
    printf("\t\t\t\t-----------------------------\n");
    printf("\n\t\t\t\tUser-Name:\t");
    fflush(stdin);
    fgets(new_admin.newuser, sizeof(new_admin.newuser), stdin);
    new_admin.newuser[strlen(new_admin.newuser) - 1] = '\0'; // fgets takes an extra \n character as input

    printf("\n\t\t\t\tPassword:\t");
    fflush(stdin);
    fgets(new_admin.newpass, sizeof(new_admin.newpass), stdin);
    new_admin.newpass[strlen(new_admin.newpass) - 1] = '\0'; // fgets takes an extra \n character as input

    
    fwrite(&new_admin, sizeof(new_admin), 1, file);
    fclose(file);

    if(strcmp(new_admin.newuser,"0")==0 || strcmp(new_admin.newpass,"0")==0){
    printf("\n\t\t\t\tExit Successfuly...\n");
    printf("\t\t\t\t-----------------------------\n");
    printf("\n\t\t\t\t");
    system("pause");
    system("cls");
  
    return main();
    }


    printf("\n\t\t\t\t-----------------------------\n");
    printf("\n\n\t\t\t\tData Update Success....\n\t\t\t\tas..user: %s   pass: %s", new_admin.newuser, new_admin.newpass);
    printf("\n\n\t\t\t\t");
    system("pause");
    system("cls");
}

// function for read admin.txt file

void read_admin()
{
    FILE *file;
    struct admin_forgate new_admin;
    file = fopen("admin.txt", "r");
    
        while (fread(&new_admin, sizeof(new_admin), 1, file) == 1)
        {
            printf("\n\t\t\t\t     ADMIN DATA\n\n\n");
            printf("\n\t\t\t\tUser-Name: %s", new_admin.newuser);
            printf("\n\t\t\t\tPassword: %s", new_admin.newpass);
        }
    
    fclose(file);
}

int forgate_password()
{
    system("cls");
    allheader();
    int tru_ref_code[] = {4545, 2416, 5548, 1122, 2420, 2217, 2544};
    int ref_code;
    printf("\n\n\t\t\t\tForgat Password\n");
    printf("\t\t\t\tEnter \'0\' For Exit.\n\n");
    printf("\n\n\t\t\t\t-----------------------------\n");
    printf("\n\t\t\t\tEnter Reference Code:");
    scanf("%d", &ref_code);

    if (ref_code == 0)
    {
        printf("\n\n\t\t\t\t-----------------------------\n");
        printf("\t\t\t\tExit Successful...\n\n");
        printf("\t\t\t\t");
        system("pause");
        system("cls");
        return main();
    }
    int i, flag = 0;
int length = sizeof(tru_ref_code) / sizeof(tru_ref_code[0]);

for (i = 0; i < length; i++)
{
    if (ref_code == tru_ref_code[i])
    {
        flag = 1;
        break;
    }
}

    if (flag == 1 && ref_code != 0)
    {
        int forgate;
        system("cls");
        allheader();
        printf("\n\n\t\t\t\t%d IS VALID REFER CODE\n",ref_code);
        printf("\n\n\t\t\t\t1.Collector Forgat Password\t\t\t");
        printf("\n\n\t\t\t\t2.Admin Forgat Password\t\t\t");
        printf("\n\t\t\t\t-----------------------------");
        printf("\n\n\t\t\t\tEnter Your Choice:");
        scanf("%d", &forgate);

        if (forgate == 1)
        {
            system("cls");
            printf("\n\n\t\t\t\tCollector Forgat Password\n\n");
            collector_forgate();
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
            return main();
        }

        else if (forgate == 2)
        {
            system("cls");
            admin_forgate();
            return main();
        }

        else if (forgate == 0)
        {
            printf("\n\n\t\t\t\t-----------------------------\n");
            printf("\t\t\t\tExit Success...\n\n");
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
            return main();
        }
        else
        {
            printf("\n\n\t\t\t\t-----------------------------\n");
            printf("\t\t\t\tWrong Choice\n\n");
            printf("\n\n\t\t\t\t");
            system("pause");
            system("cls");
            return forgate_password();
        }
    }
    else
    {
        printf("\n\n\t\t\t\t-----------------------------\n");
        printf("\t\t\t\tWrong Reference Code\n\n");
        printf("\t\t\t\t");
        system("pause");
        system("cls");
        return forgate_password();
    }
}
