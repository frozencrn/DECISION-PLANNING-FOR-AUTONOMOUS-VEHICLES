function [vehXY] = global2vehXY(globalX,globalY,vehX,vehY,vehYaw)
% [ȫ�������µ�X ȫ�������µ�Y ��������ȫ��λ��X ��������ȫ��Y ���������]
% ���[X Y theta]
alpha = vehYaw*pi/180;
vehXYTemp = [sin(alpha) cos(alpha);cos(alpha) -sin(alpha)]\[globalX-vehX;globalY-vehY];
vehXYTemp = flip(vehXYTemp)';
vehXYTemp(:,1) = -vehXYTemp(:,1);
% ���ڸ�·�����µĲο�ƫ�ǣ����������£�������
theta = zeros(length(globalX),1);
for i = 2:1:length(globalX)
    theta(i) = atan((vehXYTemp(i,2)-vehXYTemp(i-1,2))/(vehXYTemp(i,1)-vehXYTemp(i-1,1)));
end
vehXY = [fliplr(vehXYTemp) -theta*180/pi];

end


% function [vehXY] = global2vehXY(globalX,globalY,vehX,vehY,vehYaw)
% % [ȫ�������µ�X ȫ�������µ�Y ��������ȫ��λ��X ��������ȫ��Y ���������]
% alpha = vehYaw*pi/180;
% vehXYTemp = [sin(alpha) cos(alpha);cos(alpha) -sin(alpha)]\[globalX-vehX;globalY-vehY];
% vehXYTemp = flip(vehXYTemp)';
% vehXYTemp(:,2) = vehXYTemp(:,2);
% % ���ڸ�·�����µĲο�ƫ�ǣ����������£�������
% theta = zeros(length(globalX),1);
% for i = 2:1:length(globalX)
%     theta(i) = atan((vehXYTemp(i,2)-vehXYTemp(i-1,2))/(vehXYTemp(i,1)-vehXYTemp(i-1,1)));
% end
% vehXY = [vehXYTemp -theta*180/pi];
% 
% end