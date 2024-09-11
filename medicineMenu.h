#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ch1,m;
struct Medicine{
	int id; 
	char mediName[50];
	int rack;
//	int cabNit;
	int quantity;
	int sale;
	int total;
	int unit;
	int cost;
	int profit;
	int buy;
//	int qty;
	char purDate[50];
	char expDate[50];
	char manuDate[50];
	int billNo;
	char compName[50];
	char suppName[50];
};
//---------------------------------------------------------------------------------------------------------------
struct Medicine  *med=(struct Medicine*)malloc(sizeof(Medicine)*m);
FILE *mptr;
//-----------------------------------------------------------------------------------------------------------

void mediEntry(){
	int i;
	printf("\n How Many Medicine Do You want to add:");
	scanf("%d",&m);
		
    mptr = fopen("medicineData.txt", "a");
    if (mptr == NULL) {
        printf("Error opening the file.\n");
    }
    for (i =0; i<m; i++) {
//        printf("\nEnter ID, Medicine Name, Rack No , Quantity, Sale,Total,Unit,Cost,Profit,Buy,Quantity: ");
//       scanf("%d%s%d%d%d%d%d%d%d%d%s%s%s%d%s%s", &med[i].id,med[i].mediName,&med[i].rack,&med[i].quantity,&med[i].sale,&med[i].total,&med[i].unit,&med[i].cost,&med[i].profit,&med[i].buy,med[i].purDate,med[i].expDate,med[i].manuDate,&med[i].billNo,med[i].compName,med[i].suppName);
	   
	    printf("\n Enter Id:");//101
	    scanf("%d",&med[i].id);
		printf("\n Enter Medicine Name:");//abc
	    scanf("%s",med[i].mediName);
	    printf("\n Enter Rack No:");//10
	    scanf("%d",&med[i].rack);
	    printf("\n Enter Quantity:");//100
	    scanf("%d",&med[i].quantity);
	    printf("\n Enter Sale Initiallay Zero:");//initilally zero
	    scanf("%d",&med[i].sale);
	    printf("\n Enter Total:");
	    scanf("%d",&med[i].total);
	    printf("\n Enter Unit:");//10ml or daily 2
	    scanf("%d",&med[i].unit);
	    printf("\n Enter Cost:"); //per Quantity 50 
	    scanf("%d",&med[i].cost);
	    //calculate Profit    initially profit zero after sale profit will update
	    printf("\n Enter Profit Intially 0:");
	    scanf("%d",&med[i].profit);
	    printf("\n Enter Expiry Date:");
	    scanf("%s",med[i].expDate);
	    printf("\n Enter Manufacture Date:");
	    scanf("%s",med[i].manuDate);
	    printf("\n Enter Company Name:");
	    scanf("%s",med[i].compName);
	    printf("\n Enter Supplier Name:");
	    scanf("%s",med[i].suppName);
	    
        fprintf(mptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\n", med[i].id,med[i].mediName,med[i].rack,med[i].quantity,med[i].sale,med[i].total,med[i].unit,med[i].cost,med[i].profit,med[i].expDate,med[i].manuDate,med[i].compName,med[i].suppName);
    }
    fclose(mptr);
}

void mediSearch() {
    FILE *fptr;
    int id, flag = 0;
    fptr = fopen("medicineData.txt", "r");
    if (fptr == NULL) {
        printf("\nError Occur.");
    }

    printf("\nEnter ID for Search a Customer: ");
    scanf("%d", &id);

    char line[100]; 
    while (fgets(line, 100, fptr) != NULL) {
        int mediId;
        sscanf(line, "%d", &mediId);
        if (mediId == id) {
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
void stock(){
    mptr = fopen("medicineData.txt", "r");
	char line[250];
	while(fgets(line,250,mptr)!=NULL){
		printf("\n%s",line);
		line[0]='\0';
	}
}
void medicineMenu(){
	printf("\n\t Medicine Menu");
	do{
		printf("\n1.Medical Entry\n2.Search id\n3.Update Stock\n4.Medical Sale\n5.Stock ");
		printf("\nEnter Your Choice:");
		scanf("%d",&ch1);
		switch(ch1){
			case 1:
				mediEntry();
			break;
			case 2:
				mediSearch();
			break;
			case 3:
				printf("\nok");
//				updateStock();
			break;
			case 4:
				printf("\nMedical Sale function Call");
			break;
			case 5:
				stock();
			break;
			default:
				printf("\nWrong Choice \n Please Enter Right Option:");
			}
	}while(1);
}


