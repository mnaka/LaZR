import serial

class Interface():
    def __init__(self, device_file):
        self.device_file = device_file
        self.serialport = serial.Serial(device_file)
        self.input_string = ""
        self.output_string = ""
        self.message_header = #
        self.message_footer = #

    def read_from_photodiode(self):
        # (1) read from serialport
        # (2) parse and covert to string
        # (3) set string to self.output_string
        return

    def write_to_laser(self, string):
        message = self.message_header + toBinary(string) + self.message_footer
        while len(message) > 0:
            ser.write(message[:8])
            message = message[9:]
        return

    def string_to_binary(self, string):
        # string to binary conversion
        pass

    def binary_to_string(self, binary):
        # binary to string conversion
        pass

    def ASCIItoBinary(string):
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
