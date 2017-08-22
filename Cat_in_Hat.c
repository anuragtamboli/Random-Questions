/* Date 21 August 2017
	Auther: Anurag Tamboli
	anurag.tamboli@hotmail.com
	Question : A clever cat walks into a messy room which he needs to clean. Instead of doing the
	work alone, it decides to have its helper cats do the work. It keeps its (smaller) helper
	cats inside its hat. Each helper cat also has helper cats in its own hat, and so on.
	Eventually, the cats reach a smallest size. These smallest cats have no additional cats in
	their hats. These unfortunate smallest cats have to do the cleaning.
	The number of cats inside each (non-smallest) cat's hat is constant, N. The height of
	these cats-in-a-hat is 1/N+1 times the height of the cat whose hat they are in.
	The smallest cats are of height one; these are the cats that get the work done.
	All heights are positive integers.
	Given the height of the initial cat and the number of worker cats (of height one), find
	the number of cats that are not doing any work (cats of height greater than one) and
	also determine the sum of all the cats' heights (the height of a stack of all cats standing
	one on top of another).
	sample input/output
	Input : 216 125 	Output : 31 671
	Input : 1024 243 	Output : 121 3367
	Input : 5764801 1679616 	Output : 335923 30275911
*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>

int method( float var1, float var2); // Finding how many cats have hats or how many time it iterate till it reaches Cat with size 1 only
int function1(int var1, float var2); // Find number of cats in hat
void function2(int var1, int var2); // Number of cats whos are not working
void function3(float var1_x, float var2_n, float var3_y); // Find sum of heights of all cat
int main()
{
	float x, n_y; // x contain size of initial cat; n_y contain number of cat which have size 1
	int y,n; // It will contain number of times iteration happened
	printf("\n Enter fisrt input\n");
	scanf("%f",&x);
	printf("Enter 2nd input\n");
	scanf("%f",&n_y);
	y = method(x, n_y);
	if(y == 0)
	{
		printf("\n Please enter valid input\n");
		return(0);
	}
	n = function1(y, n_y);
	function2(n , y); // Function for finding Cats who are not working
	function3(x, n, y);
}

void function3(float var1_x, float var2_n, float var3_y)
{
	float i, temp1=0;
	for(i = 0; i<=var3_y ; i++)
	{
		temp1 += var1_x*(pow(var2_n, i))/(pow((var2_n+1), i));
	}
	printf("\n Heigths of all cats %d",(int)temp1);
}

void function2(int var1, int var2)
{
	int i, temp1=0;
	for(i =0; i<= var2-1; i++)
	{
		temp1 += pow (var1, i);
	}
	printf("\n Cat who are not working %d", temp1);
}

int function1(int var1, float var2)
{
	float temp1=0;
	int num=1;
	while(var2 > temp1)
	{
		temp1 = pow( num, var1);
		if(temp1 == var2)
		{
			return(num);
		}
		num++;
	}
}

int method( float var1, float var2)
{
	int y, n=2;
	float temp1=0, temp2=0, temp3=0;
	while(log(var1)>log(n+1))
	{
		temp1 = log(var1)/log(n+1);
		temp2 = modff( temp1, &temp3);
		if(temp2 == 0)
		{
			return temp1;
		}
		else
		{
			n++;
		}
	}
	return 0;
}
