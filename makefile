COMPILER=gcc -pedantic -std=c99
OUTPUT_VAN=arbolesADTVAN
OUTPUT_BUE=arbolesADTBUE
FILES=main.c front.c query.c libraryADT.c
DEFINE=-D BARRIO=1 -D HABITANTES=2
DEBUG_PARAMETERS=-Wall -fsanitize=address -g
OBJECTS=main.o front.o query.o libraryADT.o
DEFINE_VAN=-D BARRIO_ARBOLES=13 -D NOMBRE=7 -D DIAMETRO=16
DEFINE_BUE=-D BARRIO_ARBOLES=3 -D NOMBRE=8 -D DIAMETRO=12

VAN: objectsVAN
	$(COMPILER) $(OBJECTS) -o $(OUTPUT_VAN)

BUE: objectsBUE
	$(COMPILER) $(OBJECTS) -o $(OUTPUT_BUE)

all: VAN BUE

objectsVAN: DEFINE+=$(DEFINE_VAN)
objectsVAN:
	$(COMPILER) $(DEFINE) -c $(FILES)

objectsBUE: DEFINE+=$(DEFINE_BUE)
objectsBUE:
	$(COMPILER) $(DEFINE) -c $(FILES)

debugVAN: COMPILER+=$(DEBUG_PARAMETERS)
debugVAN: VAN

debugBUE: COMPILER+=$(DEBUG_PARAMETERS)
debugBUE: BUE

debug: debugVAN debugBUE

clear_queries:
	rm query*.csv

clear_objects:
	rm $(OBJECTS)

clearBUE:
	rm $(OUTPUT_BUE)

clearVAN:
	rm $(OUTPUT_VAN)

clearBUE_all: clearBUE clear_objects clear_queries

clearVAN_all: clearVAN clear_objects clear_queries

clear: clearBUE clearVAN

clear_all: clear clear_objects clear_queries
