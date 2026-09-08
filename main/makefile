CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinterface -Ienums -Imodels

SRC = main.cpp \
      Chamado.cpp \
      ListaHistorico.cpp \
      NoHistorico.cpp \
      models/Solicitante.cpp \
      ArvoreBusca.cpp \

TARGET = chamado.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)





# comando para roda o markfile
# mingw32-make