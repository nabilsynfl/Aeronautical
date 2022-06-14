#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define WINDOWS 1

void clrscr() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}
    

void calculatingAtmosphereISA()
{
    float h, T, P, rho, li, Ti, rhoi, Pi, Hi;
    float R = 29.271; // in m/k
    char NamaLapisan[32];

    printf("input height fly (meter) then press ENTER : "); 
    scanf("%f", &h);
    printf("\n");

    if ((0 <= h) & (h <= 11000))
    {
        Hi = 0;
        li = -0.0065;
        Ti = 288.15;
        rhoi = 1.2250;
        Pi = 101325;
        strcpy(NamaLapisan, "Troposphere");
    }

    if ((11000 <= h) & (h <= 20000))
    {
        Hi = 11000;
        li = 0;
        Ti = 216.65;
        rhoi = 0.3639;
        Pi = 22632;
        strcpy(NamaLapisan, "Stratosphere Bottom");
    }

    if ((20000 <= h) & (h <= 32000))
    {
        Hi = 20000;
        li = 0.0010;
        Ti = 216.65;
        rhoi = 0.0880;
        Pi = 5475;
        strcpy(NamaLapisan, "Stratosphere Mid");
    }

    if ((32000 <= h) & (h <= 47000))
    {
        Hi = 32000;
        li = 0.0028;
        Ti = 228.65;
        rhoi = 0.0132;
        Pi = 868;
        strcpy(NamaLapisan, "Strtosphere Top");
    }

    if ((47000 <= h) & (h <= 51000))
    {
        Hi = 47000;
        li = 0;
        Ti = 270.65;
        rhoi = 0.0014;
        Pi = 110.90;
        strcpy(NamaLapisan, "Stratopause");
    }

    if ((51000 <= h) & (h <= 71000))
    {
        Hi = 51000;
        li = -0.0028;
        Ti = 270.65;
        rhoi = 0.00084;
        Pi = 66.90;
        strcpy(NamaLapisan, "Mesosphere bottom");
    }

    if ((71000 <= h) & (h <= 80000))
    {
        Hi = 71000;
        li = -0.0020;
        Ti = 214.65;
        rhoi = 0.00006;
        Pi = 3.95;
        strcpy(NamaLapisan, "Mesosphere top");
    }

    if (li != 0)
    {
        T = Ti * (1+li/Ti*(h - Hi));
        P = Pi * pow(1 + li/Ti * (h - Hi), -1/(R*li));
        rho = rhoi * pow(1 + li/Ti*(h-Hi), -(1+1/(R*li)));
    }
    else
    {
        T = Ti;
        P = Pi * exp(-(h-Hi)/(R*Ti));
        rho = rhoi * exp(-(h-Hi)/(R*Ti));
    }

    printf("Height Fly      = %5.1f (m)      \n", h);
    printf("Air temperature = %5.1f (K)      \n", T);
    printf("Air pressure    = %5.1f (Pa)     \n", P);
    printf("Air Density     = %5.5f (kg/m^3) \n", rho);
    printf("Air layer       = %s \n", NamaLapisan);
}

void accelerationDueToGravity()
{
    #define PT 3.14159

    float h, phideg, phirad, G, Me, Re, ohme, g;

    G = 6.67e-11;
    Me = 5.98e24;
    Re = 6371000;
    ohme = 7.29e-5;

    printf("Input heigth fly (mtr) then press Enter = ");
    scanf("%f", &h);
    printf("Input latitude angle (deg) then press Enter = ");
    scanf("%f", &phideg);
    printf("\n");

    phirad = phideg / 180 * PT;
    g = G*Me/((Re+h) * (Re+h));
    g = g - ohme*ohme*(Re+h)*cos(phirad)*cos(phirad);

    printf("Heigth fly                  = %5.1f (m)     \n", h);
    printf("latitude position           = %5.1f (deg)   \n", phideg);
    printf("acceleration due to gravity = %5.5f (m/s^2) \n", g);
    printf("Press any key to exit");
    getch();

}

