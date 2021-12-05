# Proyecto_Gato_C
Proyecto #2 del curso IE0117 sobre un juego de gato en C, en el ciclo II-2021

### Integrante

* Luis Diego Araya Campos. B60478

### Sistema operativo

* Este programa fue diseñado para utilizarse en Ubuntu 18.04 LTS (Bionic Beaver)

### Requisitos

* gcc (sin embargo, está incluido por defecto en todos los sabores de Ubuntu)
* libgtk-3-dev

Donde este último se instala como:

```
$ sudo apt install libgtk-3-dev
```

### Compilación y ejecución del programa

Cambie de directorio al directorio del proyecto `Proyecto_Gato_C` y corra el comando:

```
$ make
```

Con ello se compila el programa y se crea un ejecutable. Para ejecutarlo se usa el comando:

```
$ make run
```

Una vez que termine de usar el programa puede borrar el ejecutable con:

```
$ make clean
```

### Intrucciones del juego

Hay dos jugadores uno con las equis (X) y otro con los círculos (O). El juego se realiza por turnos. En cada turno, el jugador puede colocar su símbolo en una de las 9 casillas que esté desocupada. El juego se gana al obtener tres símbolos de un jugador en línea, ya sea, fila, columna o diagonal.

### Características del programa

En la parte superior de la ventana se presenta un botón de reinicio el cual puede utilizarse para empezar un juego nuevo en cualquier momento, ya sea, al inicio, durante juego o al final del juego donde algún jugador gane o ninguno gane. En cada reinicio cambia el primer jugador, una vez X, a la siguiente O y así sucesivamente.
