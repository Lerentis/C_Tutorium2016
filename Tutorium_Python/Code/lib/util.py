#!/usr/bin/python3

from ctypes import *
import string


__author__ = "Tobias Trabelsi"
__copyright__ = "GPLv3"
__version__ = "1.0"
__maintainer__ = "Tobias Trabelsi"
__email__ = "Tobias.Trabelsi@HS-Bochum.de"
__status__ = "Testing"


def sayHello():
    print("Hello World")


def saySomething(something):
    print(something)


def sum(a,b):
    return a+b


def complexNumber(real,imag):
    return complex(real,imag)


def getType(var):
    return type(var)


def solveHanoi(numberOfSlices,stapleA,stapleB,stapleC):
    if(numberOfSlices>0):
        solveHanoi(numberOfSlices-1,stapleA,stapleC,stapleB)
        print("moving top slice from " + stapleA + " to " + stapleC)
        solveHanoi(numberOfSlices-1,stapleB,stapleA,stapleC)


def getArrayFromOneToTen():
    return range(10)


def checkArray(array, token):
    if token in array:
        print("Token " + str(token) + " has been found in array")


def printWithC(message):
    libc = CDLL("libc.so.6")
    printf = libc.printf
    printf("Message: %s\n".encode('ascii'), message.encode("ascii"))


def caesar_encrypt(message, key):
    libc = CDLL("libc.so.6")
    printf = libc.printf
    alphabet = string.ascii_lowercase
    shifted_alphabet = alphabet[key:]+alphabet[:key]
    table = bytes.maketrans(alphabet.encode("ascii"), shifted_alphabet.encode("ascii"))
    printf("Cyphertext: %s\n".encode("ascii"),message.translate(table).encode("ascii"))

def caesar_decrypt(message, key):
    libc = CDLL("libc.so.6")
    printf = libc.printf
    alphabet = string.ascii_lowercase
    shifted_alphabet = alphabet[-key:]+alphabet[:-key]
    table = bytes.maketrans(alphabet.encode("ascii"), shifted_alphabet.encode("ascii"))
    printf("Plaintext: %s\n".encode("ascii"),message.translate(table).encode("ascii"))

