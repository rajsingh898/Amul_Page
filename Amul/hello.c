#include<stdio.h>
#include<stdlib.h>

struct object
{
 int id;
 float profit, weight;
}*objarray;

int n , sac_cap;
char *inputfilepath="knapsack.txt";
//char* string="printf this with \\t bell\n";
void calculatesack();
void sortobjects();

int main()
{
FILE * file;
int i;
 //printf(string);
if(file=fopen(inputfilepath, "r"))
{
     fscanf(file, "%d", &sac_cap);
fscanf(file, "%d", &n);
objarray=(struct object *)malloc(n*sizeof(struct object));
for(i=0;i<n;i++)
 {
 objarray[i].id=i+1;
fscanf(file, "%f%f", &objarray[i].profit, &objarray[i].weight);
}
for(printf("\n\t input object array\n"),i=0;i<n;i++)
 printf("Object %d=(%f, %f)\n", objarray[i].id, objarray[i].profit, objarray[i].weight);
 sortobjects();
 for(printf("\n\t sorted object array\n"),i=0;i<n;i++)
 printf("Object %d=(%f, %f)\n", objarray[i].id, objarray[i].profit, objarray[i].weight);
 calculatesack();

}
 else
 printf("File could not be opened\n");
return 0;
}

void sortobjects()
{
 int i, j;
 struct object keyobject;

 for(i=1;i<n;i++)
 {
keyobject=objarray[i];
 for(j=i-1;(j>=0)&&((objarray[j].profit/objarray[j].weight)< (keyobject.profit/keyobject.weight));j--)
 {
 objarray[j+1]=objarray[j];
 }
 objarray[j+1]=keyobject;
 }
}

/*
Show object id's selected with fractions and total profit calculated
*/
void calculatesack()
{
 int i;
float profit, ratio;
 for(i=0;i<n;i++){
if(sac_cap>0 && objarray[i].weight<=sac_cap)
 {
sac_cap=sac_cap - objarray[i].weight;
profit=profit + objarray[i].profit;

}

 else
 break;
 }

 if(i<n && sac_cap>0)
 {
ratio = sac_cap/objarray[i].weight;
profit = profit + objarray[i].profit*ratio;
 }
printf("%f",profit);

}


