## Install Pyhton

## Install pip Package Manager

### Install

```
sudo apt-get install python-pip
```

### Update

```
pip install --upgrade pip
```

### Verify Version PIP

```
pip -V
```

## Install Django

```
pip install django
```

## Start Django Project

```
# Create a project called myproject
django-admin startproject myproject
```

## Django project structure

```
+<BASE_DIR_project_name>
|
+---- manage.py
|
+---+-<PROJECT_DIR_project_name>
    |
    +-__init__.py
    +-settings.py
    +-urls.py
    +-wsgi.py
```

## Set up a Database for Django Project

Django configuration to connect to a databases is done inside `setting.py` 

```
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.postgresql_psycopg2',
        'NAME': 'postgres',
        'USER': 'postgres',
        'PASSWORD': 'postgres',
        'HOST': 'db',
        'PORT': '',
    }
}
```
