# Nom de l'exécutable
TARGET = main

# Dépendance du programme
SOURCE = principale.c

# Règle de compilation et d'exécution
run: $(TARGET)
	./$(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(SOURCE)
	gcc -c $(SOURCE) -o $(TARGET).o
	gcc $(TARGET).o -o $(TARGET)

# Nettoyage des fichiers générés
clean:
	rm -f $(TARGET) $(TARGET).o


