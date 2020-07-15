# Trabajo Práctico Especial
# Programación Imperativa
# Julio 2020

# Fecha de final: 17/07/2020

# Integrantes:

# Anselmo, Sol Victoria – 61278
# Negro, Juan Manuel – 61225
# Sambartolomeo, Mauro Daniel – 61279

# Instrucciones de uso de Makefile:

Utilizando los parámetros BUE y VAN se puede compilar y linkeditar los archivos fuente y generar los ejecutables, respectivamente a su nombre. Por ejemplo, make BUE.
Si se desea realizar la acción anterior para BUE y VAN a la vez, se debe utilizar el parámetro all. Por ejemplo, make all.

Utilizando los parámetros objectsBUE y objectsVAN se puede compilar los archivos fuente y generar los archivos objeto, respectivamente a su nombre. 
No se linkeditarán los archivos objeto ni se generarán los ejecutables. 

Los parámetros clear eliminan los archivos. Se pueden utilizar de las siguientes formas:
   clearBUE y clearVAN eliminarán los ejecutables, respectivamente a su nombre.
   clear_queries eliminará las tres queries resultantes de los ejecutables.
   clear_objects eliminará todos los archivos objeto. 
   clearBUE_all y clearVAN_all eliminarán las tres queries, los archivos objeto y el ejecutable correspondiente a su nombre. 
   clear eliminará ambos ejecutables a la vez.
   clear_all eliminará las tres queries, los archivos objeto y ambos ejecutables a la vez. 

Utilizando los parámetros debugBUE y debugVAN se puede compilar los archivos fuente utilizando parámetros de debug (-Wall -fsanitize=address -g), linkeditar los archivos objeto y generar los ejecutables, respectivamente a su nombre. Utilizando el parámetro debug se pueden realizar ambas acciones a la vez.

# Instrucciones de uso:

Los ejecutables se llamarán arbolesADT seguido por el nombre de la ciudad. En este caso, arbolesADTBUE y arbolesADTVAN. 

Al ejecutar, se deben agregar como argumentos los archivos .csv de donde se extraerá la información. El primer argumento debe ser el archivo de donde se extrae la información de los árboles; y el segundo debe ser de donde se extrae la información de los barrios. Por ejemplo, ./arbolesADTBUE ../arbolesBUE.csv ../barriosBUE.csv.