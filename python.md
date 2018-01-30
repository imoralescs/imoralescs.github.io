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

## Test Django Bata Table

Django database migration process ensure all Django project logic associated with the database is reflected in the database itself.

1- `ssh` to you server and on myproject directory and run the follower command:

```
$ python manage.py migrate
```

## Set Up Content: Urls, Templates and Apps

Django works with three major bulding blocks: urls, temaplates and apps. Urls define the entry point or where to access content. Templates define de endpoint that give form to the final content. Apps serve as the middleware between urls and templates, altering or adding content from a database or user interations.

### Create and Configure Django Urls

The main entry point for Django urls is the `urls.py`, file is created when you start a project. Django urls use regular expression to match incoming request. The regular expression pattern to match a home page is `^$`.

To add url with a template add the following missing code:

Beginning:
```
from django.conf.urls import url
from django.contrib import admin

urlpatterns = [
    url(r'^admin/', admin.site.urls),
]
```

After:
```
from django.conf.urls import url
from django.contrib import admin
from django.views.generic import TemplateView 

urlpatterns = [
    url(r'^admin/', admin.site.urls),
    url(r'^$', TemplateView.as_view(template='homepage.html')),
]
```

### Create and Configure Django Template

By default Django template are interpreted as HTML. Django expect to have a standard HTML document structure and tags <html> <body>.
    
### Create and Configurate Django Apps

Go to the `PROJECT_DIR` where the `urls.py` and `settings.py` files are and type to execute the following command to create ours app:

```
django-admin startapp about
```

A subdirectory includes the following:

__init__.py
