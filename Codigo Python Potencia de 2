def potencias_de_dos(numero):
    potencia = 1
    resultado = []
    
    while potencia < numero:
        resultado.append(potencia)
        potencia *= 2
    
    return resultado
while True:
  print("Bienveido al programa de potencias de dos")
  # Pedir al usuario que ingrese un número
  numero_ingresado = int(input("Ingrese un número: "))

  # Obtener las potencias de base 2 menores que el número ingresado
  potencias = potencias_de_dos(numero_ingresado)
  if numero_ingresado < 2:
    # Si el numero ingresado es menor a dos, no imprime potencias
    print("No hay potencias de 2 para un numero menor a 2")
  else:
    # Mostrar las potencias obtenidas
    print("Las potencias de 2 menores que", numero_ingresado, "son:")
  for potencia in potencias:
    print(potencia)

  respuesta = input("¿Quiere ingresar otro valor? Si/No: ").lower()
  if respuesta != "si":
    print("Gracias por usar el programa :)")
    break
