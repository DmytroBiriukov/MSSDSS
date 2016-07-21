x = [1,2,4,5,6,7,9,10,11,12,13,14,15];
y1 =[0.78, 0.78, 0.8, 0.86, 0.88, 0.89, 0.92,0.93,0.94,0.96, 0.96, 0.96, 0.96];
y2 = bessel(2,x);

h = plot(x,y1,x,y2);

axis([0 40 0.0 1.0])
grid on

text(x(ix),y,'First Min \rightarrow','HorizontalAlignment','right')
%print -depsc -tiff -r200 myplot