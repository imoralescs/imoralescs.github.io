# AWS static-website

Primero para tener nuestro portal estatico debemos crear nuestro "Bucket", este debe de tener el mismo nombre de nuestro por tal, ejemplo si nuestro dominio del portal es www.mi-sitio.com, pues nuestro "bucket" debe de llamarse www.mi-sitio.com. Es importante entender que este nombre debe ser unico dentro de nuestra cuenta AWS y este nombre una vez creado no podra ser cambiado.

Para Crear nuestro bucket:

1- Navegamos a S3 en nuestra consola AWS.
2- Haz click en el boton "Create Bucket"
3- Entra el nombre el cual llamaras al bucket
4- Selecciona regio de AWS
5- Para finalizar haz click en el boton "Create bucket" para crear nuestro bucket.

Configuración de su bucket de S3 para estática Alojamiento de páginas web

1- Navegamos en el area de S3 de la consola AWS
2- Le damos click nuestro bucket ya creado
3- luego le damos click a la seccion de propiedades el cual veremos arriba
4- luego le damos click a editar en la seccion Static website hosting
5- Seleccionamos habilitar
6- Entramos "index.html" en la seccion "Index document"
7- Le damos click a guardar

Por defecto los bucket se generan con restrinccion a accesso publico esto se debe a que AWS evita que contenido importante sea public, para nuestra pagina debemos editar estos permisos.

1- Le damos click a nuestro bucket ya creado
2- Le damos click en la pestaña "Permission" en la parte superior.
3- Luego le damos click a "Edit" en la seccion "Block public access (bucket settings)"
4- desmarcar la casilla de verificación con el titulo de "Block all public access"
5- Click en "Save changes"
6- Luego devuelta a la seccion de permisos, le damos click en editar a la seccion de "Bucket Policy" y dentro colocamos lo siguiente.

```
{
"Version" : "2008-10-17",
"Statement": [
{
"Sid": "PublicReadGetObject",
"Effect" : "Allow" ,
"Principal" : {
"AWS" : "*"
},
"Action" :  "s3:GetObject" ,
"Resource" :  "arn:aws:s3:::www.my-awesome-site.com/*"
}
]
}
```
7- Luego le damos a "Save changes"
