# Runge-Kutta method
import numpy
h = float(input("Pass the calculation step = "))
y0 = float(input("Specify the initial condition y(0) = "))
n = int(input(("Enter the number of steps = ")))
# differential equation  ---->  y'(x)=2xy(x)
k1 = []
k2 = []
k3 = []
k4 = []
x = []
y = [y0]
for i in numpy.arange(0, n*h+h, h):
    x.append(i)
for i in numpy.arange(0, n):
    k1.append(h*(2*x[i]*y[i]))
    k2.append(h*(2*(x[i]+h/2)*(y[i]+k1[i]/2)))
    k3.append(h*(2*(x[i]+h/2)*(y[i]+k2[i]/2)))
    k4.append(h*(2*(x[i]+h)*(y[i]+k3[i])))
    y.append(y[i]+(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6)
print("x = ", x)
print("y = ", y)
print("k1 = ", k1)
print("k2 = ", k2)
print("k3 = ", k3)
print("k4 = ", k4)
print("After", n, "steps the result was", y[n])
