function [vehXY] = global2vehXY(globalX,globalY,vehX,vehY,vehYaw)
% [全局坐标下的X 全局坐标下的Y 车辆所处全局位置X 车辆所处全局Y 车辆航向角]
% 输出[X Y theta]
alpha = vehYaw*pi/180;
vehXYTemp = [sin(alpha) cos(alpha);cos(alpha) -sin(alpha)]\[globalX-vehX;globalY-vehY];
vehXYTemp = flip(vehXYTemp)';
vehXYTemp(:,1) = -vehXYTemp(:,1);
% 求在各路径点下的参考偏角，车辆坐标下，弧度制
theta = zeros(length(globalX),1);
for i = 2:1:length(globalX)
    theta(i) = atan((vehXYTemp(i,2)-vehXYTemp(i-1,2))/(vehXYTemp(i,1)-vehXYTemp(i-1,1)));
end
vehXY = [fliplr(vehXYTemp) -theta*180/pi];

end


% function [vehXY] = global2vehXY(globalX,globalY,vehX,vehY,vehYaw)
% % [全局坐标下的X 全局坐标下的Y 车辆所处全局位置X 车辆所处全局Y 车辆航向角]
% alpha = vehYaw*pi/180;
% vehXYTemp = [sin(alpha) cos(alpha);cos(alpha) -sin(alpha)]\[globalX-vehX;globalY-vehY];
% vehXYTemp = flip(vehXYTemp)';
% vehXYTemp(:,2) = vehXYTemp(:,2);
% % 求在各路径点下的参考偏角，车辆坐标下，弧度制
% theta = zeros(length(globalX),1);
% for i = 2:1:length(globalX)
%     theta(i) = atan((vehXYTemp(i,2)-vehXYTemp(i-1,2))/(vehXYTemp(i,1)-vehXYTemp(i-1,1)));
% end
% vehXY = [vehXYTemp -theta*180/pi];
% 
% end