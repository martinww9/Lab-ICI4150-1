# Lab2-ICI4150-1

---

## Parte 1: 

• ¿Qué es la percepción en robótica y por qué es fundamental en los sistemas autónomos?

  La percepción en robótica es la capacidad de un robot para recolectar, interpretar y procesar datos sensoriales del entorno, permitiéndole tomar decisiones informadas. Esta se basa en el uso de sensores como cámaras, ultrasonidos, IMU, LIDAR, entre otros.
Es fundamental en sistemas autónomos porque les permite reconocer su entorno (por ejemplo, detectar obstáculos, reconocer colores o detectar movimiento), facilita la planificación de rutas y la navegación segura. Ademas les otorga autonomía para adaptarse a cambios en el ambiente sin intervención humana.

• En el sensor ultrasónico HC-SR04 ¿qué parámetro se mide para calcular la distancia?
  El sensor ultrasónico HC-SR04 mide el tiempo de vuelo (o time of flight) de una señal ultrasónica. Específicamente, se mide el tiempo que tarda el pulso ultrasónico en salir del transmisor, reflejarse en un objeto y regresar al receptor. La fórmula utilizada para calcular la distancia es tiempo por velocidad del sonido dividido en 2.

• ¿Cómo influye el ruido en las mediciones del sensor ultrasónico y cómo podría reducirse?
  El ruido en las mediciones del HC-SR04 se puede manifestar como fluctuaciones erráticas en la distancia medida, incluso cuando el objeto permanece estático. Este     ruido puede deberse a reflexión imperfecta del sonido en superficies irregulares o suaves, condiciones ambientales como temperatura o humedad, interferencias acústicas o vibraciones externas y errores electrónicos o de programación.
  Se puede reducir a traves del filtrado de señal, por ejemplo, aplicar un filtro de mediana para eliminar valores atípicos. La umbralización o aislando los sensores.

• ¿ Que es PWM y como ayuda a controlar la velocidad de los motores?
  Es una tecnica de modulacion de la anchura del pulso para controlar la potencia media entregada a un motor. Variando el porcentaje de tiempo en alto podemos aumentar o disminuir la velocidad de manera proporcional.
  
• ¿ Como afecta el control de velocidad a la precision de la navegacion
sin encoders?
  Podriamos obtener una respuesta lenta o inexacta ya que sin retroalimentacion el control por PWM asume una relacion lineal entre la velocidad y el porcentaje de tiempo en alto. Al igual que un mayor error en la velocidad deseada.
  
---
## Análisis general de variaciones en las lecturas

Durante las pruebas realizadas con el sensor ultrasónico HC-SR04, se pudo observar que su desempeño varía dependiendo de las condiciones del entorno. En condiciones normales de luz y con superficies duras y planas, el sensor ofrece lecturas bastante precisas. Sin embargo, cuando se usa en presencia de luz intensa directa, o frente a superficies blandas o inclinadas, el sensor comienza a mostrar errores. Por ejemplo, cuando el objeto está inclinado, el rebote de la señal ultrasónica se desvía, lo que genera sobreestimaciones en la distancia. Para mejorar la fiabilidad de estos datos, se sugiere aplicar técnicas de filtrado, como una media móvil, y definir umbrales que permitan ignorar lecturas erráticas.

El sensor de color RGB, su comportamiento también se ve influenciado por la iluminación del entorno. Cuando se trabaja en condiciones de luz natural uniforme, el sensor identifica los colores de forma correcta. Sin embargo, si hay sombras intensas o luz muy brillante, los valores RGB pueden verse distorsionados, generando errores en la identificación del color. Además, colores muy claros o muy oscuros pueden ser difíciles de clasificar sin una buena calibración. Para mejorar la detección, es útil normalizar los valores RGB y establecer rangos o umbrales específicos para cada color esperado.


---

## Parte 2:   
  1. Si el robot detecta el color rojo en el suelo, ¿qué acción debería tomar? ¿Por qué?
     - El color rojo podría representar una zona de peligro o una señal de “alto”. Por lo tanto, el robot debería detenerse inmediatamente al detectar rojo. Esta decisión está basada en una estrategia de navegación por reglas, donde los colores del suelo actúan como señales. 

  2. Si el sensor ultrasónico detecta valores erráticos, ¿qué estrategias podrías aplicar para mejorar la precisión?
      Existen varias estrategias útiles como el filtrado por media móvil, es decir,  promediar varias lecturas sucesivas para suavizar los cambios bruscos.
      descarte de valores extremos, ignorar mediciones muy alejadas del promedio. O la repetición y validación para confirmar un valor solo si se repite varias veces de       forma coherente. Y finalmente el uso de umbrales de confiabilidad definiendo un rango aceptable para considerar una lectura válida.
     
  3. Si tuvieras que integrar un nuevo sensor para mejorar la navegación del robot, ¿cuál elegirías y por qué?
    Incorporaría un sensor infrarrojo (IR) o una cámara con visión computacional básica. El sensor IR puede detectar cambios de color y obstáculos cercanos con rapidez y bajo costo. Por otro lado, una cámara permitiría realizar una navegación más avanzada, reconociendo formas, señales o patrones en el entorno, lo que haría al robot   más inteligente y adaptable en entornos complejos.

  5. ¿Cuál es el tiempo de respuesta del robot al detectar un cambio de color?
     Es el tiempo de respuesta depende del procesamiento del microcontrolador y de la frecuencia de lectura del sensor. En condiciones óptimas, el robot puede responder en menos de 200 milisegundos (0.2 segundos) al detectar un cambio de color. Este tiempo puede aumentar si hay mucho ruido, si se aplican filtros muy lentos, o si el código tiene muchos retrasos (delay()).
