t=0:.1:5000; 
%p1=-0.139714*exp(-0.0008*t)+0.658667*exp(-0.0004*t)-1.51795*exp(-0.0001*t)+1;
%p2=1.11771* exp(-0.0008* t)-2.63467* exp(-0.0004* t)+1.51795* exp(-0.0001*t);
%p3=-1.956* exp(-0.0008* t)+1.976* exp(-0.0004* t);
%p4=0.978* exp(-0.0008* t);
%Type 1 (white).
p11=-0.2445* exp (-0.001* t)+1.3173 * exp (-0.0005* t)-2.0718* exp (-0.002* t) +1 ;
p12= 1.2225* exp (-0.001* t)-3.2933 * exp (-0.0005* t)+2.0718* exp (0.0002* t) ;
p13=-1.956 * exp (-0.001* t)+2.192  * exp (-0.0005* t) ;
p14= 0.978 * exp (-0.001* t) ;
p15=p11+p12+p13+p14;
%P1=[p11; p12; p13; p14; p15]; 
%Type 2 (grey).
p21=0.923* exp (-0.007* t)-1.631* exp (-0.00402* t)+0.71 ;
p22=0.369* exp (-0.007* t)-0.661* exp (-0.00402* t)+0.29 ;
p23=-1.292* exp (-0.007* t)+1.314* exp (-0.00402* t) ;
p24=0.978* exp (-0.00402* t) ;
p15=p21+p22+p23+p24;
P1=[p21; p22; p23; p24; p15]; 
myplot=plot(t,P1,'-k');
box off;
axis([0 500 0.0 1.0])
grid on
axis manual
p41=p14(find(t==100));
%s=strcat(' {\it\rho}_{\iti}^4(',num2str(500),')=',num2str(p41));
s=strcat(' \fontname{times}{\it\rho} _{\it{i}}^4({\itt})');
X=[500, 3500]; Y=[p41, 0.9];
text(3500,0.9,s,'Fontsize',16);
line(X,Y);
p31=p13(find(t==150));
%s=strcat(' \rho_i^3(',num2str(1500),')=',num2str(p31));
s=strcat(' \fontname{times}{\it\rho} _{\it{i}}^3({\itt})');
X=[1500, 3500]; Y=[p31, 0.8];
text(3500,0.8,s,'Fontsize',16);
line(X,Y);
p21=p12(find(t==200));
%s=strcat(' \rho_i^2(',num2str(2000),')=',num2str(p21));
s=strcat(' \fontname{times}{\it\rho} _{\it{i}}^2({\itt})');
X=[2000, 3500]; Y=[p21, 0.7];
text(3500,0.7,s,'Fontsize',16);
line(X,Y);
p11=p11(find(t==250));
%s=strcat(' \rho_i^1(',num2str(2500),')=',num2str(p11));
s=strcat(' \fontname{times}{\it\rho} _{\it{i}}^1({\itt})');
X=[2500, 3500]; Y=[p11, 0.6];
text(3500,0.6,s,'Fontsize',16);
line(X,Y);





