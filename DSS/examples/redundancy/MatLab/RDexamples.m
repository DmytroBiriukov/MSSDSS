% (1) Prepare your data
t = 0:0.5:5000;
%fn='Euclid';
fs=18;
fn='Times';
%fs=18;

%RD1 - x_i=(2,0,0)
p11 = 0.0195201* exp(-0.0016* t)-1.99965* exp(-0.0005* t)-0.18405* exp(-0.0012* t)+1+0.154413* exp(-0.0008* t)+1.31733* exp(-0.0004* t)-3.0359* exp(-0.0001* t)+2.30418* exp(-0.0002* t)+0.424159* exp(-0.0009* t);
p12 = 3.0359* exp(-0.0001* t)+1.99965* exp(-0.0005* t)-3.68101* exp(-0.0012* t)+0.936964* exp(-0.0016* t)-2.30418* exp(-0.0002* t)+5.70616* exp(-0.0008* t)-5.26933* exp(-0.0004* t)-0.424159* exp(-0.0009* t);
p13 = -5.47685e-11* exp(-0.0016* t)+3.952* exp(-0.0004* t)+3.86506* exp(-0.0012* t)-7.81658* exp(-0.0008* t);
p14 = 1.1736e-08* exp(-0.0012* t)+1.956* exp(-0.0008* t)-0.956484* exp(-0.0016* t);

