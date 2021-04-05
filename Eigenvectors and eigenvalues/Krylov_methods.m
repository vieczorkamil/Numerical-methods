%% Eigenvectors and eigenvalues Krylov methods
clear all
clc
%initial vector y0
y0=[1;0;0];
%matrix A
A=[1,1,1;
   1,2,3;
   1,3,6];
size=size(A);
size=size(1,1);
%calculation of the coefficients of the characteristic equation
y=zeros(size);
y(:,1)=A*y0;
for i=2:size
    y(:,i)=A*y(:,(i-1));
end
Ap=zeros(size,size-1);
j=1;
for i=(size-1):-1:1
    Ap(:,j)=y(:,i);
    j=j+1;
end
Ap=[Ap, y0];
bp=-1*y(:,size);
equation = [Ap bp];
p=zeros(1,size+1);
p(1,1)=1;
for i=1:size
    D1=Ap;
    D1(:,i)=bp;
    p(1,i+1)=det(D1)/det(Ap); 
end
%% eigenvalues designation
s=size;
syms L;
f=0;
j=1;
for i=s:-1:0
    f=f+L^i*p(:,j);
    j=j+1;
end
L=vpa(solve(f,L));
L=sort(L);

%% eigenvectors designation
g=zeros(size);
g(size,:)=1;
for k=1:size
    j=2;
    for i=size-1:-1:1
        g(i,k)=L(k,1)*g(i+1,k)+p(1,j)*g(size,k);
        j=j+1;
    end
end

y=[y0 y];
x=zeros(size);
for i=1:size
    for j=1:size
        x(:,i)=x(:,i)+g(j,i)*y(:,j);
    end
end

%% eigenvector normalization
normx=zeros(size);
absx=abs(x);
for i=1:size
    maks=0;
    for j=1:size
       if absx(j,i)>maks
           maks=absx(j,i);
           maks2=x(j,i);
       end
    end
    normx(:,i)=x(:,i)/maks2;
end

%% results
disp('Matrix A and vector b of a system of linear equations = ');
disp(equation);

disp('Vector of coefficients p of the characteristic equation = ');
disp(p);

disp('Eigenvectors = ');
disp(L);

disp('Eigenvector = ');
disp(x);

disp('Eigenvector normalization = ');
disp(normx);

