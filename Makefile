# Makefile especifico para Proyecto 2 de Sistemas Operativos 1.
# Grupo 20: Astrid, Jhonaiker y Junior.
# Este Makefile compila el archivo .c principal para el proyecto 2
# descrito como "proyecto_2_op1_AstridJhonaikerJunior.c", este consta
# de un .h "standard_lib.h" para su correcto funcionamiento.

###################################################
# DEFINES:

COMP 		 = cc -c

LINK 		 = cc

FILE 		 = proyect_2_op1_AstridJhonaikerJunior.c

OBJDIR   = 

OBJS 		 = proyect_2_op1_AstridJhonaikerJunior.o

LIBRERYS = standard_lib.h

PROGRAM  = fameChecker

FLAGS    = -pthread

###################################################
# Especificacion de Parametros para Make.

.PHONY: all clean

all: $(PROGRAM)

clean: 
	rm $(PROGRAM)
	rm $(OBJS)
#	rm $(OBJDIR)

##################################################
# Compilacion de archivos.

$(OBJS): $(FILE) $(LIBRERYS)
	$(COMP) $(FILE) $(FLAGS) -o $(OBJS)

$(PROGRAM): $(OBJS)
	$(LINK) $(OBJS) $(FLAGS) -o $(PROGRAM)

#$(OBJDIR):
#	mkdir $(OBJDIR)

#################################################

