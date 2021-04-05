%% simple iteration method
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
norma=0;
X = zeros(n,1);
if (min(abs(diag(A)))==0)
    disp('Condition not met aii != 0');
else
    g=[0;0;0];
    H=zeros(n,n);
    for i=1:n
        g(i)=b(i)/A(i,i);
    end
    for i=1:n
       for j=1:n
          if(i~=j)
              H(i,j)=-A(i,j)/A(i,i);
          end
       end
    end
    X0=g;
    i=0;
    %stop condition
     for j=1:n
         for i=1:n      
          norma=norma+H(i,j);  
        end
     end
           norma=norma*norma;
 if norma<1
        for n=1:k
            X=g+H*X0;
        end
        fprintf('Result determined by iteration = ')
        disp(X);
 else
        fprintf('The system is divergent, so it is impossible to calculate it using this method. ')
 end
end
