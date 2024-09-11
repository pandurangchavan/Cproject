#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"customerMenu.h"
#include"medicineMenu.h"
//#include"Supplier.h"
#include"Bill.h"
int main(){
	int ch;
	do{
		printf("\n1.Customer Menu\n2.Medicine Menu\n3.Supplier Menu\n4.Billing\n5.About\n6.Exit");
		printf("\nEnter Your Choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				customerMenu();
			break;
			case 2:
				medicineMenu();
			break;
			case 3:
//				supplierMenu();
			break;
			case 4:
				billingInfo();
			break;
			case 5:
//				aboutInfo();
			break;
			case 6:
				exit(0);
			break;
			default:
				printf("\nWrong Choice \n Please Enter Right Option:");
		}
		
	}while(1);
	
	return 0;
}

