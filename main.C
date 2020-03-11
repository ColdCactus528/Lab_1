#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct vector_3d_real
{
	double cor_1;
	double cor_2;
	double cor_3;
};

struct vector_3d_imag
{
	double cor_1_real;
	double cor_1_imag;
	double cor_2_real;
	double cor_2_imag;
	double cor_3_real;
	double cor_3_imag;
};

struct vector_3d_scalar_imag
{
	double real;
	double imag;
};

struct vector_3d_real* Vector_addition_real (struct vector_3d_real *vector_1, struct vector_3d_real *vector_2)
{
	struct vector_3d_real *vector_add = (struct vector_3d_real*) malloc(3*sizeof(double));
	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;

	x1 = vector_1->cor_1;
	y1 = vector_1->cor_2;
	z1 = vector_1->cor_3;

	x2 = vector_2->cor_1;
	y2 = vector_2->cor_2;
	z2 = vector_2->cor_3;

	x3 = x1+x2;
	y3 = y1+y2;
	z3 = z1+z2;

	vector_add->cor_1 = x3;
	vector_add->cor_2 = y3;
	vector_add->cor_3 = z3;

	return(vector_add);
	free(vector_add);
}

float Vector_scalar_multiplication_real (struct vector_3d_real *vector_1, struct vector_3d_real *vector_2)
{
	double vector_scalar;
	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;

	x1 = vector_1->cor_1;
	y1 = vector_1->cor_2;
	z1 = vector_1->cor_3;

	x2 = vector_2->cor_1;
	y2 = vector_2->cor_2;
	z2 = vector_2->cor_3;

	x3 = x1*x2;
	y3 = y1*y2;
	z3 = z1*z2;

	vector_scalar = x3 + y3 +z3;

	return(vector_scalar);
}

struct vector_3d_real* Vector_vector_multiplication_real (struct vector_3d_real *vector_1, struct vector_3d_real *vector_2)
{
	struct vector_3d_real *vector_vector = (struct vector_3d_real*) malloc(3*sizeof(double));
	double x1, y1, z1;
	double x2, y2, z2;
	double i, j, k;

	x1 = vector_1->cor_1;
	y1 = vector_1->cor_2;
	z1 = vector_1->cor_3;

	x2 = vector_2->cor_1;
	y2 = vector_2->cor_2;
	z2 = vector_2->cor_3;

	i = y1*z2 - y2*z1;
	j = -x1*z2 + x2*z1;
	k = x1*y2 - y1*x2;

	vector_vector->cor_1 = i;
	vector_vector->cor_2 = j;
	vector_vector->cor_3 = k;

	return(vector_vector);
	free(vector_vector);
}

struct vector_3d_imag* Vector_addition_imag(struct vector_3d_imag *vector_1, struct vector_3d_imag *vector_2)
{
	struct vector_3d_imag *vector_add = (struct vector_3d_imag*) malloc(6*sizeof(double));

	double x1_real, y1_real, z1_real;
	double x1_imag, y1_imag, z1_imag;
	double x2_real, y2_real, z2_real;
	double x2_imag, y2_imag, z2_imag;
	double x3_real, y3_real, z3_real;
	double x3_imag, y3_imag, z3_imag;

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

struct vector_3d_scalar_imag* Vector_scalar_multiplication_imag(struct vector_3d_imag *vector_1, struct vector_3d_imag *vector_2)
{
	struct vector_3d_scalar_imag *vector_scalar = (struct vector_3d_scalar_imag*) malloc(2*sizeof(double));

	double x1_real, y1_real, z1_real;
	double x1_imag, y1_imag, z1_imag;
	double x2_real, y2_real, z2_real;
	double x2_imag, y2_imag, z2_imag;
	double x3_real, y3_real, z3_real;
	double x3_imag, y3_imag, z3_imag;

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

	vector_scalar->real = x3_real + y3_real + z3_real;
	vector_scalar->imag = x3_imag + y3_imag +z3_imag;

	return(vector_scalar);
	free(vector_scalar);
}

struct vector_3d_imag* Vector_vector_multiplication_imag(struct vector_3d_imag *vector_1, struct vector_3d_imag *vector_2)
{
	struct vector_3d_imag *vector_vector = (struct vector_3d_imag*) malloc(6*sizeof(double));

	double x1_real, y1_real, z1_real;
	double x1_imag, y1_imag, z1_imag;
	double x2_real, y2_real, z2_real;
	double x2_imag, y2_imag, z2_imag;
	double i_real, j_real, k_real;
	double i_imag, j_imag, k_imag;

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
	j_real = - (x1_real*z2_real - z2_imag*x1_imag) + (x2_real*z1_real - z1_imag*x2_imag);
	k_real = (x1_real*y2_real - y2_imag*x1_imag) - (x2_real*y1_real - y1_imag*x2_imag);

