t=0:.1:1000;
P3= (0.950000)*exp(-0.000600000*t);
P2= (0.346667)+(-0.316667)*exp(-0.000600000*t);
P1= (0.653333)+(-0.633333)*exp(-0.000600000*t);
Po3= (0.950000);
Po2= (0.0300000);
Po1= (0.0200000);
 P=P1+P2+P3; 
 PL=[P1; P2; P3; P]; 
 myplot=plot(t,PL,'-k') 
 box off 
 axis([0.00000 1000.00 0.0 1.0]) 
 grid on 
 axis manual