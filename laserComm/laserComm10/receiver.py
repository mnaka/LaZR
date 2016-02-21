import sys
import serial
import time
import string
import re

ser = serial.Serial('/dev/cu.usbmodem1411', 9600)
incomingMessage = "11101010"
endofMessage = "00010101"

f = open('log', 'w')

def write():
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
            temp = temp[::-1]
            while len(temp) < 8:
                temp += "0"
            temp = temp[::-1]
            answer.append(temp)
        for x in answer:
            final = final + x
        return final
    messageRaw = raw_input('Enter Your Message Here: ')
    f.write(">> You: " + messageRaw +"\n")
    time.sleep(5)
    message = incomingMessage + toBinary(messageRaw) + endofMessage
    counter = 1
    while len(message) > 0:
        print counter
        counter = counter + 1
        ser.write(message[:8])
        time.sleep(0.25)
        message = message[8:]


def read():
    def toString(numbers):
        print "numbers = " + numbers
        mumbers = numbers;
        numbers = re.sub('[\s+]', '',mumbers)


        binary = []
        decimal = []
        answer = []
        final = ""
        tmp = 0;

        # splitting binary for conversion
        for i in range(0,len(numbers), 8):
            tmp = i
            if numbers[i] == '\n' or numbers [i ] == '\r':
                i+=1
            binary.append(numbers[tmp: tmp+8])

        # binary -> decimal
        for x in binary:
            tmp =0
            print "x = " + x
            for y in x:
                print "y = " + y
                tmp=tmp*2+int(y)
            decimal.append(tmp)

        #decimal -> ascii
        for x in decimal:
            answer.append(chr(x))

        #ascii -> string
        for x in answer:
            final = final+x

        return final
    counter = 0
    binary = ser.read(8)
    while binary!= incomingMessage:
        binary = binary[1:8] + ser.read(1)
        print "listening..."
        # counter +=1
    binary = binary[:8]
    while binary[-8:] != "00000000":
        print "Still listening..."
        binary= binary + ser.read(8)
        counter += 8
    print "creating message"
    message = toString(binary[-counter:])
    print "Printing message: " + message
    f.write("Olivia! has said: " + message + "\n")
    print "Complete"
    # time.sleep(100000000)
    # message = toString(binary)


while True:
    #write()
    read()
