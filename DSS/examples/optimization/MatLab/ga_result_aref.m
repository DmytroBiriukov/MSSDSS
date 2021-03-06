function createfigure(X1, ymatrix1)
%CREATEFIGURE(X1,YMATRIX1)
%  X1:  stairs x
%  YMATRIX1:  stairs matrix data

%  Auto-generated by MATLAB on 06-Sep-2009 18:43:19

% Create figure
figure1 = figure('PaperSize',[20.98 29.68]);

% Create axes
axes1 = axes('Parent',figure1,...
    'XTickLabel',{'0','','','','','5','','','','','10','','','','','15','','','','','20','','','','','25','','','','','30','','','','','35','','','','','40'},...
    'XTick',[0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40]);
% Uncomment the following line to preserve the X-limits of the axes
% xlim([0 40]);
% Uncomment the following line to preserve the Y-limits of the axes
% ylim([0 80]);
grid('on');
hold('all');

% Create text
text('Parent',axes1,'String','{\itf_0^*_h}','Position',[1.738 37.51 17.32],...
    'FontSize',14,...
    'FontName','Euclid',...
    'BackgroundColor',[1 1 1]);

% Create xlabel
xlabel('\it{h}','FontSize',14,'FontName','Euclid');

% Create text
text('Parent',axes1,'String','{\itf_{0h}}','Position',[20 28.77 17.32],...
    'FontSize',14,...
    'FontName','Euclid',...
    'BackgroundColor',[1 1 1]);

% Create multiple lines using matrix input to stairs
stairs1 = stairs(X1,ymatrix1,'LineWidth',2);
set(stairs1(1),'Color',[0 0.5 0]);
set(stairs1(2),'Color',[0 0 1]);

% Create line
annotation(figure1,'line',[0.5079 0.587],[0.4949 0.4905]);

% Create line
annotation(figure1,'line',[0.5167 0.5487],[0.4669 0.4667]);

% Create line
annotation(figure1,'line',[0.1681 0.2271],[0.581 0.5857]);

% Create arrow
annotation(figure1,'arrow',[0.2301 0.3248],[0.5095 0.833],'LineWidth',2);

% Create arrow
annotation(figure1,'arrow',[0.4985 0.351],[0.4038 0.6476],'LineWidth',2);

