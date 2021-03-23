.data

msgtitulo:     .asciiz "Programa para repasar las tablas de multiplicar"
msgrepeticion: .asciiz "\n¿Qué tabla desea repasar? Introduzca un número: (Escriba un cero para salir del programa)

.text 

##############################################################
# REGISTROS USADOS EN EL PROGRAMA 
# int n; //          $t0
# int i; //          $t1
# int resultado; //  $t2
# int aciertos; //   $t3
# int porcentaje; // $t4
##############################################################

main:
  li $v0,4
  la $a0,msgtitulo
  syscall

  
  Do:
    la $a0,msgrepeticion
    syscall
    li $v0,5
    syscall
    move $t0,$v0
    beqz $t0,Fin_While
    j Do
  
  Fin_while:
  li $v0, 10
  syscall
