import sys							# System calls
import os                           # Operating System
sys.path.append("../ui/")
from PyQt4 import QtGui				# Import PyQt module
import mainwindow                   # import gui

class Application(QtGui.QMainWindow, mainwindow.Ui_MainWindow):
    def __init__(self, parent=None):
        super(Application, self).__init__(parent)
        self.setupUi(self)
        # self.DeviceInterface = put interface here
        self.ConnectDevice.triggered.connect(self.DeviceConnect)

    def DeviceConnect(self):
        return


def main():
    app = QtGui.QApplication(sys.argv)
    form = Application()
    form.show()
    sys.exit(app.exec_())

if __name__ == '__main__':              # if we're running file directly and not importing it
    main()  
