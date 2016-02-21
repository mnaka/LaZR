import sys
import serial
ser = serial.Serial('/dev/cu.usbmodem1451', 9600)
incomingMessage = "11101010"
endofMessage = "00010101"

def write:
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
    messageRaw = raw_input('Enter Your Message Here: ')
    message = incomingMessage + toBinary(messageRaw) + endofMessage

    while len(message) > 0:
        ser.write(message[:8])
        message = message[9:]
        print ser.read()

def read:
    print ""
