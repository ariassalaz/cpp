Task Tracker CLI (C++)

Task Tracker es una aplicación de línea de comandos desarrollada en C++ que permite gestionar tareas y organizarlas por estado: pendientes, en progreso o completadas.  
Cada tarea se almacena en archivos de texto, lo que permite mantener un registro persistente sin necesidad de usar bases de datos.

Características principales

Agregar nuevas tareas al archivo principal (`list.txt`).
Actualizar el nombre de una tarea existente.
Eliminar tareas del registro general.
Cambiar el estado de una tarea:
  - `inProgress.txt` → tareas en progreso.
  - `done.txt` → tareas completadas.
  - `notDone.txt` → tareas pendientes.
Listar todas las tareas por categoría.
Manejo de archivos mediante la librería estándar `<fstream>`.



Instalación y ejecución

 1. Clonar el repositorio
git clone https://github.com/ariassalaz/task-tracker-cpp.git
cd task-tracker-cpp

 2. Compilación del programa
g++ taskTracker.cpp -o taskTracker

 3. Ejecución
./taskTracker
Ejemplos de uso

****TASK TRACKER APPLICATION****
1. ADD TASKS
2. UPDATE TASK
3. DELETE TASK
4. MARK TASK AS IN PROGRESS
5. MARK TASK AS DONE
6. MARK TASK AS NOT DONE
7. LIST ALL TASKS
8. LIST TASKS IN PROGRESS
9. LIST TASKS DONE
10. LIST TASKS NOT DONE
11. EXIT
CHOOSE AN OPTION: 1
Enter a task to add: Estudiar C++
Task added successfully

Tecnologías utilizadas
Lenguaje: C++
Entorno: VS Code
Librerías estándar:
<iostream>
<fstream>
<vector>
<string>


Autor
Ricardo Arias Salazar
(https://www.linkedin.com/in/ricardo-arias-570a0b360/)
Proyecto desarrollado como práctica de programación en C++.

Licencia
Este proyecto se distribuye bajo la licencia MIT, por lo que puede ser usado, modificado y redistribuido libremente citando al autor original.
