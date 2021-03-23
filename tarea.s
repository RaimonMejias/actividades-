.data

msgtitulo:     .asciiz "Programa para repasar las tablas de multiplicar"
msgrepeticion: .asciiz "\n¿Qué tabla desea repasar? Introduzca un número: (Escriba un cero para salir del programa)" 
msgresultado:  .asciiz "El porcentaje de aciertos es: " 
msgfin:        .asciiz "\nFIN DEL PROGRAMA"
msgpor:        .asciiz " x "
msgpregunta:   .asciiz " ? "
msgporcentaje  .asciiz "% " 

.text 

################################################################
# REGISTROS USADOS EN EL PROGRAMA 
# int n; //          $t0
# int i; //          $t1
# int resultado; //  $t2
# int aciertos; //   $t3
# int porcentaje; // $t4
#                    $t5 guarda el resultado de la multiplicación
################################################################

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
    beqz $t0,Fin_Do # if(n == 0) break;
    
    li $t3,0
    li $t1,0
    While: 
      bgt $t1,10,Fin_While
      move $a0,$t1
      li $v0,1
      syscall
      li $v0,4
      la $a0,msgpor
      syscall
      move $a0,$t0
      li $v0,1
      syscall
      li $v0,4
      la $a0,msgpregunta
      syscall
      li $v0,5
      syscall
      move $t2,$v0
      mul $t5,$t0,$t1
      bne $t2,$t5 incorrecto:
      addi $t3,1
      incorrecto:
      addi $t1,1
      j While
      
    Fin_While:
    multi $t3,10
    li $v0,4
    la $a0,msgresultado
    syscall
    move $a0,$t3
    li $v0,1
    syscall
    li $v0,4
    la $a0,msgporcentaje
    syscall
    j Do
  
  Fin_Do:
  li $v0,4
  la $a0,msgfin
  syscall
  li $v0, 10
  syscall
