t=0:.1:5000;

%fn='Euclid';
%fs=16;
fn='Times';
fs=18;
% 'Fontsize',fs,'Fontname',fn

% version #1 characteristics
 pi_0_0=(-0.139714).*exp(-0.000800000*t)+(0.658667).*exp(-0.000400000*t)+(-1.51795).*exp(-0.000100000*t)+(1.00000)
 pi_0_1=(1.11771).*exp(-0.000800000*t)+(-2.63467).*exp(-0.000400000*t)+(1.51795).*exp(-0.000100000*t)
 pi_0_2=(-1.95600).*exp(-0.000800000*t)+(1.97600).*exp(-0.000400000*t)
 pi_0_3=0.978000.*exp(-0.000800000*t)
 P_0=[pi_0_0; pi_0_1; pi_0_2; pi_0_3]; 
 myplot=plot(t,P_0,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p0_0_0=pi_0_0(find(t==2000));
 s=strcat(' {\it\rho} _{{\iti}1}^{(1)}({\itt})');
 X=[2000, 2750]; Y=[p0_0_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p0_0_1=pi_0_1(find(t==1500));
 s=strcat(' {\it\rho} _{{\iti}1}^{(2)}({\itt})');
 X=[1500, 2750]; Y=[p0_0_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p0_0_2=pi_0_2(find(t==1250));
 s=strcat(' {\it\rho} _{{\iti}1}^{(3)}({\itt})');
 X=[1250, 2750]; Y=[p0_0_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p0_0_3=pi_0_3(find(t==750));
 s=strcat(' {\it\rho} _{{\iti}1}^{(4)}({\itt})');
 X=[750, 2750]; Y=[p0_0_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
  print -dmeta comp_version_1


 % version #2 characteristics
 pi_1_0=(-1.63000).*exp(-0.000800000*t)+(-9.88000).*exp(-0.000400000*t)+(10.5110).*exp(-0.000500000*t)+(1.00000)
 pi_1_1=(2.60800).*exp(-0.000800000*t)+(7.90400).*exp(-0.000400000*t)+(-10.5110).*exp(-0.000500000*t)
 pi_1_2=(-1.95600).*exp(-0.000800000*t)+(1.97600).*exp(-0.000400000*t)
 pi_1_3=0.978000.*exp(-0.000800000*t)
 P_1=[pi_1_0; pi_1_1; pi_1_2; pi_1_3]; 
 myplot=plot(t,P_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p0_1_0=pi_1_0(find(t==2000));
 s=strcat(' {\it\rho} _{{\iti}2}^{(1)}({\itt})');
 X=[2000, 2750]; Y=[p0_1_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p0_1_1=pi_1_1(find(t==1500));
 s=strcat(' {\it\rho} _{{\iti}2}^{(2)}({\itt})');
 X=[1500, 2750]; Y=[p0_1_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p0_1_2=pi_1_2(find(t==1250));
 s=strcat(' {\it\rho} _{{\iti}2}^{(3)}({\itt})');
 X=[1250, 2750]; Y=[p0_1_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p0_1_3=pi_1_3(find(t==750));
 s=strcat(' {\it\rho} _{{\iti}2}^{(4)}({\itt})');
 X=[750, 2750]; Y=[p0_1_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
  print -dmeta comp_version_2


 % version #3 characteristics
 pi_2_0=(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 pi_2_1=(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 pi_2_2=(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 pi_2_3=0.978000.*exp(-0.00100000*t)
 P_2=[pi_2_0; pi_2_1; pi_2_2; pi_2_3]; 
 myplot=plot(t,P_2,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; xlabel('\itt')
 p0_2_0=pi_2_0(find(t==2000));
 s=strcat(' {\it\rho} _{{\iti}3}^{(1)}({\itt})');
 X=[2000, 2750]; Y=[p0_2_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p0_2_1=pi_2_1(find(t==1500));
 s=strcat(' {\it\rho} _{{\iti}3}^{(2)}({\itt})');
 X=[1500, 2750]; Y=[p0_2_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p0_2_2=pi_2_2(find(t==1250));
 s=strcat(' {\it\rho} _{{\iti}3}^{(3)}({\itt})');
 X=[1250, 2750]; Y=[p0_2_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p0_2_3=pi_2_3(find(t==750));
 s=strcat(' {\it\rho} _{{\iti}3}^{(4)}({\itt})');
 X=[750, 2750]; Y=[p0_2_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 print -dmeta comp_version_3

% cold-redundancy  version #1 + version #1
 p_1_1_0= pi_0_0 .* pi_0_0 %(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 p_1_1_1= pi_0_1 + pi_0_0 .* pi_0_1 %(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 p_1_1_2= pi_0_2 + pi_0_0 .* pi_0_2 %(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 p_1_1_3= pi_0_3 + pi_0_0 .* pi_0_3 %0.978000.*exp(-0.00100000*t)
 
 P_1_1=[p_1_1_0; p_1_1_1; p_1_1_2; p_1_1_3]; 

 myplot=plot(t,P_1_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p_0=p_1_1_0(find(t==2500));
 s=strcat('{\it p} _{\it{i}}^{(1)}({\itx_i,t})');
 X=[2500, 2750]; Y=[p_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_1=p_1_1_1(find(t==2250));
 s=strcat('{\it p} _{\it{i}}^{(2)}({\itx_i,t})');
 X=[2250, 2750]; Y=[p_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_2=p_1_1_2(find(t==1250));
 s=strcat('{\it p} _{\it{i}}^{(3)}({\itx_i,t})');
 X=[1250, 2750]; Y=[p_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_3=p_1_1_3(find(t==750));
 s=strcat('{\it p} _{\it{i}}^{(4)}({\itx_i,t})');
 X=[750, 2750]; Y=[p_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 %xlabel('{\itx_i}=(1,1)','Fontsize',16,'FontName','Euclid');
 print -dmeta comp_version_1_1

% cold-redundancy  version #2 + version #2
 p_1_1_0= pi_1_0 .* pi_1_0 %(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 p_1_1_1= pi_1_1 + pi_1_0 .* pi_1_1 %(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 p_1_1_2= pi_1_2 + pi_1_0 .* pi_1_2 %(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 p_1_1_3= pi_1_3 + pi_1_0 .* pi_1_3 %0.978000.*exp(-0.00100000*t)
 
 P_1_1=[p_1_1_0; p_1_1_1; p_1_1_2; p_1_1_3]; 

 myplot=plot(t,P_1_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p_0=p_1_1_0(find(t==2500));
 s=strcat('{\it p} _{\it{i}}^{(1)}({\itx_i,t})');
 X=[2500, 2750]; Y=[p_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_1=p_1_1_1(find(t==2250));
 s=strcat('{\it p} _{\it{i}}^{(2)}({\itx_i,t})');
 X=[2250, 2750]; Y=[p_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_2=p_1_1_2(find(t==1250));
 s=strcat('{\it p} _{\it{i}}^{(3)}({\itx_i,t})');
 X=[1250, 2750]; Y=[p_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_3=p_1_1_3(find(t==750));
 s=strcat('{\it p} _{\it{i}}^{(4)}({\itx_i,t})');
 X=[750, 2750]; Y=[p_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
% xlabel('{\itx_i}=(2,2)','Fontsize',16,'FontName','Euclid');
 print -dmeta comp_version_2_2

% cold-redundancy  version #3 + version #3
 p_1_1_0= pi_2_0 .* pi_2_0 %(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 p_1_1_1= pi_2_1 + pi_2_0 .* pi_2_1 %(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 p_1_1_2= pi_2_2 + pi_2_0 .* pi_2_2 %(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 p_1_1_3= pi_2_3 + pi_2_0 .* pi_2_3 %0.978000.*exp(-0.00100000*t)
 
 P_1_1=[p_1_1_0; p_1_1_1; p_1_1_2; p_1_1_3]; 

 myplot=plot(t,P_1_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p_0=p_1_1_0(find(t==2250));
 s=strcat('{\it p} _{\it{i}}^{(1)}({\itx_i,t})');
 X=[2250, 2750]; Y=[p_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_1=p_1_1_1(find(t==1750));
 s=strcat('{\it p} _{\it{i}}^{(2)}({\itx_i,t})');
 X=[1750, 2750]; Y=[p_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_2=p_1_1_2(find(t==1250));
 s=strcat('{\it p} _{\it{i}}^{(3)}({\itx_i,t})');
 X=[1250, 2750]; Y=[p_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_3=p_1_1_3(find(t==750));
 s=strcat('{\it p} _{\it{i}}^{(4)}({\itx_i,t})');
 X=[750, 2750]; Y=[p_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
% xlabel('{\itx_i}=(3,3)','Fontsize',16,'FontName','Euclid');
 print -dmeta comp_version_3_3

 % cold-redundancy  version #1 + version #2
 p_1_1_0= pi_0_0 .* pi_1_0 %(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 p_1_1_1= pi_0_1 + pi_0_0 .* pi_1_1 %(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 p_1_1_2= pi_0_2 + pi_0_0 .* pi_1_2 %(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 p_1_1_3= pi_0_3 + pi_0_0 .* pi_1_3 %0.978000.*exp(-0.00100000*t)
 
 P_1_1=[p_1_1_0; p_1_1_1; p_1_1_2; p_1_1_3]; 

 myplot=plot(t,P_1_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p_0=p_1_1_0(find(t==2500));
 s=strcat('{\it p} _{\it{i}}^{(1)}({\itx_i,t})');
 X=[2500, 2750]; Y=[p_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_1=p_1_1_1(find(t==2250));
 s=strcat('{\it p} _{\it{i}}^{(2)}({\itx_i,t})');
 X=[2250, 2750]; Y=[p_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_2=p_1_1_2(find(t==1250));
 s=strcat('{\it p} _{\it{i}}^{(3)}({\itx_i,t})');
 X=[1250, 2750]; Y=[p_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_3=p_1_1_3(find(t==750));
 s=strcat('{\it p} _{\it{i}}^{(4)}({\itx_i,t})');
 X=[750, 2750]; Y=[p_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
% xlabel('{\itx_i}=(1,2)','Fontsize',16,'FontName','Euclid');
 print -dmeta comp_version_1_2

% cold-redundancy  version #1 + version #3
 p_1_1_0= pi_0_0 .* pi_2_0 %(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 p_1_1_1= pi_0_1 + pi_0_0 .* pi_2_1 %(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 p_1_1_2= pi_0_2 + pi_0_0 .* pi_2_2 %(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 p_1_1_3= pi_0_3 + pi_0_0 .* pi_2_3 %0.978000.*exp(-0.00100000*t)
 
 P_1_1=[p_1_1_0; p_1_1_1; p_1_1_2; p_1_1_3]; 

 myplot=plot(t,P_1_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p_0=p_1_1_0(find(t==2500));
 s=strcat('{\it p} _{\it{i}}^{(1)}({\itx_i,t})');
 X=[2500, 2750]; Y=[p_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_1=p_1_1_1(find(t==2250));
 s=strcat('{\it p} _{\it{i}}^{(2)}({\itx_i,t})');
 X=[2250, 2750]; Y=[p_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_2=p_1_1_2(find(t==1250));
 s=strcat('{\it p} _{\it{i}}^{(3)}({\itx_i,t})');
 X=[1250, 2750]; Y=[p_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_3=p_1_1_3(find(t==750));
 s=strcat('{\it p} _{\it{i}}^{(4)}({\itx_i,t})');
 X=[750, 2750]; Y=[p_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
% xlabel('{\itx_i}=(1,3)','Fontsize',16,'FontName','Euclid');
 print -dmeta comp_version_1_3

 % cold-redundancy  version #2 + version #1
 p_1_1_0= pi_1_0 .* pi_0_0 %(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 p_1_1_1= pi_1_1 + pi_1_0 .* pi_0_1 %(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 p_1_1_2= pi_1_2 + pi_1_0 .* pi_0_2 %(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 p_1_1_3= pi_1_3 + pi_1_0 .* pi_0_3 %0.978000.*exp(-0.00100000*t)
 
 P_1_1=[p_1_1_0; p_1_1_1; p_1_1_2; p_1_1_3]; 

 myplot=plot(t,P_1_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p_0=p_1_1_0(find(t==2500));
 s=strcat('{\it p} _{\it{i}}^{(1)}({\itx_i,t})');
 X=[2500, 2750]; Y=[p_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_1=p_1_1_1(find(t==2250));
 s=strcat('{\it p} _{\it{i}}^{(2)}({\itx_i,t})');
 X=[2250, 2750]; Y=[p_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_2=p_1_1_2(find(t==1250));
 s=strcat('{\it p} _{\it{i}}^{(3)}({\itx_i,t})');
 X=[1250, 2750]; Y=[p_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_3=p_1_1_3(find(t==750));
 s=strcat('{\it p} _{\it{i}}^{(4)}({\itx_i,t})');
 X=[750, 2750]; Y=[p_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
% xlabel('{\itx_i}=(1,2)','Fontsize',16,'FontName','Euclid');
 print -dmeta comp_version_2_1

% cold-redundancy  version #2 + version #3
 p_1_1_0= pi_1_0 .* pi_2_0 %(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 p_1_1_1= pi_1_1 + pi_1_0 .* pi_2_1 %(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 p_1_1_2= pi_1_2 + pi_1_0 .* pi_2_2 %(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 p_1_1_3= pi_1_3 + pi_1_0 .* pi_2_3 %0.978000.*exp(-0.00100000*t)
 
 P_1_1=[p_1_1_0; p_1_1_1; p_1_1_2; p_1_1_3]; 

 myplot=plot(t,P_1_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p_0=p_1_1_0(find(t==2500));
 s=strcat('{\it p} _{\it{i}}^{(1)}({\itx_i,t})');
 X=[2500, 2750]; Y=[p_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_1=p_1_1_1(find(t==2250));
 s=strcat('{\it p} _{\it{i}}^{(2)}({\itx_i,t})');
 X=[2250, 2750]; Y=[p_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_2=p_1_1_2(find(t==1250));
 s=strcat('{\it p} _{\it{i}}^{(3)}({\itx_i,t})');
 X=[1250, 2750]; Y=[p_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_3=p_1_1_3(find(t==750));
 s=strcat('{\it p} _{\it{i}}^{(4)}({\itx_i,t})');
 X=[750, 2750]; Y=[p_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
% xlabel('{\itx_i}=(1,3)','Fontsize',16,'FontName','Euclid');
 print -dmeta comp_version_2_3

 % cold-redundancy  version #3 + version #1
 p_1_1_0= pi_2_0 .* pi_0_0 %(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 p_1_1_1= pi_2_1 + pi_2_0 .* pi_0_1 %(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 p_1_1_2= pi_2_2 + pi_2_0 .* pi_0_2 %(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 p_1_1_3= pi_2_3 + pi_2_0 .* pi_0_3 %0.978000.*exp(-0.00100000*t)
 
 P_1_1=[p_1_1_0; p_1_1_1; p_1_1_2; p_1_1_3]; 

 myplot=plot(t,P_1_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p_0=p_1_1_0(find(t==2250));
 s=strcat('{\it p} _{\it{i}}^{(1)}({\itx_i,t})');
 X=[2250, 2750]; Y=[p_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_1=p_1_1_1(find(t==1750));
 s=strcat('{\it p} _{\it{i}}^{(2)}({\itx_i,t})');
 X=[1750, 2750]; Y=[p_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_2=p_1_1_2(find(t==1250));
 s=strcat('{\it p} _{\it{i}}^{(3)}({\itx_i,t})');
 X=[1250, 2750]; Y=[p_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_3=p_1_1_3(find(t==750));
 s=strcat('{\it p} _{\it{i}}^{(4)}({\itx_i,t})');
 X=[750, 2750]; Y=[p_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
% xlabel('{\itx_i}=(1,3)','Fontsize',16,'FontName','Euclid');
 print -dmeta comp_version_3_1
 
 % cold-redundancy  version #3 + version #2
 p_1_1_0= pi_2_0 .* pi_1_0 %(-0.652000).*exp(-0.00100000*t)+(7.90400).*exp(-0.000500000*t)+(-8.25100).*exp(-0.000400000*t)+(1.00000)
 p_1_1_1= pi_2_1 + pi_2_0 .* pi_1_1 %(1.63000).*exp(-0.00100000*t)+(-9.88000).*exp(-0.000500000*t)+(8.25100).*exp(-0.000400000*t)
 p_1_1_2= pi_2_2 + pi_2_0 .* pi_1_2 %(-1.95600).*exp(-0.00100000*t)+(1.97600).*exp(-0.000500000*t)
 p_1_1_3= pi_2_3 + pi_2_0 .* pi_1_3 %0.978000.*exp(-0.00100000*t)
 
 P_1_1=[p_1_1_0; p_1_1_1; p_1_1_2; p_1_1_3]; 

 myplot=plot(t,P_1_1,'-k','LineWidth',2);  box on;  axis([0.00000 5000.00 0.0 1.0]); grid off; 
 %xlabel('\itt')
 p_0=p_1_1_0(find(t==2250));
 s=strcat('{\it p} _{\it{i}}^{(1)}({\itx_i,t})');
 X=[2250, 2750]; Y=[p_0 , 0.550000];
 text(2750, 0.550000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_1=p_1_1_1(find(t==1750));
 s=strcat('{\it p} _{\it{i}}^{(2)}({\itx_i,t})');
 X=[1750, 2750]; Y=[p_1 , 0.670000];
 text(2750, 0.670000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_2=p_1_1_2(find(t==1250));
 s=strcat('{\it p} _{\it{i}}^{(3)}({\itx_i,t})');
 X=[1250, 2750]; Y=[p_2 , 0.790000];
 text(2750, 0.790000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
 p_3=p_1_1_3(find(t==750));
 s=strcat('{\it p} _{\it{i}}^{(4)}({\itx_i,t})');
 X=[750, 2750]; Y=[p_3 , 0.910000];
 text(2750, 0.910000,s, 'Fontsize',fs,'Fontname',fn); line(X,Y);
% xlabel('{\itx_i}=(1,3)','Fontsize',16,'FontName','Euclid');
 print -dmeta comp_version_3_2