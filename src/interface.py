import serial

class Interface():
    def __init__(self, device_file):
        self.device_file = device_file
        self.serialport = serial.Serial(device_file)
        self.message_header = "11101010"
        self.message_footer = "00010101"

    def read_from_photodiode(self):
        binary = self.serialport.read(8)
        counter = 0
        while binary[-8:] != endofMessage:
            counter = counter +1
            binary += ser.read(8)
            message = toString(binary[8:])
        return message

    def write_to_laser(self, string):
        message = self.message_header + self.toBinary(string) + "0000000000000000"
        counter = 1
        while len(message) > 0:
            counter = counter + 1
            self.serialport.write(message[:8])
            message = message[8:]
        return

    def toBinary(message):
        asc = []
        binary = []
        answer = []
        final = ""
        #char -> ascii
        for x in message:
            asc.append(ord(x))
        for x in asc:
            binary.append("{0:b}".format(x))
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

    def toString(numbers):
        binary = []
        decimal = []
        answer = []
        final = ""
        tmp = 0;
        for i in range(0,len(numbers), 8):
            tmp = i
            binary.append(numbers[tmp: tmp+8])
        for x in binary:
            tmp =0
            for y in x:
                tmp=tmp*2+int(y)
            decimal.append(tmp)
        for x in decimal:
            answer.append(chr(x))
        for x in answer:
            final = final+x

        return final
