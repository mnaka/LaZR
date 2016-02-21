import sys							# System calls
import os                           # Operating System
sys.path.append("../ui/")
from PyQt4 import QtGui				# Import PyQt module
import mainwindow                   # import gui
import interface                    # import hardware interface

class Application(QtGui.QMainWindow, mainwindow.Ui_MainWindow):
    def __init__(self, parent=None):
        super(Application, self).__init__(parent)
        self.setupUi(self)
        self.DeviceInterface = None
        self.ConsoleDisplay.setReadOnly(True)
        self.ConnectDevice.triggered.connect(self.DeviceConnect)
        self.InputArea.returnPressed.connect(self.SubmitMessage)
        self.UserString = "You >> "
        self.IncomingString = "Them >> "
        self.MessageString = "Message >> "

    def DeviceConnect(self):
        portname, ok = QtGui.QInputDialog.getText(self, 'Connect Device', 'Enter Device port (eg. /dev/ttyACM0):')
        if ok:
            print(portname)
            self.DeviceInterface = interface.Interface(str(portname))
            self.ConsoleDisplay.appendPlainText(self.MessageString + "Device Connected")

        return

    def SubmitMessage(self):
        text = self.InputArea.displayText()
        self.ConsoleDisplay.appendPlainText(self.UserString + text)
        self.InputArea.setText("")
        return


def main():
    app = QtGui.QApplication(sys.argv)
    form = Application()
    form.show()
    sys.exit(app.exec_())

if __name__ == '__main__':              # if we're running file directly and not importing it
    main()  
