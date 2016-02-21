import serial

class Interface():
    def __init__(self, device_file):
        self.device_file = device_file
        self.serialport = serial.Serial(device_file)
        self.input_string = ""
        self.output_string = ""

    def read_from_photodiode(self):
        # (1) read from serialport
        # (2) parse and covert to string
        # (3) set string to self.output_string


    def write_to_laser(self, string):
        # (1) convert string to binary
        # (2) add start and stop signals to binary message
        # (3) write binary message to serial port for laser

    def string_to_binary(self, string):
        # string to binary conversion

    def binary_to_string(self, binary):
        # binary to string conversion


        
