######################################################################
# Automatically generated by qmake (2.01a) mar. juil. 16 10:52:22 2013
######################################################################

TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

win32 {
  TARGET = mvision.exe
}

unix {
  TARGET = mvision.bin
  INCLUDEPATH += -I/opencv
  LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann
} 
# Input
SOURCES += main.cpp mainWindow.cpp
HEADERS += mainWindow.h
