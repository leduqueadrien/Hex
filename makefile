#options SDL : -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net

# options de compilation et d'edition des liens
CXXFLAGS = -Wall -Wextra -MMD -g -O2
LDFLAGS = -lSDL2

SRCGraphic = $(wildcard src/Game/*.cpp) $(wildcard src/Graphic/*.cpp) src/MainHexGraph.cpp
OBJGraphic = $(addprefix build/, $(SRCGraphic:.cpp=.o))

SRCConsole = $(wildcard src/Game/*.cpp) $(wildcard src/Console/*.cpp) src/MainHexCons.cpp
OBJConsole = $(addprefix build/, $(SRCConsole:.cpp=.o))

DEP = $(addprefix build/, $(SRCGraphic:.cpp=.d)) $(addprefix build/, $(SRCConsole:.cpp=.d)) $(src/MainHexGraph.cpp) $(src/MainHexCons.cpp)


.PHONY: all
all: graphic console
	@echo "2 executables disponibles"

.PHONY: graphic
graphic: bin/graphic
	@echo "Executer avec ./bin/graphic"

# edition des liens, executable graphic
bin/graphic: $(OBJGraphic)
	@mkdir -p $(@D) #creer le dossier bin, sil nexiste pas
	$(CXX) -o $@ $^ $(LDFLAGS)


.PHONY: console
console: bin/console
	@echo "Executer avec ./bin/console"

# edition des liens, executable console
bin/console: $(OBJConsole)
	@mkdir -p $(@D) #creer le dossier bin, sil nexiste pas
	$(CXX) -o $@ $^ $(LDFLAGS)


# genere les fichiers .o (dans build) a partir des fichiers .cpp (dans src) du meme nom
# compilation
build/%.o: %.cpp
	@mkdir -p $(@D)  #creer le dossier build sil nexiste pas
	$(CXX) -c $< $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf build core *.gch
	rm -rf bin

-include $(DEP)
