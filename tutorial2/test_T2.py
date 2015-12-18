#!/usr/bin/python

from planar.vector import Vec2

import T2


def test1():
    print "test1"
    msg = T2.compare_upper('asdf')
    print "msg is", str(msg)
    print "msg is a", type(msg)


def test2():
    print "test2"
    d = {'something': 1}
    print "d was", d
    T2.edit_dict(d)
    print "d is now", d


def test3():
    print "test3"
    obj = T2.get_c_object()
    print "obj is a", type(obj)
    print "obj.sum():", obj.sum()


def test4():
    print "test4"
    vec = Vec2(3, 4)
    print "vec.length:", vec.length
    print "T2.extract_length(vec):", T2.extract_length(vec)


def test5():
    print "test5"
    print "choice.red", T2.choice.red
    print "choice.blue", T2.choice.blue


def test6():
    print "test6"
    print T2.get_vector()


if __name__ == '__main__':
    test1()
    test2()
    test3()
    test4()
    test5()
    test6()
