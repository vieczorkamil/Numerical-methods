%% Direct method
clear all
clc
%% size of grid
disp('Pass size of grid : ');
K=input('K = ');
L=input('L = ');
%% determination of grid step and optimal delta value
h=1.0/(K-1.0);
g=1.0/(L-1.0);
delta=0.5-((g*g)/(12.0*h));

t=zeros(1,K);
x=zeros(1,L);
alfa=zeros(1,L);
beta=zeros(1,L);
%% initial conditions
alfa(2)=0;
beta(2)=0;
%% setting a value of A, B i C
A=-delta/(g*g);
B=(2.0*delta/(g*g))+(1.0/h);
C=-delta/(g*g);

y=zeros(K,L);
F=zeros(K,L);
%% 
if (g*g)<=(delta*h)
	% determination of grid node values
    for i=1:K
        t(i)=(i-1.0)*h;
    end
    for j=1:L
         x(j)=(j-1.0)*g;
    end
    % initial condition
    for j=1:L
         y(1,j)=0;
    end
    % boundary conditions
    for i=1:K
         y(i,1)=0;
         y(i,L)=0;
    end
    for i=1:K-1
        for j=2:L-1
            E=7*pi*sin(pi*x(j))*sin(7*pi*t(i))*exp(-pi*pi*t(i));
            F(i,j)=-E-(((1.0-delta)/(g*g))*(y(i,j+1)+y(i,j-1)))+((2*(1.0-delta))/(g*g)-(1.0/h))*y(i,j);
            alfa(j+1)=C/(-B-alfa(j)* A);
            beta(j+1)=(A*beta(j)+F(i,j))/(-B-alfa(j)*A);
        end
        % determination of solution
        for j = L-1:-1:1
            y(i+1,j)=alfa(j+1)*y(i+1,j+1)+beta(j+1);
        end
    end
    disp(y);
    % graph of solutions
    figure('Name','3D graph of approximate solution');
    surf(t,x,y);
    xlim([0 1])
    ylim([0 1])
    
    % analytical/accurate value
    % d=sin(x*pi)*exp(-pi*pi*t)*(1-cos(7*pi*t));
    d=zeros(K,L);
    for i=1:K
       for j=1:L
           d(i,j)=sin(x(j)*pi)*exp(-pi*pi*t(i))*(1-cos(7*pi*t(i)));
       end
    end
    % value of the mean square error
    sum=0;
    for i=1:K
       for j=1:L
           sum=sum+(y(i,j)-d(i,j))^2;
       end
    end
    err=(sum^(1/2))/(K*L);
    result=['Error = ',num2str(err)];
    disp(result);
    
    % 3D graph of error
    err_plot=zeros(K,L);
    for i=1:K
       for j=1:L
           err_plot(i,j)=(y(i,j)-d(i,j));
       end
    end
    figure('Name','3D graph of error')
    surf(t,x,err_plot);
    xlim([0 1])
    ylim([0 1])
else
	disp('Does not meet the condition ');
end