%text(500, p14(find(t==500)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p13(find(t==2500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
%text(3500, p12(find(t==3500)), '\leftarrow{\it p_i}^{(2)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p11(find(t==2500)), '{\it p_i}^{(1)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
P_1_1=[p11;p12;p13;p14]; myplot=plot(t,P_1_1,'-k','LineWidth',2); box on; axis([0.00000 5000.00 0.0 1.0]); grid off; 
%xlabel('\itt')

p_0=p11(find(t==3500));
s=strcat(' {\it p} _{\it{i}}^{(1)}({\itx_i,t})');
X=[3500, 3850]; Y=[p_0 , 0.550000];
text(3850, 0.550000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_1=p12(find(t==3000));
s=strcat(' {\it p} _{\it{i}}^{(2)}({\itx_i,t})');
X=[3000, 3850]; Y=[p_1 , 0.670000];
text(3850, 0.670000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_2=p13(find(t==2000));
s=strcat(' {\it p} _{\it{i}}^{(3)}({\itx_i,t})');
X=[2000, 3850]; Y=[p_2 , 0.790000];
text(3850, 0.790000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_3=p14(find(t==750));
s=strcat(' {\it p} _{\it{i}}^{(4)}({\itx_i,t})');
X=[750, 3850]; Y=[p_3 , 0.910000];
text(3850, 0.910000,s,'Fontsize',16,'Fontname',fn); line(X,Y);

print -dmeta active_redundancy_version_2_0_0

%RD2 - x_i=(0,2,0)
p21 = -10.3068* exp(-0.0015* t)+10.7593* exp(-0.0014* t)-130.432* exp(-0.0009* t)+1+61.1692* exp(-0.001* t)+15.808* exp(-0.0005* t)-16.502* exp(-0.0004* t)+68.079* exp(-0.0008* t)+0.425104* exp(-0.002* t);
p22 = 16.502* exp(-0.0004* t)+130.432* exp(-0.0009* t)+6.44176* exp(-0.0015* t)+0.53138* exp(-0.002* t)-68.079* exp(-0.0008* t)-55.3086* exp(-0.001* t)-19.76* exp(-0.0005* t)-10.7593* exp(-0.0014* t);
p23 =  4.44089e-16* exp(-0.002* t)+3.952* exp(-0.0005* t)+3.86506* exp(-0.0015* t)-7.81658* exp(-0.001* t);
p24 =  -1.73728e-15* exp(-0.0015* t)+1.956* exp(-0.001* t)-0.956484* exp(-0.002* t);

%text(500, p24(find(t==500)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p23(find(t==2500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
%text(3000, p22(find(t==3000)), '\leftarrow{\it p_i}^{(2)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(4000, p21(find(t==4000)), '\leftarrow{\it p_i}^{(1)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');

P_1_1=[p21;p22;p23;p24]; myplot=plot(t,P_1_1,'-k','LineWidth',2); box on; axis([0.00000 5000.00 0.0 1.0]); grid off; 
%xlabel('\itt')

p_0=p21(find(t==3500));
s=strcat(' {\it p} _{\it{i}}^{(1)}({\itx_i,t})');
X=[3500, 3850]; Y=[p_0 , 0.550000];
text(3850, 0.550000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_1=p22(find(t==3000));
s=strcat(' {\it p} _{\it{i}}^{(2)}({\itx_i,t})');
X=[3000, 3850]; Y=[p_1 , 0.670000];
text(3850, 0.670000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_2=p23(find(t==2000));
s=strcat(' {\it p} _{\it{i}}^{(3)}({\itx_i,t})');
X=[2000, 3850]; Y=[p_2 , 0.790000];
text(3850, 0.790000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_3=p24(find(t==750));
s=strcat(' {\it p} _{\it{i}}^{(4)}({\itx_i,t})');
X=[750, 3850]; Y=[p_3 , 0.910000];
text(3850, 0.910000,s,'Fontsize',16,'Fontname',fn); line(X,Y);

print -dmeta active_redundancy_version_0_2_0

%RD3 - x_i=(0,0,2)
p31 = 32.2088* exp(-0.0012* t)-34.2659* exp(-0.0013* t)-207.697*exp(-0.0009* t)+1+94.3544* exp(-0.0008* t)-19.76* exp(-0.0004* t)+21.022* exp(-0.0005* t)+110.481* exp(-0.001* t)+2.6569* exp(-0.0016* t);
p32 = -21.022* exp(-0.0005* t)+207.697* exp(-0.0009* t)-36.0739*exp(-0.0012* t)-1.70042* exp(-0.0016* t)-110.481* exp(-0.001* t)-88.4938* exp(-0.0008* t)+15.808* exp(-0.0004* t)+34.2659* exp(-0.0013* t);
p33 =-8.88178e-16* exp(-0.0016* t)+3.952* exp(-0.0004* t)+3.86506* exp(-0.0012* t)-7.81658* exp(-0.0008* t); 
p34 =-1.73728e-15* exp(-0.0012* t)+1.956* exp(-0.0008* t)-0.956484*exp(-0.0016* t);

%text(500, p34(find(t==500)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p33(find(t==2500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
%text(2500, p32(find(t==2500)), '{\it p_i}^{(2)}({\itt})\rightarrow','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','right');
%text(4000, p31(find(t==4000)), '\leftarrow{\it p_i}^{(1)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
P_1_1=[p31;p32;p33;p34]; myplot=plot(t,P_1_1,'-k','LineWidth',2); box on; axis([0.00000 5000.00 0.0 1.0]); grid off; 
%xlabel('\itt')

p_0=p31(find(t==3500));
s=strcat(' {\it p} _{\it{i}}^{(1)}({\itx_i,t})');
X=[3500, 3850]; Y=[p_0 , 0.550000];
text(3850, 0.550000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_1=p32(find(t==3000));
s=strcat(' {\it p} _{\it{i}}^{(2)}({\itx_i,t})');
X=[3000, 3850]; Y=[p_1 , 0.670000];
text(3850, 0.670000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_2=p33(find(t==2000));
s=strcat(' {\it p} _{\it{i}}^{(3)}({\itx_i,t})');
X=[2000, 3850]; Y=[p_2 , 0.790000];
text(3850, 0.790000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_3=p34(find(t==750));
s=strcat(' {\it p} _{\it{i}}^{(4)}({\itx_i,t})');
X=[750, 3850]; Y=[p_3 , 0.910000];
text(3850, 0.910000,s,'Fontsize',16,'Fontname',fn); line(X,Y);

print -dmeta active_redundancy_version_0_0_2


%RD4 - x_i=(1,1,0)
p41 =-1.1043* exp(-0.0013* t)+5.2061* exp(-0.0009* t)-0.429451* exp(-0.0014* t) -11.9979* exp(-0.0006* t)+1-5.57437* exp(-0.0008* t)-7.59233* exp(-0.0004* t)-1.51795* exp(-0.0001* t)-0.652* exp(-0.001* t)+0.0910937* exp(-0.0018* t)+1.15278* exp(-0.0012* t)+0.989705* exp(-0.0011* t)+20.4286* exp(-0.0005* t)
p42 = -0.989705* exp(-0.0011* t)+11.9979* exp(-0.0006* t)-1.15278* exp(-0.0012* t)-1.30153* exp(-0.0009* t)-0.828226* exp(-0.0013* t)-22.4046* exp(-0.0005* t)+1.51795* exp(-0.0001* t)+6.55237* exp(-0.0008* t)+5.61633* exp(-0.0004* t)+1.63* exp(-0.001* t)+0.86539* exp(-0.0018* t)-1.50308* exp(-0.0014* t)
p43 =1.93253* exp(-0.0013* t)+1.976* exp(-0.0005* t)+1.93253* exp(-0.0014* t)-2.7384e-11* exp(-0.0018* t)-3.90458* exp(-0.0009* t)-1.956* exp(-0.0008* t)+1.976* exp(-0.0004* t)-1.956* exp(-0.001* t)
p44 =5.868e-09* exp(-0.0014* t)+0.978* exp(-0.0008* t)-8.68638e-16* exp(-0.0013* t)+0.978* exp(-0.001* t)-0.956484* exp(-0.0018* t)

P_1_1=[p41;p42;p43;p44]; myplot=plot(t,P_1_1,'-k','LineWidth',2); box on; axis([0.00000 5000.00 0.0 1.0]); grid off; 
%xlabel('\itt')

p_0=p41(find(t==3500));
s=strcat(' {\it p} _{\it{i}}^{(1)}({\itx_i,t})');
X=[3500, 3850]; Y=[p_0 , 0.550000];
text(3850, 0.550000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_1=p42(find(t==3000));
s=strcat(' {\it p} _{\it{i}}^{(2)}({\itx_i,t})');
X=[3000, 3850]; Y=[p_1 , 0.670000];
text(3850, 0.670000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_2=p43(find(t==2000));
s=strcat(' {\it p} _{\it{i}}^{(3)}({\itx_i,t})');
X=[2000, 3850]; Y=[p_2 , 0.790000];
text(3850, 0.790000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_3=p44(find(t==750));
s=strcat(' {\it p} _{\it{i}}^{(4)}({\itx_i,t})');
X=[750, 3850]; Y=[p_3 , 0.910000];
text(3850, 0.910000,s,'Fontsize',16,'Fontname',fn); line(X,Y);

print -dmeta active_redundancy_version_1_1_0

%RD5 - x_i=(0,1,1)
p51 =-12.8835* exp(-0.0013* t)+13.4491* exp(-0.0012* t)-6.85317* exp(-0.0015* t)+1+82.4269* exp(-0.001* t)+18.415* exp(-0.0005* t)-18.131* exp(-0.0004* t)+79.8899* exp(-0.0008* t)+1.06276* exp(-0.0018* t)-164.818* exp(-0.0009* t)+6.44176* exp(-0.0014* t)
p52 =6.85317* exp(-0.0015* t)+168.722* exp(-0.0009* t)-8.37429* exp(-0.0014* t)+16.155* exp(-0.0004* t)+10.951* exp(-0.0013* t)-13.4491* exp(-0.0012* t)-81.4489* exp(-0.001* t)-20.391* exp(-0.0005* t)-78.9119* exp(-0.0008* t)-0.106276* exp(-0.0018* t)
p53 =1.93253* exp(-0.0014* t)+1.976* exp(-0.0004* t)+1.93253* exp(-0.0013* t)-2.22045e-16* exp(-0.0018* t)-3.90458* exp(-0.0009* t)-1.956* exp(-0.001* t)+1.976* exp(-0.0005* t)-1.956* exp(-0.0008* t)
p54 =-8.68638e-16* exp(-0.0013* t)+0.978* exp(-0.001* t)-8.68638e-16* exp(-0.0014* t)+0.978* exp(-0.0008* t)-0.956484* exp(-0.0018* t)

P_1_1=[p51;p52;p53;p54]; myplot=plot(t,P_1_1,'-k','LineWidth',2); box on; axis([0.00000 5000.00 0.0 1.0]); grid off; 
%xlabel('\itt')

p_0=p51(find(t==3700));
s=strcat(' {\it p} _{\it{i}}^{(1)}({\itx_i,t})');
X=[3700, 3850]; Y=[p_0 , 0.550000];
text(3850, 0.550000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_1=p52(find(t==3000));
s=strcat(' {\it p} _{\it{i}}^{(2)}({\itx_i,t})');
X=[3000, 3850]; Y=[p_1 , 0.670000];
text(3850, 0.670000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_2=p53(find(t==2000));
s=strcat(' {\it p} _{\it{i}}^{(3)}({\itx_i,t})');
X=[2000, 3850]; Y=[p_2 , 0.790000];
text(3850, 0.790000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_3=p54(find(t==750));
s=strcat(' {\it p} _{\it{i}}^{(4)}({\itx_i,t})');
X=[750, 3850]; Y=[p_3 , 0.910000];
text(3850, 0.910000,s,'Fontsize',16,'Fontname',fn); line(X,Y);

print -dmeta active_redundancy_version_0_1_1

%RD6 - x_i=(1,0,1)
p61 =25.5084* exp(-0.0005* t)+0.227734* exp(-0.0016* t)+6.92325* exp(-0.0009* t)+1-8.27734* exp(-0.0008* t)-9.22133* exp(-0.0004* t)-1.51795* exp(-0.0001* t)-15.9552* exp(-0.0006* t)-1.46854* exp(-0.0013* t)+0.30675* exp(-0.0012* t)+2.47426* exp(-0.0009* t)
p62 =1.51795* exp(-0.0001* t)-2.47426* exp(-0.0009* t)+1.46854* exp(-0.0013* t)-6.92325* exp(-0.0009* t)-4.17181* exp(-0.0012* t)+15.9552* exp(-0.0006* t)+14.1379* exp(-0.0008* t)+5.26933* exp(-0.0004* t)-25.5084* exp(-0.0005* t)+0.72875* exp(-0.0016* t)
p63 =-2.73847e-11* exp(-0.0016* t)+3.952* exp(-0.0004* t)+3.86506* exp(-0.0012* t)-7.81658* exp(-0.0008* t)
p64 =5.868e-09* exp(-0.0012* t)+1.956* exp(-0.0008* t)-0.956484* exp(-0.0016* t)

P_1_1=[p61;p62;p63;p64]; myplot=plot(t,P_1_1,'-k','LineWidth',2); box on; axis([0.00000 5000.00 0.0 1.0]); grid off; 
%xlabel('\itt')

p_0=p61(find(t==3500));
s=strcat(' {\it p} _{\it{i}}^{(1)}({\itx_i,t})');
X=[3500, 3850]; Y=[p_0 , 0.550000];
text(3850, 0.550000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_1=p62(find(t==3000));
s=strcat(' {\it p} _{\it{i}}^{(2)}({\itx_i,t})');
X=[3000, 3850]; Y=[p_1 , 0.670000];
text(3850, 0.670000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_2=p63(find(t==2000));
s=strcat(' {\it p} _{\it{i}}^{(3)}({\itx_i,t})');
X=[2000, 3850]; Y=[p_2 , 0.790000];
text(3850, 0.790000,s,'Fontsize',16,'Fontname',fn); line(X,Y);
p_3=p64(find(t==750));
s=strcat(' {\it p} _{\it{i}}^{(4)}({\itx_i,t})');
X=[750, 3850]; Y=[p_3 , 0.910000];
text(3850, 0.910000,s,'Fontsize',16,'Fontname',fn); line(X,Y);

print -dmeta active_redundancy_version_1_0_1

% version_4
%text(500, p44(find(t==500)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p43(find(t==2500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
%text(3500, p42(find(t==3500)), '\leftarrow{\it p_i}^{(2)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p41(find(t==2500)), '{\it p_i}^{(1)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');

% version_5
%text(500, p54(find(t==500)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p53(find(t==2500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
%text(3500, p52(find(t==3500)), '\leftarrow{\it p_i}^{(2)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(4000, p51(find(t==4000)), '\leftarrow{\it p_i}^{(1)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');

% version_6
%text(500, p64(find(t==500)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p63(find(t==2500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
%text(3500, p62(find(t==3500)), '\leftarrow{\it p_i}^{(2)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p31(find(t==2500)), '{\itp_i}^{(1)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');