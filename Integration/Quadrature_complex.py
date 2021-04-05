import math
a = float(input("Pass bottom line for integration a = "))
b = float(input("Pass top line for integration b = "))
n = float(input("Pass the count of subinterval n = "))
print("Integration quadrature complex Trapezoidal Rule y = exp(x):")
h = (b-a)/n
f = a+h
sum = 0
while(f < b):
    sum += 2*math.exp(f)
    f += h
value = (h/2) * (math.exp(a) + sum + math.exp(b))
ksi = a
max = math.fabs(math.exp(ksi))
while(ksi < b):
    ksi += 0.001
    if(math.fabs(math.exp(ksi)) > max):
        max = math.fabs(math.exp(ksi))
rest = (-1/12)*n*math.pow(h, 3)*max

print("-Exact value of the integral = ", math.exp(b) - math.exp(a))
print("-Calculate value of the integral = ", value)
print("-Calculate value of the rest = ", rest)
print("-Exact value of the rest = ", (math.exp(b) - math.exp(a))-value)

print("Integration quadrature complex Simpson's Rule y = exp(x):")
h = (b-a)/(2*n)
f = .4 % (a+h)
sum = 0
counter = 1
while(f < (a+(2*n*h))):
    if(counter % 2 == 1):
        coefficient = 4
    else:
        coefficient = 2
    sum += coefficient*math.exp(f)
    f += h
    counter += 1
value = (h/3) * (math.exp(a) + sum + math.exp(b))
ksi = a
max = math.fabs(math.exp(ksi))
while(ksi < b):
    ksi += 0.01
    if(math.fabs(math.exp(ksi)) > max):
        max = math.fabs(math.exp(ksi))
rest = (-1/90)*n*math.pow(h, 5)*max
print("-Exact value of the integral = ", math.exp(b) - math.exp(a))
print("-Calculate value of the integral = ", value)
print("-Calculate value of the rest = ", rest)
print("-Exact value of the rest = ", (math.exp(b) - math.exp(a))-value)
