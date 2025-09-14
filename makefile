OBJECTS=proyecto1.c
OUTPUT=proyecto1

$(OUTPUT): $(OBJECTS)
	gcc  -o $(OUTPUT) $(OBJECTS)  -lm
$(OBJECTS): proyecto1.h
clean:
	rm -f *.o
	rm -f proyecto1
