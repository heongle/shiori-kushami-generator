SOURCE_CPP	= main.cpp MainFrame.cpp TrayMenu.cpp Component/MainWidget.cpp Component/StartButton.cpp \
			  Component/KushamiFunc/KushamiSE.cpp Component/KushamiFunc/Timer.cpp Component/KushamiFunc/RandGen.cpp res/res_pointer.cpp res/se/kushami1.cpp \
			  res/se/kushami2.cpp res/se/kushami3.cpp res/se/kushami4.cpp res/se/kushami5.cpp res/se/kushami6.cpp res/se/kushami7.cpp res/se/kushami8.cpp res/qt_resources/kushamiResQt.cpp
SOURCE_RC	= icon/shiori_icon.rc
OBJS	= $(addprefix _obj/, $(notdir $(SOURCE_CPP:.cpp=.o)) $(notdir $(SOURCE_RC:.rc=.o)))
OUT	= ../bin/Shiori_Kushami.exe
CC	 = C:/Program Files/mingw-w64/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/bin/g++.exe
FLAGS	 = -Wall -O2 -std=c++17
WINFLAGS = -mwindows
NOLINK	= -c
QT5WIDGET	= $(shell pkg-config Qt5Widgets --cflags)
QT5WIDGET_LINKER	= $(shell pkg-config Qt5Widgets --libs)
SFML_AUDIO	= $(shell pkg-config sfml-audio --cflags)
SFML_AUDIO_LINKER	= $(shell pkg-config sfml-audio --libs)

# Main CPP files test
all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(OUT) $(QT5WIDGET) $(QT5WIDGET_LINKER) $(SFML_AUDIO) $(SFML_AUDIO_LINKER)

_obj/main.o: main.cpp
	$(CC) $(NOLINK) $(FLAGS) main.cpp $(QT5WIDGET) -o _obj/main.o

_obj/TrayMenu.o: TrayMenu.cpp
	$(CC) $(NOLINK) $(FLAGS) TrayMenu.cpp $(QT5WIDGET) -o _obj/TrayMenu.o

_obj/MainFrame.o: MainFrame.cpp
	$(CC) $(NOLINK) $(FLAGS) MainFrame.cpp $(QT5WIDGET) $(SFML_AUDIO) -o _obj/MainFrame.o

_obj/StartButton.o: Component/StartButton.cpp
	$(CC) $(NOLINK) $(FLAGS) Component/StartButton.cpp $(QT5WIDGET) -o _obj/StartButton.o

_obj/KushamiSE.o: Component/KushamiFunc/KushamiSE.cpp
	$(CC) $(NOLINK) $(FLAGS) Component/KushamiFunc/KushamiSE.cpp $(SFML_AUDIO) -o _obj/KushamiSE.o

_obj/Timer.o: Component/KushamiFunc/Timer.cpp
	$(CC) $(NOLINK) $(FLAGS) Component/KushamiFunc/Timer.cpp $(QT5WIDGET) -o _obj/Timer.o

_obj/RandGen.o: Component/KushamiFunc/RandGen.cpp
	$(CC) $(NOLINK) $(FLAGS) Component/KushamiFunc/RandGen.cpp $(QT5WIDGET) -o _obj/RandGen.o

_obj/MainWidget.o: Component/MainWidget.cpp
	$(CC) $(NOLINK) $(FLAGS) Component/MainWidget.cpp $(QT5WIDGET) $(SFML_AUDIO) -o _obj/MainWidget.o

_obj/res_pointer.o: res/res_pointer.cpp
	$(CC) $(NOLINK) $(FLAGS) res/res_pointer.cpp -o _obj/res_pointer.o

_obj/kushamiResQt.o: res/qt_resources/kushamiResQt.cpp
	$(CC) $(NOLINK) $(FLAGS) res/qt_resources/kushamiResQt.cpp $(QT5WIDGET) -o _obj/kushamiResQt.o

# Icon RC files test
_obj/shiori_icon.o: icon/shiori_icon.rc
	windres -i icon\\shiori_icon.rc -o _obj\\shiori_icon.o

# C resources file
_obj/kushami1.o: res/se/kushami1.cpp
	$(CC) $(NOLINK) $(FLAGS) res/se/kushami1.cpp -o _obj/kushami1.o

_obj/kushami2.o: res/se/kushami2.cpp
	$(CC) $(NOLINK) $(FLAGS) res/se/kushami2.cpp -o _obj/kushami2.o

_obj/kushami3.o: res/se/kushami3.cpp
	$(CC) $(NOLINK) $(FLAGS) res/se/kushami3.cpp -o _obj/kushami3.o

_obj/kushami4.o: res/se/kushami4.cpp
	$(CC) $(NOLINK) $(FLAGS) res/se/kushami4.cpp -o _obj/kushami4.o

_obj/kushami5.o: res/se/kushami5.cpp
	$(CC) $(NOLINK) $(FLAGS) res/se/kushami5.cpp -o _obj/kushami5.o

_obj/kushami6.o: res/se/kushami6.cpp
	$(CC) $(NOLINK) $(FLAGS) res/se/kushami6.cpp -o _obj/kushami6.o

_obj/kushami7.o: res/se/kushami7.cpp
	$(CC) $(NOLINK) $(FLAGS) res/se/kushami7.cpp -o _obj/kushami7.o

_obj/kushami8.o: res/se/kushami8.cpp
	$(CC) $(NOLINK) $(FLAGS) res/se/kushami8.cpp -o _obj/kushami8.o

# Clean
clean:
	DEL /Q /F /S "*.o"