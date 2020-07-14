COMPILER=gcc -pedantic -std=c99
OUTPUT_VAN=arbolesADTVAN
OUTPUT_BUE=arbolesADTBUE
FILES=main.c front.c query.c libraryADT.c
DEFINE=-D BARRIO=1 -D HABITANTES=2
DEBUG_PARAMETERS=-Wall -fsanitize=address -g
OBJECTS=main.o front.o query.o libraryADT.o
DEFINE_VAN=-D BARRIO_ARBOLES=13 -D NOMBRE=7 -D DIAMETRO=16
DEFINE_BUE=-D BARRIO_ARBOLES=3 -D NOMBRE=8 -D DIAMETRO=12

VAN: objects_VAN
	$(COMPILER) $(OBJECTS) -o $(OUTPUT_VAN)

BUE: objects_BUE
	$(COMPILER) $(OBJECTS) -o $(OUTPUT_BUE)

all: VAN BUE

objects_VAN: DEFINE+=$(DEFINE_VAN)
objects_VAN:
	$(COMPILER) $(DEFINE) -c $(FILES)

objects_BUE: DEFINE+=$(DEFINE_BUE)
objects_BUE:
	$(COMPILER) $(DEFINE) -c $(FILES)

debugVAN: COMPILER+=$(DEBUG_PARAMETERS)
debugVAN: VAN

debug_BUE: COMPILER+=$(DEBUG_PARAMETERS)
debug_BUE: BUE

debug: debugVAN debugBUE

clean_queries:
	rm query*.csv

clean_objects:
	rm $(OBJECTS)

clear_BUE:
	rm $(OUTPUT_BUE)

clear_VAN:
	rm $(OUTPUT_VAN)

clear: clear_BUE clear_VAN

clear_all: clear clear_objects clear_queries
