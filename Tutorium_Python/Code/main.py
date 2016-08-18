#!/usr/bin/python3

import lib.util as util

__author__ = "Tobias Trabelsi"
__copyright__ = "GPLv3"
__version__ = "1.0"
__maintainer__ = "Tobias Trabelsi"
__email__ = "Tobias.Trabelsi@HS-Bochum.de"
__status__ = "Testing"


if __name__ == '__main__':
    util.sayHello()
    util.saySomething("I like python")
    print(util.complexNumber(5,22))
    print(util.getType(util.complexNumber(1,2)))
    util.solveHanoi(3,"A","B","C")
    util.checkArray(util.getArrayFromOneToTen(),7)
    util.printWithC("Hallo")
    util.caesar_encrypt("hallo",13)
    util.caesar_decrypt("unyyb",13)
