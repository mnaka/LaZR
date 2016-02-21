import serial
import time
import sys

class Interface():
    def __init__(self, device_file):
        self.device_file = device_file
        self.serialport = serial.Serial(device_file)

    def read_from_photodiode(self):
        # (1) read from serialport
        # (2) parse and covert to string
        # (3) set string to self.output_string
        return

    def write_to_laser(self, string):
        message = string + '\n'
        self.serialport.write(message)
        return

    def string_to_binary(self, string):
        # string to binary conversion
        pass

    def binary_to_string(self, binary):
        # binary to string conversion
        pass

if __name__ == "__main__":
    interface = Interface('/dev/ttyACM0')
    interface.write_to_laser(sys.argv[1])
    