float CalculateISA(float h, int outParam){
    float T, P, rho, li, Ti, rhoi, Pi, Hi;
    float R = 29.271; // in m/k

    if ((0 <= h) & (h <= 11000))
    {
        Hi = 0;
        li = -0.0065;
        Ti = 288.15;
        rhoi = 1.2250;
        Pi = 101325;
    }

    if ((11000 <= h) & (h <= 20000))
    {
        Hi = 11000;
        li = 0;
        Ti = 216.65;
        rhoi = 0.3639;
        Pi = 22632;
    }

    if ((20000 <= h) & (h <= 32000))
    {
        Hi = 20000;
        li = 0.0010;
        Ti = 216.65;
        rhoi = 0.0880;
        Pi = 5475;
    }

    if ((32000 <= h) & (h <= 47000))
    {
        Hi = 32000;
        li = 0.0028;
        Ti = 228.65;
        rhoi = 0.0132;
        Pi = 868;
    }

    if ((47000 <= h) & (h <= 51000))
    {
        Hi = 47000;
        li = 0;
        Ti = 270.65;
        rhoi = 0.0014;
        Pi = 110.90;
    }

    if ((51000 <= h) & (h <= 71000))
    {
        Hi = 51000;
        li = -0.0028;
        Ti = 270.65;
        rhoi = 0.00084;
        Pi = 66.90;
    }

    if ((71000 <= h) & (h <= 80000))
    {
        Hi = 71000;
        li = -0.0020;
        Ti = 214.65;
        rhoi = 0.00006;
        Pi = 3.95;
    }

    if (li != 0)
    {
        T = Ti * (1+li/Ti*(h - Hi));
        P = Pi * pow(1 + li/Ti * (h - Hi), -1/(R*li));
        rho = rhoi * pow(1 + li/Ti*(h-Hi), -(1+1/(R*li)));
    }
    else
    {
        T = Ti;
        P = Pi * exp(-(h-Hi)/(R*Ti));
        rho = rhoi * exp(-(h-Hi)/(R*Ti));
    }

    float fResult = 0;
    if(outParam == 0) fResult = T;
    if(outParam == 1) fResult = P;
    if(outParam == 2) fResult = rho;
    return fResult;
}

void aircraftLiftCalculation(){
    float h, v, s, CL, rho, L;
    char NamaLapisan[32];
    printf("Input heigth fly (meter) then press ENTER = ");
    scanf("%f", &h);
    printf("Input acceleration fly (m/s) then press ENTER = ");
    scanf("%f", &v);
    printf("Input wing area (m^2) then press ENTER = ");
    scanf("%f", &s);
    printf("Input lift coefficient (CL) then press ENTER = ");
    scanf("%f", &CL);
    printf("\n");

    rho = CalculateISA(h, 2);
    L = 0.5 * rho * v*v *s * CL;
    printf("Lift = %5.1f (N)\n", L);
    printf("\nPress any key to exit");
    getch();
}

void AircraftDragCalculation(){
    float h, v, s, CD, rho, D;

    printf("Input heigth fly (meter) then press ENTER = ");
    scanf("%f", &h);
    printf("Input acceleration fly (m/s) then press ENTER = ");
    scanf("%f", &v);
    printf("Input wing area (m^2) then press ENTER = ");
    scanf("%f", &s);
    printf("Input drag coefficient (DC) then press ENTER = ");
    scanf("%f", &CD);
    printf("\n");

    float T = CalculateISA(h, 0); //return temperature
    float P = CalculateISA(h, 1); //return Pressure
    rho = CalculateISA(h, 2); //return Density
    D = 0.5 * rho * v*v * s * CD;

    printf("\n");
    printf("Suhu Udara            = %5.1f (K)\n", T);
    printf("Tekanan Udara         = %5.1f (Pa)\n", P);
    printf("Kerapatan Udara       = %5.5f (Kg/m^3)\n", rho);
    printf("Gaya Hambat           = %5.1f (N)\n", D);
    printf("Press any key to exit...");
    getch();
}

int main(){
    printf("Author : NabilSynfl");
    int menu;
	do {
        clrscr();
        printf("\n\n\n\n\n");
		printf("Application of c Programming to Aeronautical engineering\n");
		printf("1. Calculation of atmospheric characteristics ISA\n");
		printf("2. Calculation of acceleration due to gravity\n");
		printf("3. Aircraft lift calculation\n");
        printf("4. Aircraft drag calculation\n");
		printf("5. exit\n");
		printf("========================\n");
		printf("Choose>>> "); scanf("%d", &menu);
		
		
		switch(menu) {
			case 1:
				calculatingAtmosphereISA();
				break;
			case 2:
				accelerationDueToGravity();
				break;
			case 3:
				aircraftLiftCalculation();
				break;
			case 4:
                AircraftDragCalculation();
				break;
		}
	} while (menu != 5);
		
	return 0;
}
