#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct stint{  
		int f1, f2, f3;  
	};
	struct stfloat {
		float f4;
		double f5;  
        char c2;
	};        
	struct sam { 
	    double f8; //8
        char c1;
        float f6;
		union { //16
			struct stint f11;
			struct stfloat f12;  
		}  
		f13;   
	};        
	struct sam s[100];
	
	int i, j, k, ll, m, n;
	//int *psx;
	//char *pc;
	//float *pf;
	//double *pd, *psy;
	//struct sam *pstart;
	int *p0, *p1, *p2, *p3, *pa, *p5, *p6;
	
	i = sizeof(int); //char = 1
	j = sizeof(char);//float = 4
	k = sizeof(float);// dobule = 8
	m = sizeof(double); //unicon =16 (Structure Member Alignment)
	ll = sizeof(struct stfloat);//int = 4*3 =>12
	n = sizeof(struct sam); //40 => 1+ 4*2 + 8 + 16 = 33 (Structure Member Alignment)
	
	p0 = &(s[0]); //0x62ee30 starting address
	p1 = &(s[17].c1);//0x62f0e0 = 0x62ee30 + 0x200 (40*17+8=688)
	p2 = &(s[13].f6);//0x62f044 = 0x62ee30 + 0x214 (40*13+8+4=532)
	p3 = &(s[28].f8);//0x62f290 = 0x62ee30 + 0x460 (40*28=1120)
	pa = &(s[17].f13.f11.f3);//0x62f0f0 = 0x62ee30 + 0x2c0 (40*17+8+4+4+(4+4) = 704)
	p5 = &(s[27].f13.f12.f5);//0x62f280 = 0x62ee30 +0x450 (40*27+8+4+4+(8)=1104)
	//pstart = &(s[0]);
	//pc = &(s[17].c1);
	//pf = &(s[13].f6);
	//pd = &(s[28].f8);
	//psx = &(s[17].f13.f11.f3);
	//psy = &(s[27].f13.f12.f5);
	
	return 0;
}
