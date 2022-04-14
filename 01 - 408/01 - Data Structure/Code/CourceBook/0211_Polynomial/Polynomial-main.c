#include "Pololynomial.h"


int main(int argc, char** argv) {
	int Pa_expns[4] = { 0, 1, 8, 17 };
	float Pa_coefs[4] = { 7.0, 3.0, 9.0, 5.0 };
	int Pb_expns[3] = { 1, 7, 8 };
	float Pb_coefs[3] = { -8.0, 22.0, -9.0 };


	Polynomial Pa, Pb;
	CreatePolyn(&Pa, 4, Pa_expns, Pa_coefs);
	CreatePolyn(&Pb, 3, Pb_expns, Pb_coefs);

	printf("Pa = ");
	PrintPolyn(Pa);
	printf("Pb = ");
	PrintPolyn(Pb);

	//// º”∑®ºÏ≤‚
	//AddPolyn(&Pa, &Pb);
	//printf("Pa = ");
	//PrintPolyn(Pa);

	//// ºı∑®≤‚ ‘
	//SubtractPolyn(&Pa, &Pb);
	//printf("Pa = ");
	//PrintPolyn(Pa);

	// ≥À∑®≤‚ ‘
	MuliplyPolyn(&Pa, &Pb);
	printf("Pa = ");
	PrintPolyn(Pa);

}