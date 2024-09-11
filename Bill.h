#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int b;

struct Bill{
	int billNo;
	char custName[50];
	char mediName[50];
	int mediQty;
	int mediRate;
	int total;
	
};
struct Bill *bill=(struct Bill*)malloc(sizeof(Bill)*b);
FILE *bptr;


void billingInfo(){
	int customerId,i;
	char name[50];
	FILE *bptr;
    int id;
    printf("\n How Many Bills Do You want to Make: ");
    scanf("%d", &b);
    bptr = fopen("billData.txt", "a");
    if (bptr == NULL) {
        printf("\nError Occur.");
    }
    fptr = fopen("customerData.txt", "r");
	for (i = 0;i<b; i++) {
	    printf("\nEnter Bill no  Customer: ");
	    scanf("%d", &bill[i].billNo);
	    
	    printf("\nEnter ID for Search a Customer: ");
    	scanf("%d", &id);

	    char line[250]; 
		  while (fgets(line, 250, fptr) != NULL){
	        sscanf(line, "%d",&customerId);
	        printf("\n ID is :%d",customerId);
	        if (customerId == id) {
	        	sscanf(line, "%d%s", &customerId,name);
	            printf("%s", line); // Print the entire line containing customer data
	            strcpy(bill[i].custName,name);
	            break; 
	        }
	    }
	    printf("\nEnter Medicine Name: ");
	    scanf("%s", bill[i].mediName);
	    printf("\nEnter Medicine Quantity: ");
	    scanf("%d", &bill[i].mediQty);
	    printf("\nEnter Medicine Rate: ");
	    scanf("%d", &bill[i].mediRate);
	    bill[i].total=bill[i].mediQty*bill[i].mediRate;
	    printf("\n%d",bill[i].total);
	    
	    fprintf(bptr,"%d\t%s\t%s\t%d\t%d\t%d\n",bill[i].billNo,bill[i].custName,bill[i].mediName,bill[i].mediQty,bill[i].mediRate,bill[i].total);
	    
	}
	fclose(bptr);
	fclose(fptr);
}