	i_imag = (y1_imag*z2_real + z2_imag*y1_real) - (y2_imag*z1_real + z1_imag*y2_real);
	j_imag = - (x1_imag*z2_real + z2_imag*x1_real) + (x2_imag*z1_real + z1_imag*x2_real);
	k_imag = (x1_imag*y2_real + y2_imag*x1_real) - (x2_imag*y1_real + y1_imag*x2_real);

	vector_vector->cor_1_real = i_real;
	vector_vector->cor_2_real = j_real;
	vector_vector->cor_3_real = k_real;

	vector_vector->cor_1_imag = i_imag;
	vector_vector->cor_2_imag = j_imag;
	vector_vector->cor_3_imag = k_imag;

	return(vector_vector);
	free(vector_vector);
}

void Test_real()
{
	struct vector_3d_real *vector_1 = (struct vector_3d_real*) malloc(3*sizeof(double));
	struct vector_3d_real *vector_2 = (struct vector_3d_real*) malloc(3*sizeof(double));
	struct vector_3d_real *vector_add = (struct vector_3d_real*) malloc(3*sizeof(double));
	double vector_scalar_mul;
	struct vector_3d_real *vector_vector_mul = (struct vector_3d_real*) malloc(3*sizeof(double));
	double x_add, y_add, z_add;
	double x_v_mul, y_v_mul, z_v_mul;
	
	vector_1->cor_1 = 1.3;
	vector_1->cor_2 = -2.1;
	vector_1->cor_3 = 3.2;

	vector_2->cor_1 = 3.1;
	vector_2->cor_2 = 0;
	vector_2->cor_3 = 2.3;

	vector_add = Vector_addition_real(vector_1, vector_2) ;
	vector_scalar_mul= Vector_scalar_multiplication_real(vector_1, vector_2);
	vector_vector_mul= Vector_vector_multiplication_real(vector_1, vector_2);

	x_add = vector_add->cor_1;  
	y_add = vector_add->cor_2;
	z_add = vector_add->cor_3;

	x_v_mul = vector_vector_mul->cor_1;
	y_v_mul = vector_vector_mul->cor_2;
	z_v_mul = vector_vector_mul->cor_3;

	printf("\n");

	if ((x_add < 4.41) && (4.39 < x_add) && (y_add < -2.0) && (y_add > -2.2) && (z_add < 5.6) && (z_add > 5.4))
	{
		printf("Successful\n");
	}
	else 
	{
		printf("Fail\n" );
	}

	if (( 11.38 < vector_scalar_mul) && (vector_scalar_mul < 11.4))
	{
		printf("Successful\n");
	}
	else 
	{
		printf("Fail\n" );
	}

	if ((x_v_mul < -4.82) && (x_v_mul > -4.84) && (y_v_mul < 6.94) && (y_v_mul > 6.92) && (z_v_mul < 6.53) && (z_v_mul > 6.5))
	{
		printf("Successful\n");
	}
	else 
	{
		printf("Fail\n" );
	}

	printf("\n");

	free(vector_1);
	free(vector_2);
	free(vector_add);
	free(vector_vector_mul);
}

void Test_imagine()
{
	struct vector_3d_imag *vector_1 = (struct vector_3d_imag*) malloc(6*sizeof(double));
	struct vector_3d_imag *vector_2 = (struct vector_3d_imag*) malloc(6*sizeof(double));
	struct vector_3d_imag *vector_add_check = (struct vector_3d_imag*) malloc(6*sizeof(double));
	struct vector_3d_imag *vector_add = (struct vector_3d_imag*) malloc(6*sizeof(double));
	struct vector_3d_scalar_imag *vector_scalar_mul_check = (struct vector_3d_scalar_imag*) malloc(2*sizeof(double));
	struct vector_3d_scalar_imag *vector_scalar_mul = (struct vector_3d_scalar_imag*) malloc(2*sizeof(double));
	struct vector_3d_imag *vector_vector_mul_check = (struct vector_3d_imag*) malloc(6*sizeof(double));
	struct vector_3d_imag *vector_vector_mul = (struct vector_3d_imag*) malloc(6*sizeof(double));
	double x_add_r, x_add_i, y_add_r, y_add_i, z_add_r, z_add_i;
	double x_v_m_r, x_v_m_i, y_v_m_r, y_v_m_i, z_v_m_r, z_v_m_i;
	double scal_r, scal_i;
	
	vector_1->cor_1_real = 1.3;
	vector_1->cor_2_real = -2.1;
	vector_1->cor_3_real = 3.2;

	vector_1->cor_1_imag = -2.3;
	vector_1->cor_2_imag = 4.1;
	vector_1->cor_3_imag = -3.3;

	vector_2->cor_1_imag = 5.3;
	vector_2->cor_2_imag = 1.1;
	vector_2->cor_3_imag = 4.3;

	vector_2->cor_1_real = 3.1;
	vector_2->cor_2_real = 0;
	vector_2->cor_3_real = 2.3;

	vector_add = Vector_addition_imag(vector_1, vector_2) ;
	vector_scalar_mul= Vector_scalar_multiplication_imag(vector_1, vector_2);
	vector_vector_mul= Vector_vector_multiplication_imag(vector_1, vector_2);

	x_add_r = vector_add->cor_1_real;
	x_add_i = vector_add->cor_1_imag;
	y_add_r = vector_add->cor_2_real;
	y_add_i = vector_add->cor_1_imag;
	z_add_r = vector_add->cor_3_real;
	z_add_i = vector_add->cor_1_imag;

	scal_r = vector_scalar_mul->real;
	scal_i = vector_scalar_mul->imag;

	x_v_m_r = vector_vector_mul->cor_1_real;
	x_v_m_i = vector_vector_mul->cor_1_imag;
	y_v_m_r = vector_vector_mul->cor_2_real;
	y_v_m_i = vector_vector_mul->cor_2_imag;
	z_v_m_r = vector_vector_mul->cor_2_real;
	z_v_m_i = vector_vector_mul->cor_3_imag;

	if ((x_add_r < 4.42) && (x_add_r > 4.38) && (y_add_r < -1.9 ) && (y_add_r > -2.3) && (z_add_r < 5.7) && (z_add_r > 5.3))
	{
		if ((x_add_i < 3.2) && (x_add_i > 2.8) && (y_add_i < 5.3) && (y_add_i > 5.1) && (z_add_i < 1.1) && (z_add_i > 0.9))
		{
			printf("Successful\n");
		}
		else 
		{
			printf("Fail\n" );
		}
	}

	if ((scal_r < 33.27) && (scal_r > 33.25) && (scal_i < 3.63) && (scal_i > 3.61))
	{
		printf("Suuccessful\n");
	}
	else 
	{
		printf("Faail\n" );
	}

	if ((x_v_m_r < -25) && (x_v_m_r > -27) && (y_v_m_r < 14.54) && (y_v_m_r > 14.52) && (z_v_m_r < 30.78) && (z_v_m_r > 30.76))
	{
		if ((x_v_m_i < -3.11) && (x_v_m_i > -3.13) && (y_v_m_i < 6.44) && (y_v_m_i > 6.42) && (z_v_m_i < -0.14) && (z_v_m_i > -0.16))	
		{	
			printf("Suuuccessful\n");
		}
		else 
		{
			printf("Faaail\n" );
		}
	}	
	free(vector_1);
	free(vector_2);
	free(vector_add_check);
	free(vector_add);
	free(vector_scalar_mul_check);
	free(vector_scalar_mul);
	free(vector_vector_mul_check);
	free(vector_vector_mul);
}

int main() 
{
	int n;
	int t;

	struct vector_3d_real *vector1_real = (struct vector_3d_real*) malloc(3*sizeof(double));
	struct vector_3d_real *vector2_real = (struct vector_3d_real*) malloc(3*sizeof(double));
	struct vector_3d_real *vector_add_real = (struct vector_3d_real*) malloc(3*sizeof(double)); 
	double vector_scalar_mul_real;
	struct vector_3d_real *vector_vector_mul_real =(struct vector_3d_real*) malloc(3*sizeof(double));
	struct vector_3d_imag *vector1_imag = (struct vector_3d_imag*) malloc(6*sizeof(double));
	struct vector_3d_imag *vector2_imag = (struct vector_3d_imag*) malloc(6*sizeof(double));
	struct vector_3d_imag *vector_add_imag = (struct vector_3d_imag*) malloc(6*sizeof(double)); 
	struct vector_3d_scalar_imag *vector_scalar_mul_imag = (struct vector_3d_scalar_imag*) malloc(2*sizeof(double));
	struct vector_3d_imag *vector_vector_mul_imag =(struct vector_3d_imag*) malloc(6*sizeof(double));

	n = 5; 
	while ((n != 1) || (n != 2))
	{
		printf("What type of numbers do you want to work?\n");
		printf("1. If they are real, press 1\n");
		printf("2. If they are complex, press 2\n");
		scanf("%d", &n);
	}
	if (n == 1)
	{
		printf("Print coordinates of the first vector\n");
		scanf("%lf,%lf,%lf", &vector1_real->cor_1, &vector1_real->cor_2, &vector1_real->cor_3);

		printf("Print coordinates of the second vector\n");
		scanf("%lf,%lf,%lf", &vector2_real->cor_1, &vector2_real->cor_2, &vector2_real->cor_3);

		printf("\n");

		t = 1;
	}

	if (n == 2) 
	{	
		printf("Print REAL part of coordinates of the first vector\n");
		scanf("%lf,%lf,%lf", &vector1_imag->cor_1_real, &vector1_imag->cor_2_real, &vector1_imag->cor_3_real);
		printf("Print IMAGINARY part of coordinates of the first vector\n");
		scanf("%lf,%lf,%lf", &vector1_imag->cor_1_imag, &vector1_imag->cor_2_imag, &vector1_imag->cor_3_imag);

		printf("Print REAL part of coordinates of the second vector\n");
		scanf("%lf,%lf,%lf", &vector2_imag->cor_1_real, &vector2_imag->cor_2_real, &vector2_imag->cor_3_real);
		printf("Print IMAGINARY part of coordinates of the second vector\n");
		scanf("%lf,%lf,%lf", &vector2_imag->cor_1_imag, &vector2_imag->cor_2_imag, &vector2_imag->cor_3_imag);

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
		printf("4. If you want to test operations with real numbers, press 4\n");
		printf("5. If you want to test operations with imaginary numbers, press 5\n");	
		printf("6. If want to exit, press 0\n");
		scanf("%d", &n);

		if ((n == 1) && (t == 1)) 
		{
			/*функция сложения векторов с вещ координатами*/
			vector_add_real = Vector_addition_real(vector1_real, vector2_real);
			printf("\n");
			printf("%lf,%lf,%lf\n", vector_add_real->cor_1, vector_add_real->cor_2, vector_add_real->cor_3);
			printf("\n");
		}
		if ((n == 1) && (t == 2))
		{
			/*функция сложения векторов с комплексными координатами*/
			vector_add_imag = Vector_addition_imag(vector1_imag, vector2_imag);
			printf("\n");
			printf("Real part of cordinates\n");
			printf("%lf,%lf,%lf\n", vector_add_imag->cor_1_real, vector_add_imag->cor_2_real, vector_add_imag->cor_3_real);
			printf("\n");
			printf("Imaginary part of cordinates\n");
			printf("%lf,%lf,%lf\n", vector_add_imag->cor_1_imag, vector_add_imag->cor_2_imag, vector_add_imag->cor_3_imag);
			printf("\n");
		}
		if ((n == 2) && (t == 1)) 
		{
	 		/*функция скалярного умножения векторов с вещ координатами*/
			vector_scalar_mul_real = Vector_scalar_multiplication_real(vector1_real, vector2_real);
			printf("\n");
			printf("%lf\n", vector_scalar_mul_real);
			printf("\n");
		}
		if ((n == 2) && (t == 2)) 
		{
			/*функция скалярного умножения векторов с комплексными координатами*/
			vector_scalar_mul_imag = Vector_scalar_multiplication_imag(vector1_imag, vector2_imag);
			printf("\n");
			printf("Real part of cordinates\n");
			printf("%lf\n", vector_scalar_mul_imag->real);
			printf("\n");
			printf("Imaginary part of cordinates\n");
			printf("%lf\n", vector_scalar_mul_imag->imag);
			printf("\n");
		}
		if ((n == 3) && (t == 1)) 
		{
			/*функция векторного произведния векторов с вещ координатами*/
			vector_vector_mul_real = Vector_vector_multiplication_real(vector1_real, vector2_real);
			printf("\n");
			printf("%lf,%lf,%lf\n", vector_vector_mul_real->cor_1, vector_vector_mul_real->cor_2, vector_vector_mul_real->cor_3);
			printf("\n");
		}
		if ((n == 3) && (t == 2)) 
		{
			/*функция векторного произведения векторов с комплексными координатами*/
			vector_vector_mul_imag = Vector_vector_multiplication_imag(vector1_imag, vector2_imag);
			printf("\n");
			printf("Real part of cordinates\n");
			printf("%lf,%lf,%lf\n", vector_vector_mul_imag->cor_1_real, vector_vector_mul_imag->cor_2_real, vector_vector_mul_imag->cor_3_real);
			printf("\n");
			printf("Imaginary part of cordinates\n");
			printf("%lf,%lf,%lf\n", vector_vector_mul_imag->cor_1_imag, vector_vector_mul_imag->cor_2_imag, vector_vector_mul_imag->cor_3_imag);
			printf("\n");
		}
		if (n == 4)
		{
			Test_real();
		}
		if (n == 5)
		{
			Test_imagine();
		}
	}	

	free(vector1_real);
	free(vector2_real);
	free(vector_add_real);
	free(vector_vector_mul_real);
	free(vector1_imag);
	free(vector2_imag);
	free(vector_add_imag);
	free(vector_scalar_mul_imag);
	free(vector_vector_mul_imag);
}
