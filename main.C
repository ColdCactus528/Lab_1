#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <malloc.h>

struct vector_3d_real
{
	float cor_1;
	float cor_2;
	float cor_3;
};

struct vector_3d_imag
{
	float cor_1_real;
	float cor_1_imag;
	float cor_2_real;
	float cor_2_imag;
	float cor_3_real;
	float cor_3_imag;
};

struct vector_3d_real* Vector_addition_real (struct vector_3d_real *vector_1, struct vector_3d_real *vector_2)
{
	struct vector_3d_real *vector_add = (struct vector_3d_real*) malloc(3*sizeof(float));
	float x1, y1, z1;
	float x2, y2, z2;
	float x3, y3, z3;

	printf("\n");
	printf("Vvod\n");
	printf("%f,%f,%f\n", vector_1->cor_1, vector_1->cor_2, vector_1->cor_3);
	printf("%f,%f,%f\n", vector_2->cor_1, vector_2->cor_2, vector_2->cor_3);

	printf("\n");

	x1 = vector_1->cor_1;
	y1 = vector_1->cor_2;
	z1 = vector_1->cor_3;

	printf("%f,%f,%f\n", x1, y1, z1);

	x2 = vector_2->cor_1;
	y2 = vector_2->cor_2;
	z2 = vector_2->cor_3;

	printf("%f,%f,%f\n", x2, y2, z2);

	x3 = x1+x2;
	y3 = y1+y2;
	z3 = z1+z2;

	printf("Vivod\n");
	printf("%f,%f,%f\n", x3, y3, z3);

	vector_add->cor_1 = x3;
	vector_add->cor_2 = y3;
	vector_add->cor_3 = z3;

	return(vector_add);
	free(vector_add);
}

struct vector_3d_real* Vector_scalar_multiplication_real (struct vector_3d_real *vector_1, struct vector_3d_real *vector_2)
{
	struct vector_3d_real *vector_scalar = (struct vector_3d_real*) malloc(3*sizeof(float));
	float x1, y1, z1;
	float x2, y2, z2;
	float x3, y3, z3;

	printf("%f,%f,%f\n", vector_1->cor_1, vector_1->cor_2, vector_1->cor_3);

	x1 = vector_1->cor_1;
	y1 = vector_1->cor_2;
	z1 = vector_1->cor_3;

	x2 = vector_2->cor_1;
	y2 = vector_2->cor_2;
	z2 = vector_2->cor_3;

	x3 = x1*x2;
	y3 = y1*y2;
	z3 = z1*z2;

	vector_scalar->cor_1 = x3;
	vector_scalar->cor_2 = y3;
	vector_scalar->cor_3 = z3;

	return(vector_scalar);
	free(vector_scalar);
}

struct vector_3d_real* Vector_vector_multiplication_real (struct vector_3d_real *vector_1, struct vector_3d_real *vector_2)
{
	struct vector_3d_real *vector_vector = (struct vector_3d_real*) malloc(3*sizeof(float));
	float x1, y1, z1;
	float x2, y2, z2;
	float i, j, k;

	printf("%f,%f,%f\n", vector_1->cor_1, vector_1->cor_2, vector_1->cor_3);

	x1 = vector_1->cor_1;
	y1 = vector_1->cor_2;
	z1 = vector_1->cor_3;

	x2 = vector_2->cor_1;
	y2 = vector_2->cor_2;
	z2 = vector_2->cor_3;

	i = y1*z2-y2*z1;
	j = x1*z2-x2*z1;
	k = x1*y2-y1*x2;

	vector_vector->cor_1 = i;
	vector_vector->cor_2 = -j;
	vector_vector->cor_3 = k;

	return(vector_vector);
	free(vector_vector);
}

struct vector_3d_imag* Vector_addition_imag(struct vector_3d_imag *vector_1, struct vector_3d_imag *vector_2)
{
	struct vector_3d_imag *vector_add = (struct vector_3d_imag*) malloc(6*sizeof(float));

	float x1_real, y1_real, z1_real;
	float x1_imag, y1_imag, z1_imag;
	float x2_real, y2_real, z2_real;
	float x2_imag, y2_imag, z2_imag;
	float x3_real, y3_real, z3_real;
	float x3_imag, y3_imag, z3_imag;

