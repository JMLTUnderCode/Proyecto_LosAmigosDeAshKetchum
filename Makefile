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

OBJDIR   = ProyectFiles

OBJS 		 = $(OBJDIR)/search_inodo.o $(OBJDIR)/readExtractFlags.o $(OBJDIR)/proyect_2_op1_AstridJhonaikerJunior.o

PROGRAM  = fameChecker

FLAGS    = -pthread -o

###################################################
# Especificacion de Parametros para Make.

.PHONY: all clean

all: $(PROGRAM)

clean: 
	rm $(PROGRAM)
	rm $(OBJS)
	rmdir $(OBJDIR)

##################################################
# Compilacion de archivos.

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/readExtractFlags.o: readExtractFlags.c $(OBJDIR) readExtractFlags.h
	$(COMP) readExtractFlags.c $(FLAGS) $(OBJDIR)/readExtractFlags.o

$(OBJDIR)/search_inodo.o: search_inodo.c $(OBJDIR) search_inodo.h
	$(COMP) search_inodo.c $(FLAGS) $(OBJDIR)/search_inodo.o

$(OBJDIR)/proyect_2_op1_AstridJhonaikerJunior.o: proyect_2_op1_AstridJhonaikerJunior.c $(OBJDIR) readExtractFlags.h search_inodo.h
	$(COMP) proyect_2_op1_AstridJhonaikerJunior.c $(FLAGS) $(OBJDIR)/proyect_2_op1_AstridJhonaikerJunior.o

$(PROGRAM): $(OBJS)
	$(LINK) $(OBJS) $(FLAGS) $(PROGRAM)

#################################################

