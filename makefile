#options SDL : -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net

# options de compilation et d'edition des liens
CXXFLAGS = -Wall -Wextra -MMD -g -O2
LDFLAGS = -lSDL2

SRC = $(wildcard src/*.cpp)

OBJ = $(addprefix build/, $(SRC:.cpp=.o))
DEP = $(addprefix build/, $(SRC:.cpp=.d))


.PHONY: all
all: main
	@echo "1 executables disponibles"

.PHONY: main
main: bin/main
	@echo "Executer avec ./bin/main"

# edition des liens, executable main
bin/main: $(OBJ)
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
