#!/usr/bin/python

import hello_ext

# Exporting classes
print "Practice 1: Exporting classes"
h1 = hello_ext.function()
print h1
print dir(h1)

# Call policies
print "Practice 2: Call policies"
a = hello_ext.A(1)
b = hello_ext.B(2)

print b.a1.val
print b.a2.val
print hello_ext.f(b, a)
print b.a1.val
print b.a2.val

# Overloading
print "Practice 3: Overloading"
x = hello_ext.X()
print x.f(1)
print x.f(1, 2)
print x.f(1, 2, 'a')
print x.f(1, 2, 3)

# Default arguments
print "Practice 4: Default arguments"
hello_ext.foo(0)
hello_ext.foo(0, 'z')
hello_ext.foo(0, 'z', 100)
hello_ext.foo(0, 'z', 100, 1000)

g = hello_ext.George(1)
g.wack_em(0)
g.wack_em(0, 1)
g.wack_em(0, 1, 'c')
