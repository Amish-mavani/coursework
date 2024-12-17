#include <stdio.h>
int main() {
	int physicalmemorysize=0,pagesize=0,i=0;
	printf("Enter the physical memory size :-");
	scanf("%d",&physicalmemorysize);
	printf("Enter the page size :-");
	scanf("%d",&pagesize);
	int nopages=physicalmemorysize/pagesize;
	int processno=1;
	int memory[nopages];
	int process[100];
	while(1) {
		int choice=1,process_size=0;
		printf(" \n Which of the following operation do you want to execute :- \n");
		printf("1.Enter the process to be inserted into the memory. \n");
		printf("2.Enter the process to be found. \n");
		printf("3.Enter the process to be deleted from the memory. \n");
		printf("4.EXIT \n");
		scanf("%d",&choice);
		if(choice==1) {
			printf("Enter the size of process %d :-",processno);
			scanf("%d",&process_size);
			process[processno]=process_size;
			int entered=0;
			for(i=0; i<nopages; i+=1) {
				if(process_size==0) {
					entered=1;
					printf("Process entered into the MEMORY SUCCESSFULLY. \n");
					break;
				}
				if(memory[i]==0) {
					memory[i]=processno;
					process_size-=pagesize;
				}

			}
			if(entered==0) {
				printf("INSUFFICIENT MEMORY. \n");
			}
			processno+=1;
		} else if(choice==2) {
			int processno1=1,byteno=0,found=0;
			printf("Enter the process no. to be found :-");
			scanf("%d",&processno1);
			printf("Enter the byte to be found :-");
			scanf("%d",&byteno);
			if(processno1>processno) {
				printf("NO such process exists. \n");
			} else if(byteno>process[processno1]) {
				printf("NO such byte exists. \n");
			} else {
				for(i=0; i<nopages; i+=1) {
					if(memory[i]==processno1) {
						byteno-=pagesize;
					}
					if(byteno<=pagesize) {
						printf("The Required Bit FOUND at %d frame and %d offset.\n",i,byteno-1);
						found=1;
					}

				}
				if(found==0) {
					printf("REQUIRED BYTE NOT FOUND. \n");
				}
			}
		} else if(choice==3) {
			int processno1=1,found=0;
			printf("Enter the process no. to be deleted :-");
			scanf("%d",&processno1);
			if(processno1>processno)

			{
				printf("NO such process exists. \n");
			} 
			else {
				for(i=0; i<nopages; i+=1) {
					if(memory[i]==processno1) {
						memory[i]=0;
					}
				}
				if(found==0) {
					printf("Process DELETED SUCCESSFULLY. \n");
				}
			}
		} 
	}
	return 0;
