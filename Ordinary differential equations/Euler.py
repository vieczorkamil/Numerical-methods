# Euler method
import numpy
h = float(input("Pass the calculation step = "))
y0 = float(input("Specify the initial condition y(0) = "))
n = int(input(("Enter the number of steps = ")))
# differential equation  ---->  y'(x)=2xy(x)
y = [y0]
x = [0]
f = [2*x[0]*y[0]]
delta_y = [h*f[0]]
for i in numpy.arange(h, n*h, h):
    x.append(i)
y.append(y[0]+delta_y[0])
for i in range(1, n):
    f.append(2*x[i]*y[i])
    delta_y.append(h*f[i])
    y.append(y[i]+delta_y[i])
print("x = ", x)
print("y = ", y)
print("f = ", f)
print("delta y = ", delta_y)
print("After", n, "steps the result was", y[n])
