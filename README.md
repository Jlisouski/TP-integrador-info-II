# TP-integrador-info-II
Trabajo práctico integrador de Juan Lisouski del curso 2°11, para la materia Informática II.

## Sistema antirrobo para auto
El trabajo práctico consistirá de un sistema que podrá bloquear el flujo de corriente a la bobina de encendido del auto, mediante un relé (normalmente cerrado). Este mecanismo contara con un botón escondido, que si no es presionado tras cierto tiempo de ser encendido el auto o de ser abierta la puerta del conductor, cortará la corriente, impidiendo el arranque del motor.

<img width="800" height="600" alt="Diagrama maquina de estado" src="https://github.com/user-attachments/assets/86aced80-b105-471b-a3f9-75ed884a5d8f" />


 **Explicación de variables y constante:**

<ins> mem:</ins> Variable que se almacena en memoria eeprom de microcontrolador (su valor persiste aunque se apague y encienda el mismo). Se encargará de almacenar en que estado se encontraba el sistema tras apagar el auto. Si mem=0, significa que el relé estaba cerrado; si mem=1, el relé estaba abierto, y por ende no podría arrancar el motor.  

<ins> boton:</ins> Variable que representa el pin de entrada conectado a un boton. Si boton=0, este no está presionado; si boton=1, este está siendo presionado.

<ins> puerta:</ins> Variable que lee el estado de la puerta del conductor. Si puerta=0, esta se encuentra abierta; si puerta=1, está cerrada.

<ins> relay:</ins> Variable que representa el puerto de salida conectado a la base del transistor que controlará el estado del relay. Si relay=0, éste no ha sido activado y se encontrará cerrado, dado que es normalmente cerrado; si relay=1, el relé se abrirá, y por ende el motor se apagará y no podra ser encendido.

<ins> tiempo:</ins> Variable que funcionará como contador de tiempo.

<ins> t_set:</ins> Valor constante que se comparará con la variable "tiempo", y determinará cuanto tiempo transcurrirá hasta que se corte la corriente de la bobina, dadas las condiciones necesarias.


 **Explicación de estados:**

 <ins> Inicio:</ins> Estado inicial del sistema, en el cual se evaluará el valor de la variable "mem".

 <ins> Estado 1:</ins> En este estado, el valor de las variables relay=1, y mem=1. Si boton=0, significa que el boton no ha sido presionado, y el sistema se mantendrá en este estado, impidiendo encender el motor. Si boton=1, significa que ha sido presionado el boton, y se procederá al estado 2.

 <ins> Estado 2:</ins> En este estado, el valor de las variables relay=0, mem=0 y tiempo=0. Esto significa que se podrá encender el auto. Si puerta=1, la puerta esta cerrada, y el sistema se mantendría en este estado; si puerta=0, la puerta se encuentra abierta y se prosigue al estado 3.

 <ins> Estado 3:</ins> En este estado, el valor de mem=1. La variable "tiempo" comenzaría a contar, y su valor se comparará constantemente con "t_set". Si tiempo<t_set, sigue en el mismo estado; si tiempo>t_set, prosigue al estado 1.
