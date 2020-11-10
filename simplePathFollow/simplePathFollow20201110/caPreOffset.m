function preOffset = caPreOffset(oriPoint, vehLo, distXY,preDist)

%% ���㳵����ǰ����λ�õ�ȫ������
vehGlobal = [0 0 vehLo(3)];
[vehGlobal(1), vehGlobal(2)] = latlon2global(oriPoint,vehLo);

% hold on
% plot(vehGlobal(1), vehGlobal(2),'*')

% ����ο��켣�ڳ�������ϵ�µ�����
vehXY = zeros(length(distXY(:,1)),3);
for i = 1:1:length(distXY(:,1))

[vehXYTemp]= global2vehXY(distXY(i,1),distXY(i,2),vehGlobal(1),vehGlobal(2),vehGlobal(3));
vehXY(i,:) = vehXYTemp;
end

plot(vehXY(:,2),vehXY(:,1))
set(gca,'XDir','reverse')%��X����ת
xlabel('Y');
ylabel('X');


% ����Ԥ��㴦��ο��켣��ƫ�ƣ�ʹ����ϵķ���

% preDist = 4; % Ԥ����루����ں���ģ�

p2 = spline(vehXY(:,1),vehXY(:,2));
preOffset = ppval(p2,preDist); % Ԥ��㴦�ڲο��ߵ�ƫ��
end