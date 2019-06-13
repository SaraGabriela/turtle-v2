Turtle en C++
=========

## Descripci�n
C�digo que simula la tortuga de Python haciendo uso de OpenGL. Permite realizar gr�ficos simples por medio de un plano de coordenadas. Empieza a dibujar en (0,0).

## �C�mo se usa?
### 1. Instalar Glut
Referencias para instalar GLUT al usar DevC++:
https://www.quora.com/How-do-I-run-OpenGL-in-DEV-C++
https://www.youtube.com/watch?v=RTk6W67dyR4

Referencias para instalar GLUT al usar Visual Studio:
https://elcodigografico.wordpress.com/2017/07/31/opengl-glut-con-visual-studio-2017/
https://www.youtube.com/watch?v=HKGJrzAuTvU


### 2. Usar la estructura
Primero se crea una instancia del objeto que se va a dibujar y se crea la ventana donde se va a dibujar.
```c++
	turtle * tu = new turtle();
	tu->setInstance(tu);
	tu->startTurtle();
```
Luego, ingresa lo que la tortuga va a dibujar.

Finalmente mostramos el dibujo realizado.
```c++
	tu->display();
```

Debe quedar as�:
```c++
int main()
{
	turtle * tu = new turtle();
	tu->setInstance(tu);
	tu->startTurtle();

	//tu c�digo va aqu�

	tu->display();
	return 0;
}
```
�Y listo! Permite realizar dibujos de un modo sencillo. Para un ejemplo, ejecuta main.cpp de la carpeta source.

## �C�mo dibujar?
### pendown()
Baja el l�piz de dibujo. La tortuga va a dibujar solo cuando el l�piz este abajo.

### penup()
Levanta el l�piz de dibujo. Mientras el l�piz este arriba, la tortuga no va a dibujar.

### forward(distancia)
Dibujar� una l�nea seg�n la distancia indicada. Solo dibuja si el l�piz est� abajo, es decir si se llam� antes a pendown(). Si el l�piz est� arriba, se mover� sin dibujar.
```c++
	tu->forward(3);
```
### left(�ngulo)
La tortuga girar� a la izquierda seg�n el �ngulo indicado.
```c++
	tu->left(90);
```
### right(�ngulo)
La tortuga girar� a la derecha seg�n el �ngulo indicado.
```c++
	tu->right(90);
```
### go(x,y)
La tortuga se va a dirigir al punto indicado.
```c++
	tu->go(-2,0);
```

### pencolor(r,g,b)
Cambiar el color del dibujo

## Authors
- [Sara D�az Oporto](https://github.com/SaraGabriela)
