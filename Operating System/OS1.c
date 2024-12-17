#include<stdio.h>
void bestFit(int bsize[], int nb, int psize[], int np)
{
int i,j,sub,low=999;
static int barr[10],parr[10];
for(i = 0; i &lt; 10; i++)
{
barr[i] = 0;
parr[i] = -1;
}
for(i=0; i&lt;np; i++)
{
for(j=0; j&lt;nb; j++)
{
if(barr[j]!=1)
{
sub = bsize[j]-psize[i];
if(sub&gt;=0)
{
if(low&gt;sub)
{
parr[i] = j;
low = sub;

}
}
}
}
barr[parr[i]]=1;
low=1000;
}
printf(&quot;\nProcess_no\tProcess_size\tBlock_no\tBlock_size&quot;);
for(i=0;i&lt;=np;i++)
{
printf(&quot;\n%d\t\t%d\t\t&quot;,i,psize[i]);
if(parr[i]!=-1)
{

printf(&quot;%d\t\t\t%d&quot;,parr[i],bsize[parr[i]]);

}
}
}

void firstFit(int bsize[], int nb, int psize[], int np)
{
int i,j;
static int barr[10],parr[10];
for(i = 0; i &lt; 10; i++)
{
barr[i] = 0;
parr[i] = -1;
}
for(i=0;i&lt;np;i++)
{

for(j=0;j&lt;nb;j++)
{
if(bsize[j] &gt;= psize[i] &amp;&amp; barr[j]==0)
{
parr[i] = j;
barr[j] = 1;
break;
}

}
}
printf(&quot;\nProcess_no\tProcess_size\tBlock_no\tBlock_size&quot;);
for(i=0;i&lt;=np;i++)
{
printf(&quot;\n%d\t\t%d\t\t&quot;,i,psize[i]);
if(parr[i]!=-1)
{

printf(&quot;%d\t\t\t%d&quot;,parr[i],bsize[parr[i]]);

}
}
}

void worstFit(int bsize[], int nb, int psize[], int np)
{
int i,j,sub,low=0;
static int barr[10],parr[10];
for(i = 0; i &lt; 10; i++)
{
parr[i] = -1;

barr[i] = 0;
}
for (i=0; i &lt; np; i++)
{
for(j = 0; j &lt; nb; j++)
{
if(bsize[j] &gt;= psize[i] &amp;&amp; barr[j]==0)
{

sub = bsize[j]-psize[i];
if(sub&gt;low)
{
parr[i] = j;
low = sub;
}

}
}
barr[parr[i]]=1;
low=1;
}

printf(&quot;\nProcess No.\tProcess Size\tBlock no.\tblock Size\n&quot;);
for (int i = 0; i &lt; np; i++)
{
printf(&quot;%d \t\t %d \t\t&quot;, i, psize[i]);
if (parr[i] != -1)
{
printf(&quot;%d\t\t%d\t\t\n&quot;,parr[i],bsize[parr[i]]);

}
}
}

int main()
{
int az,i,bsize[20],nb,np,psize[20];
printf(&quot;enter the num. of memory block = &quot;);
scanf(&quot;%d&quot;,&amp;nb);
printf(&quot;enter the size of \n&quot;);
for(i=0;i&lt;nb;i++)
{
printf(&quot;momory block %d = &quot;,i);
scanf(&quot;%d&quot;,&amp;bsize[i]);
}
printf(&quot;enter the num of process = &quot;);
scanf(&quot;%d&quot;,&amp;np);
printf(&quot;enter the size of \n&quot;);
for(i=0;i&lt;np;i++)
{
printf(&quot; process %d = &quot;,i);
scanf(&quot;%d&quot;,&amp;psize[i]);
}

printf(&quot;select memory allocation &quot;);
printf(&quot; \n1. Best fit\n2. First fit\n3. Worst fit&quot;);
printf(&quot;\nenter the value : &quot;);

scanf(&quot;%d&quot;,&amp;az);

switch(az)
{
case 1:
bestFit(bsize, nb, psize, np);
break;

case 2:
firstFit(bsize, nb, psize, np);
break;

case 3:
worstFit(bsize, nb, psize, np);
break;
}
return 0;
}
