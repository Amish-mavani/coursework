#include<stdio.h>
int main() {
int physicalmemorysize=0,pagesize=0,i=0;
printf(&quot;Enter the physical memory size :-&quot;);
scanf(&quot;%d&quot;,&amp;physicalmemorysize);
printf(&quot;Enter the page size :-&quot;);
scanf(&quot;%d&quot;,&amp;pagesize);
int nopages=physicalmemorysize/pagesize;
int processno=1;
int memory[nopages];
int process[100];
while(1) {
int choice=1,process_size=0;
printf(&quot; \n Which of the following operation do you want to execute :- \n&quot;);
printf(&quot;1.Enter the process to be inserted into the memory. \n&quot;);
printf(&quot;2.Enter the process to be found. \n&quot;);
printf(&quot;3.Enter the process to be deleted from the memory. \n&quot;);
printf(&quot;4.EXIT \n&quot;);
scanf(&quot;%d&quot;,&amp;choice);
if(choice==1) {
printf(&quot;Enter the size of process %d :-&quot;,processno);
scanf(&quot;%d&quot;,&amp;process_size);
process[processno]=process_size;
int entered=0;
for(i=0; i&lt;nopages; i+=1) {
if(process_size==0) {
entered=1;
printf(&quot;Process entered into the MEMORY SUCCESSFULLY.

\n&quot;);

break;
}
if(memory[i]==0) {
memory[i]=processno;
process_size-=pagesize;
}
}
if(entered==0) {
printf(&quot;INSUFFICIENT MEMORY. \n&quot;);
}
processno+=1;
} else if(choice==2) {

int processno1=1,byteno=0,found=0;
printf(&quot;Enter the process no. to be found :-&quot;);
scanf(&quot;%d&quot;,&amp;processno1);
printf(&quot;Enter the byte to be found :-&quot;);
scanf(&quot;%d&quot;,&amp;byteno);
if(processno1&gt;processno) {
printf(&quot;NO such process exists. \n&quot;);
} else if(byteno&gt;process[processno1]) {
printf(&quot;NO such byte exists. \n&quot;);
} else {
for(i=0; i&lt;nopages; i+=1) {
if(memory[i]==processno1) {
byteno-=pagesize;
}
if(byteno&lt;=pagesize) {
printf(&quot;The Required Bit FOUND at %d frame and %d

offset.\n&quot;,i,byteno-1);

found=1;
}
}
if(found==0) {
printf(&quot;REQUIRED BYTE NOT FOUND. \n&quot;);
}
}
} else if(choice==3) {
int processno1=1,found=0;
printf(&quot;Enter the process no. to be deleted :-&quot;);
scanf(&quot;%d&quot;,&amp;processno1);
if(processno1&gt;processno)
{
printf(&quot;NO such process exists. \n&quot;);
}
else {
for(i=0; i&lt;nopages; i+=1) {
if(memory[i]==processno1) {
memory[i]=0;
}
}
if(found==0) {
printf(&quot;Process DELETED SUCCESSFULLY. \n&quot;);
}
}
}
}
return 0;
