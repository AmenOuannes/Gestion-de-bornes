# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = UtilisationGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjoutFontaine.cpp AjoutStationnement.cpp RegistreGUI.cpp SupprimeBorne.cpp main.cpp
HEADERS += AjoutFontaine.h AjoutStationnement.h RegistreGUI.h SupprimeBorne.h
FORMS += AjoutFontaine.ui AjoutStationnement.ui RegistreGUI.ui SupprimeBorne.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../source 
LIBS += ../source/dist/Debug/GNU-Linux/libsource.a  