	x1_real = vector_1->cor_1_real;
	y1_real = vector_1->cor_2_real;
	z1_real = vector_1->cor_3_real;

	x1_imag = vector_1->cor_1_imag;
	y1_imag = vector_1->cor_2_imag;
	z1_imag = vector_1->cor_3_imag;

	x2_real = vector_2->cor_1_real;
	y2_real = vector_2->cor_2_real;
	z2_real = vector_2->cor_3_real;

	x2_imag = vector_2->cor_1_imag;
	y2_imag = vector_2->cor_2_imag;
	z2_imag = vector_2->cor_3_imag;

	x3_real = x1_real+x2_real;
	y3_real = y1_real+y2_real;
	z3_real = z1_real+z2_real;

	x3_imag = x1_imag+x2_imag;
	y3_imag = y1_imag+y2_imag;
	z3_imag = z1_imag+z2_imag;

	vector_add->cor_1_real = x3_real;
	vector_add->cor_2_real = y3_real;
	vector_add->cor_3_real = z3_real;

	vector_add->cor_1_imag = x3_imag;
	vector_add->cor_2_imag = y3_imag;
	vector_add->cor_3_imag = z3_imag;

	return(vector_add);
	free(vector_add);
}

struct vector_3d_imag* Vector_scalar_multiplication_imag(struct vector_3d_imag *vector_1, struct vector_3d_imag *vector_2)
{
	struct vector_3d_imag *vector_scalar = (struct vector_3d_imag*) malloc(6*sizeof(float));

	float x1_real, y1_real, z1_real;
	float x1_imag, y1_imag, z1_imag;
	float x2_real, y2_real, z2_real;
	float x2_imag, y2_imag, z2_imag;
	float x3_real, y3_real, z3_real;
	float x3_imag, y3_imag, z3_imag;

	x1_real = vector_1->cor_1_real;
	y1_real = vector_1->cor_2_real;
	z1_real = vector_1->cor_3_real;

	x1_imag = vector_1->cor_1_imag;
	y1_imag = vector_1->cor_2_imag;
	z1_imag = vector_1->cor_3_imag;

	x2_real = vector_2->cor_1_real;
	y2_real = vector_2->cor_2_real;
	z2_real = vector_2->cor_3_real;

	x2_imag = vector_2->cor_1_imag;
	y2_imag = vector_2->cor_2_imag;
	z2_imag = vector_2->cor_3_imag;

	x3_real = x1_real*x2_real - (x1_imag*x2_imag);
	y3_real = y1_real*y2_real - (y1_imag*y2_imag);
	z3_real = z1_real*z2_real - (z1_imag*z2_imag);

	x3_imag = x1_imag*x2_real + x2_imag*x1_real;
	y3_imag = y1_imag*y2_real + y2_imag*y1_real;
	z3_imag = z1_imag*z2_real + z2_imag*z1_real;

	vector_scalar->cor_1_real = x3_real;
	vector_scalar->cor_2_real = y3_real;
	vector_scalar->cor_3_real = z3_real;

	vector_scalar->cor_1_imag = x3_imag;
	vector_scalar->cor_2_imag = y3_imag;
	vector_scalar->cor_3_imag = z3_imag;

	return(vector_scalar);
	free(vector_scalar);
}

struct vector_3d_imag* Vector_vector_multiplication_imag(struct vector_3d_imag *vector_1, struct vector_3d_imag *vector_2)
{
	struct vector_3d_imag *vector_vector = (struct vector_3d_imag*) malloc(6*sizeof(float));

	float x1_real, y1_real, z1_real;
	float x1_imag, y1_imag, z1_imag;
	float x2_real, y2_real, z2_real;
	float x2_imag, y2_imag, z2_imag;
	float i_real, j_real, k_real;
	float i_imag, j_imag, k_imag;

	x1_real = vector_1->cor_1_real;
	y1_real = vector_1->cor_2_real;
	z1_real = vector_1->cor_3_real;

	x1_imag = vector_1->cor_1_imag;
	y1_imag = vector_1->cor_2_imag;
	z1_imag = vector_1->cor_3_imag;

