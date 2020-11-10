function [distX, distY] = latlon2global(oriPoint,point)
Rc = 6378137; % ³àµÀ°ë¾¶
Rj = 6356725; % ¼«°ë¾¶

distX = Rc.*cos(oriPoint(1)*pi/180).*(point(:,2)-oriPoint(2)).*pi/180;
distY = Rj.*(point(:,1)-oriPoint(1)).*pi/180;


end