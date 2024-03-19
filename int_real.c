#define MASSES_INFO
#define OMEGA 
#define CLEAN
#include"../include/micromegas.h"
#include"../include/micromegas_aux.h"
#include"lib/pmodel.h"
#include<math.h>
#define pi 3.14159

int main()
{  int err;
   char cdmName[10];
   int spin2, charge3,cdim;
   ForceUG=0; 
  VZdecay=0; VWdecay=0;


  // if(err==-1)     {printf("Can not open the file\n"); exit(1);}
  // else if(err>0)  { printf("Wrong file contents at line %d\n",err);exit(1);}



  err=sortOddParticles(cdmName);
  if(err) { printf("Can't calculate %s\n",cdmName); return 1;}



  {
     qNumbers(CDM[1], &spin2, &charge3, &cdim);
     printf("\nDark matter candidate is '%s' with spin=%d/2 mass=%.2E\n",CDM[1],  spin2,McdmN[1]);
     if(charge3) printf("Dark Matter has electric charge %d/3\n",charge3);
     if(cdim!=1) printf("Dark Matter is a color particle\n");
  }


double lam3=1E-11;
double coupling=1E-5;
double Yndx1=9E-5;
assignVal("MXi",450);
assignVal("MnH1",460);
assignVal("MnH2",460);
assignVal("MnH3",460);
assignVal("lam3",lam3);
assignVal("wC21x1",18);
assignVal("wC22x2",18);
assignVal("wC23x3",18);
assignVal("wC11x1",0);
assignVal("wC12x2",0);
assignVal("wC13x3",0);

#ifdef OMEGA
{ int fast=1;
  double Beps=1.E-4, cut=0.01, vsPb;
  double Omega, Xf;
  int i,err;   
defThermalSet(2,"~N1 ~N2 ~N3");
defThermalSet(1,"~Xi");
sortOddParticles(NULL);
for (int j=0; j<5;j++)
{
assignVal("Ynd1x1",Yndx1*10);
assignVal("Ynd2x2",Yndx1*10);
assignVal("Ynd3x3",Yndx1*10);
Omega=darkOmegaN(fast,Beps,&err);
printf("Omega = %.16f\n",Omega);
printf("Tstart %.3f Tend %.3f\n",Tstart,Tend);
printf("The xstart=%.3f\n",McdmN[1]/Tstart);
printf("The xend=%.3f\n",McdmN[1]/Tend);
}
}
#endif



  killPlots();
  return 0;
}