	x2_real = vector_2->cor_1_real;
	y2_real = vector_2->cor_2_real;
	z2_real = vector_2->cor_3_real;

	x2_imag = vector_2->cor_1_imag;
	y2_imag = vector_2->cor_2_imag;
	z2_imag = vector_2->cor_3_imag;

	i_real = (y1_real*z2_real - z2_imag*y1_imag) - (y2_real*z1_real - z1_imag*y2_imag);
	j_real = (x1_real*z2_real - z2_imag*x1_imag) - (x2_real*z1_real - z1_imag*x2_imag);
	k_real = (x1_real*y2_real - y2_imag*x1_imag) - (x2_real*y1_real - y1_imag*x2_imag);

	i_imag = (y1_imag*z2_real + z2_imag*y1_real) - (y2_imag*z1_real + z1_imag*y2_real);
	j_imag = (x1_imag*z2_real + z2_imag*x1_real) - (x2_imag*z1_real + z1_imag*x2_real);
	k_imag = (x1_imag*y2_real + y2_imag*x1_real) - (x2_imag*y1_real + y1_imag*x2_real);

	vector_vector->cor_1_real = i_real;
	vector_vector->cor_2_real = -j_real;
	vector_vector->cor_3_real = k_real;

	vector_vector->cor_1_imag = i_imag;
	vector_vector->cor_2_imag = -j_imag;
	vector_vector->cor_3_imag = k_imag;

	return(vector_vector);
	free(vector_vector);
}

