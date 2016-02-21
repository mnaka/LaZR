import sys
import binascii

class convert:

    #converts string to binary
    def toBinary(message):
        asc = []
        binary = []
        answer = []
        final = ""

        #char -> ascii
        for x in message:
            asc.append(ord(x))

        #ascii -> binary
        for x in asc:
            binary.append("{0:b}".format(x))

        #formatting binary
        for x in binary:

            temp = x;
            while len(temp) < 8:
                temp += "0"

            temp = temp[::-1]
            answer.append(temp)

        for x in answer:
            final = final + x

        return final

    #converts binary to string 
    def toString(numbers):
        binary = []
        decimal = []
        answer = []
        final = ""
        tmp = 0;

        #splitting binary for conversion
        for i in range(0,len(numbers), 8):
                tmp = i
                binary.append(numbers[tmp: tmp+8])

        #binary -> decimal
        for x in binary:
            tmp =0
            for y in x:
                tmp=tmp*2+int(y)
            decimal.append(tmp)

        #decimal -> ascii
        for x in decimal:
            answer.append(chr(x))

        #ascii -> string
        for x in answer:
            final = final+x

        return final

    print(toString("0110100001100101011011000110110001101111001000000111011101101111011100100110110001100100"))
