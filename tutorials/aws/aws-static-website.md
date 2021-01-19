# Amazon AWS a traves de ejemplo: S3

## Ejemplo: Creacion sitio web estatico

Para tener nuestro sitio web estatico debemos crear nuestro "Bucket", este debe de tener el mismo nombre de nuestro por tal, ejemplo si nuestro dominio del portal es www.mi-sitio.com, pues nuestro "bucket" debe de llamarse www.mi-sitio.com. Es importante entender que este nombre debe ser unico dentro de nuestra cuenta AWS y este nombre una vez creado no podra ser cambiado.

### Paso 1: Crear nuestro bucket

1- Vaya la consola S3
2- Haga clic en "Create Bucket"
3- Entre el nombre el cual desee tener a su bucket
5- Podemos revisar toda las demas propiedades y actualizar o anadir cualquiera que entendamos que aplique a nuestro proyecto.
6- Finalizamos haciendo clic en el boton "Create bucket" para finalizar y crear nuestro bucket.

### Paso 2: Configuración de su bucket para sitio web estatico

1- Vaya la consola S3
2- Haga clic a nuestro bucket ya creado
3- Para editar configuraciones de nuestro bucket haga clic en la pestana "Properties" en la parte superior
4- Ahora, en la seccion de "Static website hosting" hacemos clic en editar
5- Una vez dentro del area de editar seleccionamos habilitar
6- Colocamos lo siguiente en "Index document": index.html
7- Para terminar con esta area clic en guardar.

### Paso 3: Permiso para acesso publico a nuestro sitio web estatico

Por defecto los bucket al crearse, esto contienen restrincciones a accesso publico esto se debe a que Amazon AWS trata de evita que contenido con valor importante sean publicos a las redes, para que usuarios tengan accesso a ver nuestro sitio web estatico debemos editar permisos relacionados al bucket en el cual esta alojado nuestro sitio web estatico.

1- Vaya la consola S3
2- Haga clic a nuestro bucket ya creado
2- Para editar permisos de nuestro bucket haga clici en la pestaña "Permission" en la parte superior
3- Ahora vamos a la seccion "Block public access (bucket settings)" y haga clic en editar
4- Desmarcar la casilla de verificación con el titulo de "Block all public access"
5- Haga clic en "Save changes"
6- Regresamos a la seccion de permisos, hacemos clic a editar en la seccion de "Bucket Policy" y dentro de esta seccion colocamos el siguiente valor JSON:
```
{
  "Version" : "2008-10-17",
  "Statement": [{
    "Sid": "PublicReadGetObject",
    "Effect" : "Allow" ,
    "Principal" : {
    "AWS" : "*"
  },
  "Action" :  "s3:GetObject" ,
  "Resource" :  "arn:aws:s3:::www.my-awesome-site.com/*"
 }]
}
```
7- Para terminar con esta area clic en guardar.
