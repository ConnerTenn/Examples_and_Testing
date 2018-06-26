
#include <iostream>

#define INIT { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 } }
#define OUT(a) std::cout << (int)(a) << "\n"

const int X = 2, Y = 3;

void test1(int in[3][5])
{
	std::cout << "normal array access on [3][5]\n";
	OUT(in[X][Y]);
}

void test2(int **in)
{
	std::cout << "normal array access on **\n";
	OUT(in[X][Y]);
}

int main()
{
	int array1[3][5] = INIT;
	
	int **array2 = new int *[3];
	for (int i = 0; i < 3; i++)
	{
		array2[i] = new int[5];
		for (int j = 0; j < 5; j++)
		{
			array2[i][j] = 5*i + j+1;
		}
	}
	
	
	//does work
	test1(array1);
	
	//doesnt work
	//test1(array2);
	
	//doesnt work
	//test2((int **)array1);
	
	//does work
	test2(array2);
	
	std::cout << "array 1 by calculation\n";
	int *arrayt1 = (int *)array1 + X*5 + Y;
	OUT(*arrayt1);
	
	std::cout << "array 1 by pointer access\n";
	int *arrayt2 = *(array1+X) + Y;
	OUT(*arrayt2);
	
	//array2 is calcualted implicitly in this way
	std::cout << "array 1 by calculation with bytes\n";
	int *arrayt3 = (int *)( (char *)array1 + X*sizeof(int[5]) + Y*sizeof(int));
	OUT(*arrayt3);
	
	//doesnt work
	//int *arrayt4 = (int *)array2 + X*5 + Y;
	//OUT(*arrayt4);
	
	std::cout << "array 2 by pointer access\n";
	int *arrayt5 = *(array2+X) + Y;
	OUT(*arrayt5);
	
}