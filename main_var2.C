#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

typedef struct Vector
{
	void* data;
	size_t dimension;
	size_t elem_size;	
}Vector;

typedef struct Complex
{
	double real;
	double imag;
}Complex;

typedef struct Real
{
	double real;
}Real;


void Error(const char* message)
{
	printf("ERROR\n");
	printf("%s",message);
	system("pause");
	exit(1);
}

Vector* Create_Vector(size_t dimension, size_t elem_size)
{
	Vector* vector = (Vector*)malloc(sizeof(Vector));
	if (vector == NULL)
		system("clear"), Error("Out of Memmory");
	vector->elem_size = elem_size;
	vector->dimension = dimension;
	vector->data = malloc(vector->dimension * elem_size);
	if (vector->data == NULL)
		system("clear"), Error("Out of Memmory");

	return vector;
}

Real* Create_Real()
{
	Real* re = (Real*)malloc(sizeof(Real));
	if (re == NULL)
		system("clear"), Error("Out of Memmory");
	return re;
}

Complex* Create_Complex()
{
	Complex* comp = (Complex*)malloc(sizeof(Complex));
	if (comp == NULL)
		system("clear"), Error("Out of Memmory");
	return comp;
}

void Set_Elem(Vector* vec, size_t index, void* value)
{
	if (index >= vec->dimension)
		system("clear"), Error("Buffer Overflow");

	void* ptr = (char*)vec->data + index * vec->elem_size;
	memmove(ptr, value, vec->elem_size);
}

Vector* Create_Vector_Real(size_t dimension)
{
	Real default_elem = {0};
	Vector* vec = Create_Vector(dimension, sizeof(Real));
	for (size_t i=0; i < vec->dimension; i++)
		Set_Elem(vec, i, &default_elem);
	return vec;
}

Vector* Create_Vector_Complex(size_t dimension)
{
	Complex default_elem = {0,0};
	Vector* vec = Create_Vector(dimension, sizeof(Complex));
		for (size_t i=0; i < (vec->dimension); i++)
		Set_Elem(vec, i, &default_elem);
	return vec;
}

Real* Get_Real(Vector* vec, size_t index)
{
	if(index>=vec->dimension)
		return NULL;
	return (Real*)vec->data+index;
}

Complex* Get_Complex(Vector* vec, size_t index)
{
	if(index>=vec->dimension)
		return NULL;
	return (Complex*)vec->data+index;
}

Complex* Mult_Complex(Complex* z1, Complex* z2)
{
	Complex* z = Create_Complex();
	z->real = z1->real*z2->real - z1->imag*z2->imag;
	z->imag = z1->real*z2->imag + z1->imag*z2->real;
	return z;
} 

Complex* Add_Complex(Complex* z1, Complex* z2)
{
	Complex* z = Create_Complex();
	z->real = z1->real + z2->real;
	z->imag = z2->imag + z1->imag;
	return z;
} 

Complex* Sub_Complex(Complex* z1, Complex* z2)
{
	Complex* z = Create_Complex();
	z->real = z1->real - z2->real;
	z->imag = z2->imag - z1->imag;
	return z;
} 

Real* Mult_Real(Real* r1, Real* r2)
{
	Real* r = Create_Real();
	r->real = r1->real*r2->real;
	return r;
}

Real* Add_Real(Real* r1, Real* r2)
{
	Real* r = Create_Real();
	r->real = r1->real + r2->real;
	return r;
}

Real* Sub_Real(Real* r1, Real* r2)
{
	Real* r = Create_Real();
	r->real = r1->real - r2->real;

	return r;
}

Vector* Vector_addition_real (Vector* vector_1, Vector* vector_2)
{			
	if(vector_1->dimension != vector_2->dimension) 
		system("clear"), Error("Vectors of different dimensions do not stack");

	Vector* vector_add = Create_Vector(vector_1->dimension, vector_1->elem_size);

	for(size_t i=0; i<vector_1->dimension; i++)
	{
		Real* sum = Add_Real(Get_Real(vector_1,i), Get_Real(vector_2,i));
		Set_Elem(vector_add, i, sum);
	}

	return vector_add;
}

