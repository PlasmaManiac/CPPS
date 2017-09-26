%%POLYNOMIALS
x = linspace(-5,5);


%degree 1:
figure(1);
p1 = 2*x;
plot(x,p1);

hold on;
hold off;

grid on;
ylabel('y');
xlabel('x');


%degree 2:
figure(2);
p2 = x.^2 - 1;
plot(x,p2);


grid on;
ylabel('y');
xlabel('x');


%degree 3:
figure(3);
p2 = x.^3 + 2*x.^2 - 1;
plot(x,p2);


grid on;
ylabel('y');
xlabel('x');

%% Interpolation Example:
close all;

x = [1 2 3 4 5];
y = [8 4 7 6 3];

x_cont = -0.5:0.1:5;

p = polyfit(x,y,6);



y_poly = polyval(p,0:0.1:6);
figure(1);


figure(4);
hold on;
plot(x,y,'o');

grid on;

axis([-0.5 5 -0.5 10]);
xlabel('x');
ylabel('y');

%%l0

l0 = 8*1/2*(x_cont.^2 - 5* x_cont + 6);
figure(1)
plot(x_cont,l0);
axis([0 6 0 9])
grid on
xlabel('x');
ylabel('y');
hold on;
plot(x,y,'o');


figure(4)
plot(x_cont,l0);
%l1 =

l1 = 4*(-x_cont.^2 + 4*x_cont -3);
figure(2)
plot(x_cont,l1);
axis([0 6 0 9])
grid on
axis([0 6 0 9])
xlabel('x');
ylabel('y');
hold on;
plot(x,y,'o');

figure(4)
plot(x_cont,l1);


%l2 = 

l2 = 7*(x_cont.^2 / 2 -3*x_cont/2 + 1);
figure(3)
plot(x_cont,l2)
axis([0 6 0 9])
grid on
axis([0 6 0 9])
xlabel('x');
ylabel('y');
hold on;
plot(x,y,'o');

figure(4)
plot(x_cont,l2)
plot(x_cont,(l0 + l1 + l2) , 'LineWidth', 4);
plot(0:0.1:6, y_poly,'LineWidth', 1);
axis([0 6 0 9])



figure(5)
title('final function');
plot(x_cont,(l0 + l1 + l2) , 'LineWidth', 2);
axis([0 6 0 9])
grid on;
hold on;
plot(x,y,'o');


figure(6)
hold on;
plot(x_cont,(l0 + l1 + l2) , 'LineWidth', 2);
plot(x_cont,l2)
plot(x_cont,l1)
plot(x_cont,l0)

axis([0 6 0 9])
grid on;
hold on;
plot(x,y,'o');

figure(7);

plot(0:0.1:6, y_poly,'LineWidth', 1);
axis([0 6 0 9])
grid on;
hold on;
plot(x,y,'o');

figure(8);
axis([0 6 0 9])
grid on;
hold on;
plot(x,y,'o');


%% Shamir Secret Sharing
x_cont = -2:0.01:10;
f = 1234 + 166*x_cont + 94*x_cont.^2;
keys = [1494 1942 2578 3402 4414 5614];
plot(x_cont,f);
axis([-0.5,7,0,8000]);
grid on;
hold on;
labels = cellstr( num2str([0:5]'));
plot([1 2 3 4 5 6],keys,'o');
plot(0,1234,'x');
text([1 2 3 4 5 6],keys, labels, ...
    'VerticalAlignment','bottom', ...
    'HorizontalAlignment','right');
text(0, 1234, 'S', ...
    'VerticalAlignment','bottom', ...
    'HorizontalAlignment','right');


