% (1) Prepare your data
%t = 0:0.5:5000;
t = 0:0.5:2500;
t2 = 2500:0.5:5000;
%RD1
p11 = -1.0*(0.0195201* exp(-0.0016* t)-1.99965* exp(-0.0005* t)-0.18405* exp(-0.0012* t)+1+0.154413* exp(-0.0008* t)+1.31733* exp(-0.0004* t)-3.0359* exp(-0.0001* t)+2.30418* exp(-0.0002* t)+0.424159* exp(-0.0009* t) );
p12 = 3.0359* exp(-0.0001* t)+1.99965* exp(-0.0005* t)-3.68101* exp(-0.0012* t)+0.936964* exp(-0.0016* t)-2.30418* exp(-0.0002* t)+5.70616* exp(-0.0008* t)-5.26933* exp(-0.0004* t)-0.424159* exp(-0.0009* t);
p13 = -5.47685e-11* exp(-0.0016* t)+3.952* exp(-0.0004* t)+3.86506* exp(-0.0012* t)-7.81658* exp(-0.0008* t);
p14 = 1.1736e-08* exp(-0.0012* t)+1.956* exp(-0.0008* t)-0.956484* exp(-0.0016* t);

p11_2 = -1.0*(0.0195201* exp(-0.0016* t2)-1.99965* exp(-0.0005* t2)-0.18405* exp(-0.0012* t2)+1+0.154413* exp(-0.0008* t2)+1.31733* exp(-0.0004* t2)-3.0359* exp(-0.0001* t2)+2.30418* exp(-0.0002* t2)+0.424159* exp(-0.0009* t2) );
p12_2 = 3.0359* exp(-0.0001* t2)+1.99965* exp(-0.0005* t2)-3.68101* exp(-0.0012* t2)+0.936964* exp(-0.0016* t2)-2.30418* exp(-0.0002* t2)+5.70616* exp(-0.0008* t2)-5.26933* exp(-0.0004* t2)-0.424159* exp(-0.0009* t2);
p13_2 = -5.47685e-11* exp(-0.0016* t2)+3.952* exp(-0.0004* t2)+3.86506* exp(-0.0012* t2)-7.81658* exp(-0.0008* t2);
p14_2 = 1.1736e-08* exp(-0.0012* t2)+1.956* exp(-0.0008* t2)-0.956484* exp(-0.0016* t2);

p15 = p14_2+p13_2;

%figure(1)
h1=plot(t,p11,t,p12,t,p13,t2,p11_2,t2,p12_2,t2,p13_2,t,p14,t2,p14_2,t2,p15);
%xlabel('a)','FontName','Times','Fontsize',28);
%text(500, p14(find(t==500)), '\leftarrow{\it p_i}^{(4)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p13(find(t==2500)), '{\it p_i}^{(3)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');
%text(3500, p12(find(t==3500)), '\leftarrow{\it p_i}^{(2)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','middle','HorizontalAlignment','left');
%text(2500, p11(find(t==2500)), '{\it p_i}^{(1)}({\itt})','FontName','Times','Fontsize',28,'VerticalAlignment','bottom','HorizontalAlignment','left');

annotation(h1,'textarrow',[0.2959 0.1982],[0.7755 0.463],'TextEdgeColor','none','Interpreter','latex','String','\sum_{s \in S}\int_{T} {I_{[u_s > w(t)]} p(t) dt}');

box off
axis([0 5000 0.0 1.0])

print -dmeta myplot