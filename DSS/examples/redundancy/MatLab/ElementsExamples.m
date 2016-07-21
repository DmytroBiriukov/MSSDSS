% (1) Prepare your data
t = 0:0.5:5000;
%Type 1 (white).
p11=-0.1397* exp (-0.0008* t)+0.6587* exp (-0.0004* t)-1.518* exp (-0.0001* t)+1 ;
p12=1.1177* exp (-0.0008* t)-2.6347* exp (-0.0004* t)+1.518* exp (-0.0001* t) ;
p13=-1.956* exp (-0.0008* t)+1.976* exp (-0.0004* t) ;
p14=0.978* exp (-0.0008* t) ;
p15=p11+p12+p13+p14;
%Type 2 (lined).
p21=-0.652* exp (-0.001* t)+7.904* exp (-0.0005* t)-8.251* exp (-0.0004* t)+1 ;
p22=1.63* exp (-0.001* t)-9.88* exp (-0.0005* t)+8.251* exp (-0.0004* t) ;
p23=-1.956* exp (-0.001* t)+1.976* exp (-0.0005* t) ;
p24=0.978* exp (-0.001* t) ;
p25=p21+p22+p23+p24;
%Type 2 (grey).
p31=-1.63* exp (-0.0008* t)+9.88* exp (-0.0004* t)+10.511* exp (-0.0005* t)+1 ;
p32=2.608* exp (-0.0008* t)+7.904* exp (-0.0004* t)-10.511* exp (-0.0005* t) ;
p33=-1.956* exp (-0.0008* t)+1.976* exp (-0.0004* t) ;
p34=0.978* exp (-0.0008* t) ;
p35=p31+p32+p33+p34;

%h3=plot(t,p31,t,p32,t,p33,t,p34, t, p35);
text(500, p34(find(t==500)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
text(2500, p33(find(t==2500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
text(1500, p32(find(t==1500)), '{\it p_i}^{(2)}({\itt})\rightarrow','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','right');
text(4000, p31(find(t==4000)), '\leftarrow{\it p_i}^{(1)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
box off
axis([0 5000 0.0 1.0])
axis manual

%h2=plot(t,p21,t,p22,t,p23,t,p24);
text(100, p24(find(t==100)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
text(1500, p23(find(t==1500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
text(2000, p22(find(t==2000)), '\leftarrow{\it p_i}^{(2)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
text(2500, p21(find(t==2500)), '\leftarrow{\it p_i}^{(1)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
box off
axis([0 5000 0.0 1.0])
axis manual

h1=plot(t,p11,t,p12,t,p13,t,p14);
text(200, p14(find(t==200)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
text(1500, p13(find(t==1500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
text(3500, p12(find(t==3500)), '\leftarrow{\it p_i}^{(2)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
text(5000, p11(find(t==5000)), '{\it p_i}^{(1)}({\itt})\rightarrow','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','right');
box off
axis([0 5000 0.0 1.0])
axis manual
print -dmeta elplot1