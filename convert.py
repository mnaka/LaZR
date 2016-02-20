import binascii
import sys

class convert:

    def toBinary(message):
        asc = []
        binary = []

        for x in message:
            asc.append(ord(x))

        for x in asc:
            binary.append("{0:b}".format(x))

        for x in binary:
            x = x[::-1]
            while len(x) <= 8:
                x += "0"
            x = x[::-1]

        return binary

    print(toBinary("message"))



    #def toString(numbers):
