#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
struct Customer{
	int custId;
	char custName[50];
	char city[50];
	char mobNo[15];
	char email[50];
};
//---------------------------------------------------------------------------------------------------------------
struct Customer *cust=(struct Customer*)malloc(sizeof(Customer)*n);
FILE *fptr;
//-----------------------------------------------------------------------------------------------------------

void custEntry( ){
    int n,ch;
    int i;
    
    FILE *fptr;

    printf("\n How Many Customers Do You want to add: ");
    scanf("%d", &n);

    fptr = fopen("customerData.txt", "a");
    if (fptr == NULL) {
        printf("\n Error Occurred ");
        return;
    }

    for (i = 0; i < n; i++) {
    	
        printf("\nEnter Customer Id: ");
        scanf("%d", &cust[i].custId);
        printf("\nEnter Customer Name: ");
        scanf("%s", cust[i].custName);
        printf("\nEnter Customer City: ");
        scanf("%s", cust[i].city);
        printf("\nEnter Customer Contact: ");
        scanf("%s", cust[i].mobNo);
        printf("\nEnter Customer Email: ");
        scanf("%s", cust[i].email);

        fprintf(fptr, "%d\t%s\t%s\t%s\t%s\t\n", cust[i].custId, cust[i].custName, cust[i].city, cust[i].mobNo, cust[i].email);
    }

    fclose(fptr);
}

void searchId() {
    FILE *fptr;
    int id, flag = 0;
    fptr = fopen("customerData.txt", "r");
    if (fptr == NULL) {
        printf("\nError Occur.");
    }

    printf("\nEnter ID for Search a Customer: ");
    scanf("%d", &id);

    char line[100]; 
    while (fgets(line, 100, fptr) != NULL) {
        int customerId;
        sscanf(line, "%d", &customerId);
        if (customerId == id) {
        	printf("\n Id is:",id);
        	printf("\n Id is:",customerId);
            flag = 1;
            printf("\nCustomer Found:\n");
            printf("%s", line); // Print the entire line containing customer data
            break; 
        }
    }
	
    if (!flag) {
        printf("\nCustomer not Found\n");
    }
    fclose(fptr);
}

void searchName() {
    FILE *fptr;
    fptr = fopen("customerData.txt", "r");
    
    if (fptr == NULL) {
        printf("\n Error Occur.");
    }
    printf("\nEnter Name for Search a Customer: ");
    int flag = 0; 
    char name[50];
    scanf("%s",&name);

    char line[100]; 
    while (fgets(line, 100, fptr) != NULL) {
        char customerName[50];
        int id;
        	
		sscanf(line, "%d%s",&id, customerName);
        if (strcmp(customerName ,name)==0) {
            flag = 1;
            printf("\nCustomer Found:\n");
            printf("%s", line); // Print the entire line containing customer data
            break; 
        }
    }

    if (!flag) {
        printf("\nCustomer not Found\n");
    }
    fclose(fptr);
}

void custList(){
    fptr = fopen("customerData.txt", "r");
	char line[200];
	while(fgets(line,100,fptr)!=NULL){
		printf("\n%s",line);
		line[0]='\0';
	}
}
void update() {
    FILE *fptr;
    int id, value, flag = 0;
    fptr = fopen("customerData.txt", "r+");
    char line[250];
    char temp[250];
    
    if (fptr == NULL) {
        printf("File not found.\n");
        return;
    }

    printf("\nEnter new value for Customer: ");
    scanf("%d", &value);
    printf("Enter ID of Customer: ");
    scanf("%d", &id);

    while (fgets(line, sizeof(line), fptr) != NULL) {
        int customerId;
        long pos = ftell(fptr);

        sscanf(line, "%d", &customerId);
        
        if (customerId == id) {
            fseek(fptr, pos - strlen(line)-1, SEEK_SET);
            sprintf(temp, "%d", value);
            fprintf(fptr, "%s", temp);
            flag = 1;
            printf("Customer Found:\n");
            printf("%s", line); // Print the entire line containing customer data
            break;
        }
    }
    rewind(fptr);
    if (flag == 0) {
        printf("Customer with ID %d not found.\n", id);
    }

    printf("\nUpdated File Data:\n");

    fclose(fptr);

    fptr = fopen("customerData.txt", "r");

    while (fgets(line, sizeof(line), fptr) != NULL)
        printf("%s", line);

    fclose(fptr);
}

void customerMenu(){
	int ch;
	printf("\n\tCUSTOMER MENU");
	do{
		printf("\n1.Entry Customer\n2.Search id\n3.Search Name\n4.Display Customer\n5.Update ");
		printf("\nEnter Your Choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nok");
				custEntry();
			break;
			case 2:
				printf("\nok");
				searchId();
			break;
			case 3:
				printf("\nok");
				searchName();
			break;
			case 4:
				printf("\nok");
				custList();
			break;
			case 5:
				printf("\nok");
				update();
//				listOfCustomer();
			break;
			default:
				printf("\nWrong Choice \n Please Enter Right Option:");
			}
	}while(1);
}




//void update(){
//	FILE *fptr;
//    int id, flag = 0;
//    fptr = fopen("customerData.txt", "r+");
//    char str[80];
//  
//
//   printf("Original File Data:\n");
//   while(fgets(str,80,fptr)!=NULL)
//    printf("%s", str);
//   //getch();
//   
//   printf("\n\nEnter new Id for Customer:");
//   scanf("%d", &id);
//      
//   printf("Updated File Data:\n\n");
//   
//   itoa(id,str, 10);
//      //convert int to string; fputs() write "string" to fp
//   
//   fseek(fptr,0,SEEK_SET); //set the pointer to position no. 4
//   
//   fputs(str, fptr);
//   fseek(fptr,0,SEEK_CUR);  //write string to current position of fp
//   fclose(fptr);
//   
//   fptr = fopen("customerData.txt","r");
//
//   while(fgets(str,80,fptr)!=NULL)
//    printf("%s", str);
//    
//   fclose(fptr);
//}
