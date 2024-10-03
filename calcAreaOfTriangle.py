
#area of triangle  

p = float(input('Enter the length of first side: '))  
q = float(input('Enter the length of second side: '))  
r = float(input('Enter the length of final side: '))  

# calculate the semi-perimeter  
s = (p + q + r)/2

# calculate the area  
area_tri = (s*(s-p)(s-q)(s-r)) ** 0.5  
print('The area of the triangle is %0.2f' %area_tri)