Vector* Vector_addition_complex (Vector* vector_1, Vector* vector_2)
{

	if(vector_1->dimension != vector_2->dimension) 
		system("clear"), Error("Vectors of different dimensions do not stack");

	Vector* vector_add = Create_Vector(vector_1->dimension, vector_1->elem_size);

	for(size_t i=0; i<vector_1->dimension; i++)
	{
		Complex* sum = Add_Complex(Get_Complex(vector_1,i), Get_Complex(vector_2,i));
		Set_Elem(vector_add, i, sum);
	}

	return vector_add;
}

double Scalar_real(Vector* vec)
{
	double a = Get_Real(vec,0)->real;
	double b = Get_Real(vec,1)->real;
	double c = Get_Real(vec,2)->real;
	double Square = a + b + c;

	return Square; 
}

Complex* Scalar_complex(Vector* vec)
{
	Complex* a = Add_Complex(Get_Complex(vec,0), Get_Complex(vec,1));
	Complex* result = Add_Complex(a,Get_Complex(vec,2));

	return result;
}

double Vector_mul_scalar_real (Vector* vector_1, Vector* vector_2)
{
	double scalar;

	if(vector_1->dimension != vector_2->dimension) 
		system("clear"), Error("Vectors with different dimensions do not multiply");

	Vector* vector_scalar_mul = Create_Vector(vector_1->dimension, vector_1->elem_size);

	for(size_t i=0; i<vector_1->dimension; i++)
	{
		Real* scalar_mul = Mult_Real(Get_Real(vector_1,i), Get_Real(vector_2,i));
		Set_Elem(vector_scalar_mul, i, scalar_mul);
	}
	scalar = Scalar_real(vector_scalar_mul);

	return scalar;
}

Complex* Vector_mul_scalar_complex (Vector* vector_1, Vector* vector_2)
{
	if(vector_1->dimension != vector_2->dimension) 
		system("clear"), Error("Vectors with different dimensions do not multiply");

	Vector* vector_scalar_mul = Create_Vector(vector_1->dimension, vector_1->elem_size);

	for(size_t i=0; i<vector_1->dimension; i++)
	{
		Complex* scalar_mul = Mult_Complex(Get_Complex(vector_1,i), Get_Complex(vector_2,i));
		Set_Elem(vector_scalar_mul, i, scalar_mul);
	}
	Complex* scalar = Scalar_complex(vector_scalar_mul);

	return scalar;
}

Vector* Vector_mul_vector_real_3d(Vector* vector_1, Vector* vector_2)
{
	if ((vector_1->dimension == 3) && (vector_2->dimension == 3))
	{
		Vector* vector_vector_mul = Create_Vector(vector_1->dimension, vector_1->elem_size);

		Real* vector_mul_0 = Sub_Real(Mult_Real(Get_Real(vector_1,1), Get_Real(vector_2,2)), Mult_Real(Get_Real(vector_1,2), Get_Real(vector_2,1)));
		Set_Elem(vector_vector_mul, 0, vector_mul_0);
		Real* vector_mul_1 = Sub_Real(Mult_Real(Get_Real(vector_1,2), Get_Real(vector_2,0)), Mult_Real(Get_Real(vector_1,0), Get_Real(vector_2,2)));
		Set_Elem(vector_vector_mul, 1, vector_mul_1);
		Real* vector_mul_2 = Sub_Real(Mult_Real(Get_Real(vector_1,0), Get_Real(vector_2,1)), Mult_Real(Get_Real(vector_1,1), Get_Real(vector_2,0)));
		Set_Elem(vector_vector_mul, 2, vector_mul_2);
		return vector_vector_mul;
	}
	else
	{
		system("clear"), Error("Sorry, I have not such power }:-(");
		return NULL;
	}
}

