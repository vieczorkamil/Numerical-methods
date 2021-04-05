%% Gaussian method - one division scheme
clc
clear all
%% entering the Ax=b matrix
n=input('Pass the size of matrix ');
A=zeros(n,n);
for i=1:n
    for j=1:n
        fprintf('Pass the a%d%d element of matrix A',i,j);
        A(i,j)=input(' = ');
    end
end
b=zeros(n,1);
for i=1:n
    fprintf('Pass the b%d element of matrix b',i);
    b(i)=input(' = ');
end
X = zeros(n,1);
C = [A b];
    disp('C =');
    disp(C);
%% determination of the step matrix
for i=1:n
    C(i,:) = C(i,:)/C(i,i);
    for j=(i+1):n
        C(j,:) = C(j,:) - C(i,:) * C(j,i);
    end
    Iter_num=sprintf('Iteration number %f',i);
    disp(Iter_num);
    disp(C);
end
%% determination of x
for k=n:-1:1
    suma = 0;
    for j=(n-1):-1:k
        suma =  suma + C(k,j+1)*X(j+1);
    end
    X(k) = C(k,n+1) - suma;
end
disp('Solutions: X=');
disp(X);