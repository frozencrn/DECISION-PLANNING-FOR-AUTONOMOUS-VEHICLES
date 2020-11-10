function preOffset = caPreOffset(oriPoint, vehLo, distXY,preDist)

%% 计算车辆当前所处位置的全局坐标
vehGlobal = [0 0 vehLo(3)];
[vehGlobal(1), vehGlobal(2)] = latlon2global(oriPoint,vehLo);

% hold on
% plot(vehGlobal(1), vehGlobal(2),'*')

% 计算参考轨迹在车辆坐标系下的坐标
vehXY = zeros(length(distXY(:,1)),3);
for i = 1:1:length(distXY(:,1))

[vehXYTemp]= global2vehXY(distXY(i,1),distXY(i,2),vehGlobal(1),vehGlobal(2),vehGlobal(3));
vehXY(i,:) = vehXYTemp;
end

plot(vehXY(:,2),vehXY(:,1))
set(gca,'XDir','reverse')%对X方向反转
xlabel('Y');
ylabel('X');


% 计算预瞄点处与参考轨迹的偏移，使用拟合的方法

% preDist = 4; % 预瞄距离（相对于后轴的）

p2 = spline(vehXY(:,1),vehXY(:,2));
preOffset = ppval(p2,preDist); % 预瞄点处于参考线的偏移
end