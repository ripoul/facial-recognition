# facial-recognition
## sample 1

Lunch the webcam and take a picture when pressing 'q'.

Let's try (in `./sample1`):

```
make
./main
```

## sample 2

Lunch the webcam and auto-detect if a human is here.

Let's try (in `./sample2`):

```
make
./main
```

## training

Lunch the webcam and take a photo when q is pressed (10 times).

Let's try (in `./training`):

```
make
./main
```

## recognition

Needed before try the example : 
* several set of picture (9 images by set). Each set have to be on the same person. Only the head has to appear.
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