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
## Explicacion y conexion correcta de componentes

| **Componente**                 | **Pin del Componente**          | **Pin del Arduino UNO**     | **Descripción de la Conexión**                           |
| ------------------------------ | ------------------------------- | --------------------------- | -------------------------------------------------------- |
| **Driver L298N**               | IN1                             | D8                          | Control dirección Motor A                                |
|                                | IN2                             | D9                          | Control dirección Motor A                                |
|                                | IN3                             | D10                         | Control dirección Motor B                                |
|                                | IN4                             | D11                         | Control dirección Motor B                                |
|                                | ENA                             | D5 (PWM)                    | Habilita y controla velocidad Motor A                    |
|                                | ENB                             | D6 (PWM)                    | Habilita y controla velocidad Motor B                    |
| **Motores DC (x2)**            | Terminales de Motor A y Motor B | Salidas del L298N           | Conectados directamente al puente H                      |                                                                                                                       
| **Sensor ultrasónico HC‑SR04** | Trig                            | D12                         | Pin de disparo (distancia)                               |
|                                | Echo                            | D13                         | Pin de recepción (distancia)                             |    
|| **Sensor IMU MPU‑6050**       | SDA                             | A4                          | Comunicación I²C                                         |
|                                | SCL                             | A5                          | Comunicación I²C                                         |
| **Módulo de alimentación**     | VIN o entrada batería           | Batería externa             | 9 V para todo el sistema                                 |
|                                | 5V                              | 5V rail protoboard          | Alimentación de sensores                                 |

---

## Parte 2:   
  1. ¿Cómo se calcula la velocidad del robot sin encoders usando PWM?
     - Para estimar la velocidad de un motor DC sin utilizar encoders, se recurre a la relación entre el ciclo de trabajo del PWM y la velocidad angular del eje del motor. ω = kD * D. Siendo D el ciclo de trabajo del PWM.

  2. ¿Cómo factores afectan la trayectoria y velocidad del robot al cambiar los intervalos de tiempo?
     - Un motor DC no cambia instantáneamente de velocidad, tarda un tiempo de respuesta en estabilizarse. Si los “intervalos” son demasiado cortos, nunca alcanzará la velocidad objetivo, generando errores.
     - Al girar, subir una pendiente o rozar una superficie distinta, la carga sobre el motor cambia. A igual PWM, la velocidad varía según la fricción o la pendiente.
  3. ¿Cuáles son las ventajas y desventajas de usar un IMU para ajustar la dirección en lugar de encoders

      | Aspecto         | IMU (acelerómetro + giroscopio)                                                                                                                                                                                                                     |
      | --------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | 
      | **Ventajas**    | • Mide rotaciones y aceleraciones en 3 ejes (yaw, pitch, roll).<br>• Detecta inclinación y vuelcos, útil en terrenos irregulares.<br>• No requiere acoplamiento mecánico al eje de la rueda.                                                        | 
      | **Desventajas** | • **Deriva**: el giroscopio sufre drift acumulativo si no se corrige con acelerómetro o magnetómetro.<br>• **Ruido**: los sensores  son sensibles a vibraciones.<br>• Requiere filtros (complementario o Kalman) para obtener ángulos estables. | 

  4. ¿Qué efecto tiene la inclinación o el giro en el movimiento del robot, y cómo se corrige con el IMU?
     - Si el robot sube o baja una pendiente, la componente de la gravedad cambia. Esto puede alterar la carga en los motores y provocar que avance más lento o se detenga. Midiendo el pitch, el sistema puede aumentar o disminuir el PWM para mantener la velocidad en el plano horizontal efectivo.
     - Desniveles, superficies irregulares o diferencias de fricción hacen que el robot gire ligeramente al avanzar en línea recta. Midiendo el yaw con el giroscopio puedes calcular un erro y aplicar un corrector en la velocidad diferencial.
