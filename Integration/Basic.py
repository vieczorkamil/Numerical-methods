import math
import random
random.seed()
a = float(input("Pass bottom line for integration a = "))
b = float(input("Pass top line for integration b = "))
print("Trapezoidal Rule y = exp(x):")
h = (b-a)
value = (h/2) * (math.exp(a) + math.exp(b))
ksi = a
max = math.fabs(math.exp(ksi))
while(ksi < b):
    ksi += 0.001
    if(math.fabs(math.exp(ksi)) > max):
        max = math.fabs(math.exp(ksi))
rest = (-1/12)*math.pow(h, 3)*math.exp(ksi)
print("-Exact value of the integral = ", math.exp(b) - math.exp(a))
print("-Calculate value of the integral = ", value)
print("-Calculate value of the rest = ", rest)
print("-Exact value of the rest = ", (math.exp(b) - math.exp(a))-value)

print("Simpson's Rule y = exp(x):")
h = (b-a)/2
x1 = a+h  # point x1
value = (h/3) * (math.exp(a) + 4*math.exp(x1) + math.exp(b))
ksi = random.random()*(b-a)+a
rest = (-1/90)*math.pow(h, 5)*math.exp(ksi)
print("-Exact value of the integral = ", math.exp(b) - math.exp(a))
print("-Calculate value of the integral = ", value)
print("-Calculate value of the rest = ", rest)
print("-Exact value of the rest = ", (math.exp(b) - math.exp(a))-value)
