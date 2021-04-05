%% Neumann method
clear all
clc
%% y(x)=integral[-0.5;0.5]((x^2+t^2)*y(t)*dt)+x^3-x/2
%x=0:0.01:0.5;
deltaT=0.01;
a=-0.5;
b=0.5;
N=(b-a)/deltaT;
x_value=zeros(1,N);
%t=zeros(1,N);
y=zeros(1,N+1);
y(1)=0;
for i=1:N+1
   sum=0;
   for j=1:i
       x=i*deltaT;
       x_value(i)=x;
       t=j*deltaT;
       sum=sum+(x^2 + t^2)*y(j)*deltaT;
   end
   y(i+1)= sum + x^3 - x/2;
end
ynum = zeros(1,N);
for k=2:N+2
    ynum(k-1) = y(k);
end
result = [x_value' ynum']
%% Comparison chart
xd = 0:0.01:0.5;
y_accurate=xd.^3-xd./2;
plot(xd,y_accurate,'--');
hold on;
plot(x_value,ynum);
xlim([0 0.5]);
ylim([-0.15 0]);
xlabel('x');
ylabel('y');
legend('Exact solution','Approximate solution');