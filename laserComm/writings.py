import sys
import serial

start = '11101010'
end = '00010101'

ser = serial.Serial('/dev/cu.usbmodem1451', 9600)