Vector* Vector_mul_vector_complex_3d(Vector* vector_1, Vector* vector_2)
{
	if ((vector_1->dimension == 3) && (vector_2->dimension == 3))
	{
		Vector* vector_vector_mul = Create_Vector(vector_1->dimension, vector_1->elem_size);

		Complex* vector_mul_0 = Sub_Complex(Mult_Complex(Get_Complex(vector_1,1), Get_Complex(vector_2,2)), Mult_Complex(Get_Complex(vector_1,2), Get_Complex(vector_2,1)));
		Set_Elem(vector_vector_mul, 0, vector_mul_0);
		Complex* vector_mul_1 = Sub_Complex(Mult_Complex(Get_Complex(vector_1,2), Get_Complex(vector_2,0)), Mult_Complex(Get_Complex(vector_1,0), Get_Complex(vector_2,2)));
		Set_Elem(vector_vector_mul, 1, vector_mul_1);
		Complex* vector_mul_2 = Sub_Complex(Mult_Complex(Get_Complex(vector_1,0), Get_Complex(vector_2,1)), Mult_Complex(Get_Complex(vector_1,1), Get_Complex(vector_2,0)));
		Set_Elem(vector_vector_mul, 2, vector_mul_2);
		return vector_vector_mul;
	}
	else
	{
		system("clear"), Error("Sorry, I have not such power }:-(");
		return NULL;
	}
}

void ClearStdin()
{
	while (getchar() != '\n');
}

void Menu_type_of_vector_Real_or_Complex()
{
	system("clear");
	printf("Select what type of vector do you want to use.\n");
	printf("1. If you want to work with real coordinates, press 1\n");
	printf("2. If you want to work with complex coordinates, press 2\n");
}

#define Quantity_menu_items_R_C 2

void Menu_type_of_operation()
{
	system("clear");
	printf("Choose what type of operation do you want to do next\n");
	printf("1. Vector addition, press 1\n");
	printf("2. Scalar multiplication of vectors, press 2\n");
	printf("3. Vector multiplication of vectors, press 3\n");
	printf("4. Exit\n");
}

#define Quantity_menu_items_op 4

int Select_menu_item_R_C()
{
	int menu_item;
	int result;

	do
	{
		Menu_type_of_vector_Real_or_Complex();

		result = scanf("%d", &menu_item);
		!result ? scanf("%*s") : 0;
	} while (!result || menu_item > Quantity_menu_items_R_C || menu_item <= 0);

	ClearStdin();
	return menu_item;
}

int Select_menu_item_op()
{
	int menu_item;
	int result;

	ClearStdin();
	do
	{
		Menu_type_of_operation();
		result = scanf("%d", &menu_item);
		!result ? scanf("%*s") : 0;
	} while (!result || menu_item > Quantity_menu_items_op || menu_item <= 0); 

	ClearStdin();
	return menu_item;
}

Vector* Enter_coordinates_Real(const char* message, Vector* vec)
{
	Real* cor_0 = (Real*) malloc(sizeof(Real));
	Real* cor_1 = (Real*) malloc(sizeof(Real));
	Real* cor_2 = (Real*) malloc(sizeof(Real));

	printf("%s", message);
	printf("\n");
	scanf("%lf,%lf,%lf", &cor_0->real, &cor_1->real, &cor_2->real);
	Vector* vector = Create_Vector(vec->dimension, vec->elem_size);
	
	Set_Elem(vector, 0, cor_0);
	Set_Elem(vector, 1, cor_1);
	Set_Elem(vector, 2, cor_2);

	return vector;
}

Vector* Enter_coordinates_Complex(const char* message, Vector* vec)
{
	Complex* cor_0 = (Complex*) malloc(sizeof(Complex));
	Complex* cor_1 = (Complex*) malloc(sizeof(Complex));
	Complex* cor_2 = (Complex*) malloc(sizeof(Complex));

	printf("%s", message);
	printf("\n");

	printf("Print real part of coordinates\n");
	scanf("%lf,%lf,%lf", &cor_0->real, &cor_1->real, &cor_2->real);
	printf("Print imaginary part of coordinates\n");
	scanf("%lf,%lf,%lf", &cor_0->imag, &cor_1->imag, &cor_2->imag);

	Vector* vector = Create_Vector(vec->dimension, vec->elem_size);
	
	Set_Elem(vector, 0, cor_0);
	Set_Elem(vector, 1, cor_1);
	Set_Elem(vector, 2, cor_2);

	return vector;
}

