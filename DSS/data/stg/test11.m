t=0:.1:5000;
P0= (-0.500000)*exp(-0.000100000*t)+(+0.166667)*exp(-0.000300000*t)+(0.333333);
P1= (-1.00000)*exp(-0.000200000*t)
%+(-0.000000000827181*t+0.500000)*exp(-0.000300000*t)+(0.500000)*exp(-0.000100000*t);
P2= (-0.000100000*t-1.00000)*exp(-0.000300000*t)+(1.00000)*exp(-0.000200000*t);
P3= (0.000100000*t)*exp(-0.000300000*t);
P4= (1.00000)*exp(-0.000300000*t);
P=P0+P1+P2+P3+P4+0.0;
 PL=[P0; P1; P2; P3; P4;  P]; 
 myplot=plot(t,PL,'-k') 
 box off 
 axis([0.00000 5000.00 0.0 1.0]) 
 grid on 
 axis manual