int main() 
{
	int n;
	int t;

	struct vector_3d_real *vector1_real = (struct vector_3d_real*) malloc(3*sizeof(float));
	struct vector_3d_real *vector2_real = (struct vector_3d_real*) malloc(3*sizeof(float));
	struct vector_3d_real *vector_add_real = (struct vector_3d_real*) malloc(3*sizeof(float)); 
	struct vector_3d_real *vector_scalar_mul_real = (struct vector_3d_real*) malloc(3*sizeof(float));
	struct vector_3d_real *vector_vector_mul_real =(struct vector_3d_real*) malloc(3*sizeof(float));

	struct vector_3d_imag *vector1_imag = (struct vector_3d_imag*) malloc(6*sizeof(float));
	struct vector_3d_imag *vector2_imag = (struct vector_3d_imag*) malloc(6*sizeof(float));
	struct vector_3d_imag *vector_add_imag = (struct vector_3d_imag*) malloc(6*sizeof(float)); 
	struct vector_3d_imag *vector_scalar_mul_imag = (struct vector_3d_imag*) malloc(6*sizeof(float));
	struct vector_3d_imag *vector_vector_mul_imag =(struct vector_3d_imag*) malloc(6*sizeof(float));

	printf("What type of numbers do you want to work?\n");
	printf("1. If they are real, press 1\n");
	printf("2. If they are complex, press 2\n");
	scanf("%d", &n);

	if (n == 1)
	{
		printf("Print coordinates of the first vector\n");
		scanf("%f,%f,%f", &vector1_real->cor_1, &vector1_real->cor_2, &vector1_real->cor_3);

		printf("Print coordinates of the second vector\n");
		scanf("%f,%f,%f", &vector2_real->cor_1, &vector2_real->cor_2, &vector2_real->cor_3);

		printf("\n");

		t = 1;
	}

	if (n == 2) 
	{	
		printf("Print REAL part of coordinates of the first vector\n");
		scanf("%f,%f,%f", &vector1_imag->cor_1_real, &vector1_imag->cor_2_real, &vector1_imag->cor_3_real);
		printf("Print IMAGINARY part of coordinates of the first vector\n");
		scanf("%f,%f,%f", &vector1_imag->cor_1_imag, &vector1_imag->cor_2_imag, &vector1_imag->cor_3_imag);

		printf("Print REAL part of coordinates of the second vector\n");
		scanf("%f,%f,%f", &vector2_imag->cor_1_real, &vector2_imag->cor_2_real, &vector2_imag->cor_3_real);
		printf("Print IMAGINARY part of coordinates of the second vector\n");
		scanf("%f,%f,%f", &vector2_imag->cor_1_imag, &vector2_imag->cor_2_imag, &vector2_imag->cor_3_imag);

		printf("\n");

		t = 2;
	}

	n = 4;
	while (n != 0)
	{	
		printf("What operation do you want to do?\n");
		printf("1. Vector addition, press 1\n");
		printf("2. Scalar multiplication of vectors, press 2\n");
		printf("3. Vector multiplication of vectors, press 3\n");
		printf("4. If want to exit, press 0\n");
		scanf("%d", &n);

		if ((n == 1) && (t == 1)) 
		{
			/*функция сложения векторов с вещ координатами*/
			vector_add_real = Vector_addition_real(vector1_real, vector2_real);
			printf("\n");
			printf("%f,%f,%f\n", vector_add_real->cor_1, vector_add_real->cor_2, vector_add_real->cor_3);
			printf("\n");
		}
		if ((n == 1) && (t == 2))
		{
			/*функция сложения векторов с комплексными координатами*/
			vector_add_imag = Vector_addition_imag(vector1_imag, vector2_imag);
			printf("\n");
			printf("Real part of cordinates\n");
			printf("%f,%f,%f\n", vector_add_imag->cor_1_real, vector_add_imag->cor_2_real, vector_add_imag->cor_3_real);
			printf("\n");
			printf("Imaginary part of cordinates\n");
			printf("%f,%f,%f\n", vector_add_imag->cor_1_imag, vector_add_imag->cor_2_imag, vector_add_imag->cor_3_imag);
			printf("\n");
		}
		if ((n == 2) && (t == 1)) 
		{
	 		/*функция скалярного умножения векторов с вещ координатами*/
			vector_scalar_mul_real = Vector_scalar_multiplication_real(vector1_real, vector2_real);
			printf("\n");
			printf("%f,%f,%f\n", vector_scalar_mul_real->cor_1, vector_scalar_mul_real->cor_2, vector_scalar_mul_real->cor_3);
			printf("\n");
		}
		if ((n == 2) && (t == 2)) 
		{
			/*функция скалярного умножения векторов с комплексными координатами*/
			vector_scalar_mul_imag = Vector_scalar_multiplication_imag(vector1_imag, vector2_imag);
			printf("\n");
			printf("Real part of cordinates\n");
			printf("%f,%f,%f\n", vector_scalar_mul_imag->cor_1_real, vector_scalar_mul_imag->cor_2_real, vector_scalar_mul_imag->cor_3_real);
			printf("\n");
			printf("Imaginary part of cordinates\n");
			printf("%f,%f,%f\n", vector_scalar_mul_imag->cor_1_imag, vector_scalar_mul_imag->cor_2_imag, vector_scalar_mul_imag->cor_3_imag);
			printf("\n");
		}
		if ((n == 3) && (t == 1)) 
		{
			/*функция векторного произведния векторов с вещ координатами*/
			vector_vector_mul_real = Vector_vector_multiplication_real(vector1_real, vector2_real);
			printf("\n");
			printf("%f,%f,%f\n", vector_vector_mul_real->cor_1, vector_vector_mul_real->cor_2, vector_vector_mul_real->cor_3);
			printf("\n");
		}
		if ((n == 3) && (t == 2)) 
		{
			/*функция векторного произведения векторов с комплексными координатами*/
			vector_vector_mul_imag = Vector_vector_multiplication_imag(vector1_imag, vector2_imag);
			printf("\n");
			printf("Real part of cordinates\n");
			printf("%f,%f,%f\n", vector_vector_mul_imag->cor_1_real, vector_vector_mul_imag->cor_2_real, vector_vector_mul_imag->cor_3_real);
			printf("\n");
			printf("Imaginary part of cordinates\n");
			printf("%f,%f,%f\n", vector_vector_mul_imag->cor_1_imag, vector_vector_mul_imag->cor_2_imag, vector_vector_mul_imag->cor_3_imag);
			printf("\n");
		}
	}	

	free(vector1_real);
	free(vector2_real);
	free(vector_add_real);
	free(vector_scalar_mul_real);
	free(vector_vector_mul_real);
	free(vector1_imag);
	free(vector2_imag);
	free(vector_add_imag);
	free(vector_scalar_mul_imag);
	free(vector_vector_mul_imag);
}