int main()
{
	int menu_item_R_C;
	int menu_item_op;
	double scalar_real;
	Complex* scalar_complex = Create_Complex();
	Vector* vector_0_real = Create_Vector(3, sizeof(Real));
	Vector* vector_1_real = Create_Vector(3, sizeof(Real));
	Vector* vector_2_real = Create_Vector(3, sizeof(Real));
	Vector* vector_0_complex = Create_Vector(3, sizeof(Complex));
	Vector* vector_1_complex = Create_Vector(3, sizeof(Complex));
	Vector* vector_2_complex = Create_Vector(3, sizeof(Complex));

	menu_item_R_C = Select_menu_item_R_C();
	

	if(menu_item_R_C == 1)
	{
		vector_1_real = Enter_coordinates_Real("Print coordinates of first vector", vector_1_real);
		vector_2_real = Enter_coordinates_Real("Print coordinates of second vector", vector_2_real);

		do
		{
			menu_item_op = Select_menu_item_op();		

			if(menu_item_op == 1)
			{
				vector_0_real = Vector_addition_real(vector_1_real, vector_2_real);
				printf("Result\n");
				printf("%lf,%lf,%lf\n", Get_Real(vector_0_real,0)->real, Get_Real(vector_0_real,1)->real, Get_Real(vector_0_real,2)->real);
			}
			if(menu_item_op == 2)
			{
			    scalar_real = Vector_mul_scalar_real(vector_1_real, vector_2_real);
				printf("Result\n");
				printf("%lf\n", scalar_real);
			}
			if( menu_item_op == 3)
			{
				vector_0_real = Vector_mul_vector_real_3d(vector_1_real, vector_2_real);
				printf("Result\n");
				printf("%lf,%lf,%lf\n", Get_Real(vector_0_real,0)->real, Get_Real(vector_0_real,1)->real, Get_Real(vector_0_real,2)->real);
			}

		}while(menu_item_op != 4);

	}

	if(menu_item_R_C == 2)
	{
		vector_1_complex = Enter_coordinates_Complex("Print coordinates of first vector", vector_1_complex);
		vector_2_complex = Enter_coordinates_Complex("Print coordinates of second vector", vector_2_complex);

		do
		{
			menu_item_op = Select_menu_item_op();		

			if(menu_item_op == 1)
			{
				vector_0_complex = Vector_addition_complex(vector_1_complex, vector_2_complex);
				printf("Result\n");
				printf("Real part of coordinates\n");
				printf("%lf,%lf,%lf\n", Get_Complex(vector_0_complex,0)->real, Get_Complex(vector_0_complex,1)->real, Get_Complex(vector_0_complex,2)->real);
				printf("\n");
				printf("Imagine par of coordinates\n");
				printf("%lf,%lf,%lf\n", Get_Complex(vector_0_complex,0)->imag, Get_Complex(vector_0_complex,1)->imag, Get_Complex(vector_0_complex,2)->imag);
			}
			if(menu_item_op == 2)
			{
				scalar_complex = Vector_mul_scalar_complex(vector_1_complex, vector_2_complex);
				printf("Result\n");
				printf("Real part of coordinates\n");
				printf("%lf\n", scalar_complex->real);
				printf("\n");
				printf("Imagine par of coordinates\n");
				printf("%lf\n", scalar_complex->imag);
			}
			if( menu_item_op == 3)
			{
				vector_0_complex = Vector_mul_vector_complex_3d(vector_1_complex, vector_2_complex);
				printf("Result\n");
				printf("Real part of coordinates\n");
				printf("%lf,%lf,%lf\n", Get_Complex(vector_0_complex,0)->real, Get_Complex(vector_0_complex,1)->real, Get_Complex(vector_0_complex,2)->real);
				printf("\n");
				printf("Imagine par of coordinates\n");
				printf("%lf,%lf,%lf\n", Get_Complex(vector_0_complex,0)->imag, Get_Complex(vector_0_complex,1)->imag, Get_Complex(vector_0_complex,2)->imag);
			}

		}while(menu_item_op != 4);	
	}
	free(vector_0_real);
	free(vector_1_real);
	free(vector_2_real);
	free(vector_0_complex);
	free(vector_1_complex);
	free(vector_2_complex);
	free(scalar_complex);
}
