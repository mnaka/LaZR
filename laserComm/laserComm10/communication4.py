import sys
import serial
import time
ser = serial.Serial('/dev/cu.usbmodem1451', 9600)
incomingMessage = "11101010"
endofMessage = "00010101"

f = open('log', 'a')

def write():
    def toBinary(message):
        asc = []
        binary = []
        answer = []
        final = ""
        #char -> ascii
        for x in message:
            asc.append(ord(x))
        print asc
        #ascii -> binary
        for x in asc:
            binary.append("{0:b}".format(x))
        print binary
        #formatting binary
        for x in binary:
            temp = x;
            temp = temp[::-1]
            while len(temp) < 8:
                temp += "0"
            temp = temp[::-1]
            answer.append(temp)
        print answer
        for x in answer:
            final = final + x
        print final
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
    binary = ser.read(8)
    counter = 0
    while binary[-8:] != endofMessage:
        counter = counter +1
        binary += ser.read(8)
    message = toString(binary[8:])
    f.write("Olivia said: " + message + "\n")

while True:
    read()
    write()
