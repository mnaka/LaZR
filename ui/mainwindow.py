# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(800, 600)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.gridLayout_2 = QtGui.QGridLayout(self.centralwidget)
        self.gridLayout_2.setObjectName(_fromUtf8("gridLayout_2"))
        self.gridLayout = QtGui.QGridLayout()
        self.gridLayout.setObjectName(_fromUtf8("gridLayout"))
        self.InputArea = QtGui.QLineEdit(self.centralwidget)
        self.InputArea.setObjectName(_fromUtf8("InputArea"))
        self.gridLayout.addWidget(self.InputArea, 1, 0, 1, 1)
        self.ConsoleDisplay = QtGui.QPlainTextEdit(self.centralwidget)
        self.ConsoleDisplay.setTextInteractionFlags(QtCore.Qt.TextSelectableByKeyboard|QtCore.Qt.TextSelectableByMouse)
        self.ConsoleDisplay.setObjectName(_fromUtf8("ConsoleDisplay"))
        self.gridLayout.addWidget(self.ConsoleDisplay, 0, 0, 1, 1)
        self.ListenButton = QtGui.QPushButton(self.centralwidget)
        self.ListenButton.setObjectName(_fromUtf8("ListenButton"))
        self.gridLayout.addWidget(self.ListenButton, 2, 0, 1, 1)
        self.gridLayout_2.addLayout(self.gridLayout, 0, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 23))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        self.menuFile = QtGui.QMenu(self.menubar)
        self.menuFile.setObjectName(_fromUtf8("menuFile"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)
        self.ConnectDevice = QtGui.QAction(MainWindow)
        self.ConnectDevice.setCheckable(False)
        self.ConnectDevice.setObjectName(_fromUtf8("ConnectDevice"))
        self.menuFile.addAction(self.ConnectDevice)
        self.menubar.addAction(self.menuFile.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.ListenButton.setText(_translate("MainWindow", "Listen for Message", None))
        self.menuFile.setTitle(_translate("MainWindow", "File", None))
        self.ConnectDevice.setText(_translate("MainWindow", "Connect Device ...", None))

