data = rand(500,2);
options = [3.0 NaN NaN 0];
subplot(1,3,1);
[centers3,U] = fcm(data,3,options);
maxU3 = max(U);
index3_1 = find(U(1,:) == maxU3);
index3_2 = find(U(2,:) == maxU3);
index3_3 = find(U(3,:) == maxU3);
plot(data(index3_1,1),data(index3_1,2),'ob')
hold on
plot(data(index3_2,1),data(index3_2,2),'or')
plot(data(index3_3,1),data(index3_3,2),'og')
plot(centers3(1,1),centers3(1,2),'xb','MarkerSize',15,'LineWidth',3)
plot(centers3(2,1),centers3(2,2),'xr','MarkerSize',15,'LineWidth',3)
plot(centers3(3,1),centers3(3,2),'xg','MarkerSize',15,'LineWidth',3)
xlabel('C = 3')
hold off
subplot(1,3,2);
[centers5,U] = fcm(data,5,options);
maxU5 = max(U);
index5_1 = find(U(1,:) == maxU5);
index5_2 = find(U(2,:) == maxU5);
index5_3 = find(U(3,:) == maxU5);
index5_4 = find(U(4,:) == maxU5);
index5_5 = find(U(5,:) == maxU5);
plot(data(index5_1,1),data(index5_1,2),'ob')
hold on
plot(data(index5_2,1),data(index5_2,2),'or')
plot(data(index5_3,1),data(index5_3,2),'og')
plot(data(index5_4,1),data(index5_4,2),'oc')
plot(data(index5_5,1),data(index5_5,2),'om')
plot(centers5(1,1),centers5(1,2),'xb','MarkerSize',15,'LineWidth',3)
plot(centers5(2,1),centers5(2,2),'xr','MarkerSize',15,'LineWidth',3)
plot(centers5(3,1),centers5(3,2),'xg','MarkerSize',15,'LineWidth',3)
plot(centers5(4,1),centers5(4,2),'xc','MarkerSize',15,'LineWidth',3)
plot(centers5(5,1),centers5(5,2),'xm','MarkerSize',15,'LineWidth',3)
xlabel('C = 5')
hold off
subplot(1,3,3);
[centers7,U] = fcm(data,7,options);
maxU7 = max(U);
index7_1 = find(U(1,:) == maxU7);
index7_2 = find(U(2,:) == maxU7);
index7_3 = find(U(3,:) == maxU7);
index7_4 = find(U(4,:) == maxU7);
index7_5 = find(U(5,:) == maxU7);
index7_6 = find(U(6,:) == maxU7);
index7_7 = find(U(7,:) == maxU7);
plot(data(index7_1,1),data(index7_1,2),'ob')
hold on
plot(data(index7_2,1),data(index7_2,2),'or')
plot(data(index7_3,1),data(index7_3,2),'og')
plot(data(index7_4,1),data(index7_4,2),'oc')
plot(data(index7_5,1),data(index7_5,2),'om')
plot(data(index7_6,1),data(index7_6,2),'ok')
plot(data(index7_7,1),data(index7_7,2),'oy')
plot(centers7(1,1),centers7(1,2),'xb','MarkerSize',15,'LineWidth',3)
plot(centers7(2,1),centers7(2,2),'xr','MarkerSize',15,'LineWidth',3)
plot(centers7(3,1),centers7(3,2),'xg','MarkerSize',15,'LineWidth',3)
plot(centers7(4,1),centers7(4,2),'xc','MarkerSize',15,'LineWidth',3)
plot(centers7(5,1),centers7(5,2),'xm','MarkerSize',15,'LineWidth',3)
plot(centers7(6,1),centers7(6,2),'xk','MarkerSize',15,'LineWidth',3)
plot(centers7(7,1),centers7(7,2),'xy','MarkerSize',15,'LineWidth',3)
xlabel('C = 7')
hold off