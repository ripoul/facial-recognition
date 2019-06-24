<h1 align="center">Welcome to facial-recognition 👋</h1>
<p>
  <img src="https://img.shields.io/badge/version-1.1.0-blue.svg?cacheSeconds=2592000" />
  <a href="https://github.com/ripoul/facial-recognition">
    <img alt="Documentation" src="https://img.shields.io/badge/documentation-yes-brightgreen.svg" target="_blank" />
  </a>
  <a href="http://www.wtfpl.net/">
    <img alt="License: wtfpl" src="https://img.shields.io/badge/License-wtfpl-yellow.svg" target="_blank" />
  </a>
</p>

> reconnaitre la tête des gens

### 🏠 [Homepage](https://github.com/ripoul/facial-recognition)

## Author

👤 **Jules**

* Github: [@ripoul](https://github.com/ripoul)

## How To use it

### sample 1

Lunch the webcam and take a picture when pressing 'q'.

Let's try (in `./sample1`):

```
make
./main
```

### sample 2

Lunch the webcam and auto-detect if a human is here.

Let's try (in `./sample2`):

```
make
./main
```

### training

Lunch the webcam and take a photo when q is pressed (10 times).

Let's try (in `./training`):

```
make
./main
```

### recognition

Needed before try the example : 
* several set of picture of the same resolution (10 images by set). Each set have to be on the same person. Only the head has to appear.
* you need to create a csv file with this format : 
```
path/To/Img;numberOfTheSet
path/To/Img2;numberOfTheSet
path/To/Img3;numberOfTheSet
path/To/Img4;numberOfTheSet
```
* have a look to the `makefile` and let's play !

The main take 3 args : 
1. the path to the file to id the face (example : `/usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml`)
2. the path to the csv file
3. the id of the camera

Let's try (in `./recognition`):
```
make
```

### some usefull cmd

* `convert p6.png -resize 92x112! p6.png` or 
* Or if all pictures are in the same folder, cd to this folder and execute : `for i in $(ls); do convert $i -resize 92x112! $i; done`

## 🤝 Contributing

Contributions, issues and feature requests are welcome!<br />Feel free to check [issues page](https://github.com/ripoul/facial-recognition/issues).

## Show your support

Give a ⭐️ if this project helped you!

## 📝 License

Copyright © 2019 [Jules](https://github.com/ripoul).<br />
This project is [wtfpl](http://www.wtfpl.net/) licensed.

