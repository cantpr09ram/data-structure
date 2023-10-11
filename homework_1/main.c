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
	};        
	struct sam { 
		char utype; //1
		float f6, f7; //4*2
	    double f8; //8
		union { //16
			struct stint f11;
			struct stfloat f12;  
		}  
		f13;   
	};        
	struct sam s[100];
	
	int i, j, k, l, m, n;
	int *p0, *p1, *p2, *p3, *p4, *p5, *p6;
	i = sizeof(s[0].utype); //char = 1
	j = sizeof(s[0].f6);//float = 4
	k = sizeof(s[0].f8);// dobule = 8
	m = sizeof(s[0].f13.f12); //unicon =16 (Structure Member Alignment)
	l = sizeof(s[0].f13.f11);//int = 4*3 =>12
	n = sizeof(s[1]); //40 => 1+ 4*2 + 8 + 16 = 33 (Structure Member Alignment)
	
	

	
	p0 = &(s[0]); //0x62ee30
	p1 = &(s[27].utype); //0x62ee30+27*40(0x438) = 0x62F268 
	p2 = &(s[23].f6);//0x62ee30 + 23*40(0x398) + 1 + 3(alignment) =  0x62f1cc
	p3 = &(s[18].f8);//0x62ee30 + 18*40(0x2d0) + 1 + 3(alignment) + 8 + 4(alignment) (10)= 0x62f110
	p4 = &(s[37].f13.f11.f3);//0x62ee30 + 37*40(0x5c8) + 24(18) + 4*2 = 0x62f418
	p5 = &(s[37].f13.f12.f5);//0x62ee30 + 37*40(0x5c8) + 24(18) + 4 + 4(alignment) = 0x62f418 
	
	//0x62ee30 + 37*40(0x5c8) = 0x62f3f8
	//411440430 bo-chain
	return 0;
}
