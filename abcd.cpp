#include<stdio.h>  // avoid to  global variable 

  void display(int x[], int i, int size)
  {
  	       if(i<size)
  	       {
  	       	    printf("%d\t",x[i]);
  	       	    i++;
  	       	    display(x,i,size);
			 }
  }

 void sorting(int i, int j, int size,int a[],int f )
 {
 	
 	    if(i<size&&f)
 	    {
 	    	j=i+1;
 	    	//  printf(" i =%d\n",i);
 	    	 sorting(i,j,size,a,0); 
		 }else if(j<size)
		 {
		 	  if(a[i]>a[j])
		 	  {
		 	  	 int temp=a[i];
		 	  	 a[i]=a[j];
		 	  	 a[j]=temp;
			   }
		 	 // printf(" j =%d\n",j);
		 	  j++;
		 	   sorting(i,j,size,a,0); 
		 }else{
		 	i++;
		 	
		 	  if(i==5)
		 	  {
		 	  	  display(a,0,size);
			   }
		 	 sorting(i,j,size,a,1); 
		 }
		 
 }
 int main()
 {
 	  int a[5];
 	  for(int i=0;i<5;i++)
 	  {
 	  	 scanf("%d",&a[i]);
	   }
 	 
 	 sorting(0,0,5,a,1);
 }
