# CiudadELA_theremin


El _theremin_ es un instrumento musical muy curioso, pues no necesita de contacto directo, sino que detecta la posición de las manos 🖐, y según esta suena una frecuencia particular, a un volumen determinado.

Fue inventado por el físico ruso Léon Theremin, en 1920, pero @dumb_stuff_maker y @jose.l_delaoliva trabajaron en una versión propia, con muy pocos componentes, que hemos continuado desarrollando. Lo más importante es que esta versión es posible tocarla fácilmente, y con cualquier parte de nuestro cuerpo.

Con la info que te damos pudieses armarlo sin importar si te desempeñas en estos campos o no. Te contamos:

![Semantic description of image](/source/images/Componentes.jpg)*De izquierda a derecha: arduino (nano en este caso); _buzzer_ (zumbador); ultrasónico.*

----

## Funcionamiento

🧠 El primer componente es el arduino, es dónde se almacena nuestro código, y desde ahí se le dice a cada pieza qué debe hacer.

🦇 La próxima pieza es un ultrasónico, y lo usaremos como si fuese un murciélago. Uno de sus cilindros emite ondas ultrasónicas, y otro recibe el eco de ellas. De esta forma podemos conocer la distancia a la que se encuentra el objeto con el que choquen, según el tiempo que se demoran en ser captadas nuevamente. 

⚙️ Un código interno en el arduino define qué nota musical debe tocar, según la distancia detectada, así como varias funcionalidades internas.

🔌 En realidad, el arduino no sabe lo que es una nota, lo que puede hacer es pasar por los cables una corriente de determinada frecuencia. Esa frecuencia será la misma que la de la nota musical que se debería reproducir (las notas son ondas, lo que mecánicas, y estas tienen frecuencia).

🔊 El corrientazo se lo lleva un _buzzer_ , que tiene un piezoeléctrico incluido. ¿Qué es eso?. Sencillo,son materiales superinteresantes que, al recibir un campo eléctrico, sufren deformaciones (y viceversa). ¿Y esto para qué nos sirve? Pues que el corrientazo que le dimos lo va a hacer vibrar (con la frecuencia que le dimos).

🍃 Pasa ahora a la pieza final, el aire. El aire en contacto con el _buzzer_ vibrará también, y al propagarse por él esa vibración tenemos una onda, y eso precisamente es el sonido que percibimos. Según la fecuencia de la onda tendremos un anota distinta. 

Ahora solo nos falta usar una _protoboard_, que es donde conectamos todo.

![Semantic description of image](/source/images/Theremin.jpg)*Theremin armado*



## Funcionalidades musicales

El código también se encarga de que solo se usen notas sin mucha disonancia entre ellas (aquellas que pertenecen a la escala pentatónica de la menor), así que prepárate, porque cualquiera puede tocarlo. Algunas funcionalidades extras incluidas son: tocar con un cierto tempo; registrar las melodías que tocamos; cambiar dinámicamente a la escala mayor de do (para tener más diversidad de notas); una transición suave cuando dejamos de tocar, pues demorará unos milisegundos en desaparecer el sonido, a diferencia de cuando tocamos con fluidez; dejar de registrar las pausas luego de 1 segundo de pausas consecutivas, entre otras.

Si adaptamos un poco el código, podemos hacer que en lugar de sonar una nota según la distancia suene una melodía completa, y tenemos un reproductor. Esta versión y otra que sirve de instrumento y reproductor a la vez las tenemos desarrolladas en este repositorio también.

Todo esto nos permitió que nuestro _theremin_ fuese la vía por la que Irene, Lázaro, Joan y Tamara (quienes son pacientes de ELA) convirtiesen sus movimientos en melodías, y usándolo también se registraran estas, se tradujeran (con el programa) e incluso se reprodujeran en el estudio de grabación. Todo este proceso ha sido parte del proyecto CiudadELA Camp, al que se han unido un grupo de músicos cubanos para, usando estas melodías registradas, crear canciones que serám vendidas como NFT para apoyar a los pacientes con esta enfermedad.

----

## Tutoriales y códigos

Aunque nos pueden ser difíciles de conseguir, como ves solo son necesarios par de cables y piezas, y tenemos música, así que solo te falta saber cómo conectar qué con qué.

Acá tienes un tutorial para ello:
<https://telegra.ph/Theremin-08-18>

En este repositorio puedes encontrar los códigos de las distintas versiones del _theremin_, en Softwares. Estos códigos deben subirse al arduino para usarlo, y esa parte es fácil, lo puedes buscar o consultarnos.

Desarrollamos un programa, ejecutable en cualquier computadora con Windows, que permite traducir lo salido del theremin a cifrados musicales legibles (acuérdate que lo que sale del arduino son frecuencias, números), pero también pasar de un cifrado musical a otro, o incluso traducir  unas notas al lenguaje en que puede reproducirlas el _theremin_. El programa, para descargarlo, así como el código que lo generó, los podrás encontrar acá:

En la carpeta Necessary puedes encontrar paquetes necesarios para usar los programas.

----

## ¿Qué hemos logrado con esto? Más detalles sobre CiudadELA Camp

![Semantic description of image](/source/images/CiudadELA.jpg)

Es un proyecto musical y tecnológico con el fin de visibilizar y sensibilizar la esclerosis lateral amiotrófica (ELA), una enfermedad del sistema nervioso que debilita los músculos y afecta las funciones físicas. Se presenta a través de una experiencia innovadora en la cual artistas, psicólogos, físicos, emprendedores, especialistas de la salud y estudiantes se juntan para construir una gran trinchera de apoyo a la causa de la ELA. 

Esta iniciativa surge en colaboración con Habana Espacios Creativos, como parte de la residencia de Nuevos Medios, que fue otorgada a Nativos B 6 12. 

Se presentan tres etapas que recogen la esencia del proyecto:

- La primera representa el alma de CiudadELA, por la cual fue inspirada: los pacientes con ELA. Nos acompañaron dos hombres y dos mujeres excepcionales, los cuales nos regalaron sus movimientos corporales para la producción de bases melódicas a través del _theremin_. 

- La segunda etapa fusiona las melodías realizadas por los pacientes para crear la letra y género. Participaron varios artistas cubanos que brindaron su creatividad para crear el primer sencillo del disco. 

- El 8 de septiembre del año 2023 se materializó la tercera etapa, a través de un performance que mostró el recorrido realizado. Estuvieron presentes talleres sobre tecnología, artes, fotografía terapéutica, campos han aportado a la visibilización de la ELA desde su perspectiva y posibilidades. COntamos además con la presencia de los pacientes que han sido parte del proyecto. 

CiudadELA no termina aquí, seguimos trabajando como trinchera contra esta enfermedad, y apoyo a quienes la padecen.



