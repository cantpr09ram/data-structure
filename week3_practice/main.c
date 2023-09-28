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
	
	int i, j, k, l, m, n;
	int *p0, *p1, *p2, *p3, *p4, *p5, *p6;
	i = sizeof(s[0].c1); //char = 1
	j = sizeof(s[0].f6);//float = 4
	k = sizeof(s[0].f8);// dobule = 8
	m = sizeof(s[0].f13.f12); //unicon =16 (Structure Member Alignment)
	l = sizeof(s[0].f13.f11);//int = 4*3 =>12
	n = sizeof(s[1]); //40 => 1+ 4*2 + 8 + 16 = 33 (Structure Member Alignment)
	
	

	
	p0 = &(s[0]);
	p1 = &(s[17].c1);
	p2 = &(s[13].f6);
	p3 = &(s[28].f8);
	p4 = &(s[17].f13.f11.f3);
	p5 = &(s[27].f13.f12.f5);
	
	return 0;
}
